#include "./_intepretation.h"
#include <string.h>

ASTnode* parse(Parser* parser)
{
  ASTnode** res = malloc(parser->tokens_count * sizeof(ASTnode*));
  unsigned long last = 0;
  int is_in_par = 0;

  for (unsigned long i = 0; i < parser->tokens_count; ++i)
  {
    if (parser->tokens[i]->t == TOKEN_NUMBER)
    {
      res[i] = cr_num_AST(atof(parser->tokens[i]->value));
      parser->tokens[i]->t = TOKEN_NUL;
    }

    else if (parser->tokens[i]->t == TOKEN_STRING)
    {
      res[i] = cr_str_AST(parser->tokens[i]->value);
      // printf("| %d\n", i);
      parser->tokens[i]->t = TOKEN_NUL;
    }

    last = i;
  }

  while (is_all_null(parser))
  {
    unsigned long po = TOKEN_NUL;
    unsigned long po_i = 0;
    for (unsigned long i = 0; i < parser->tokens_count; ++i)
    {
      if (parser->tokens[i]->t == TOKEN_NUL)
        continue;

      if (po < (int)(parser->tokens[i]->t) + is_in_par * (int)(TOKEN_LPARENT) &&
          parser->tokens[i]->t < TOKEN_LPARENT)
      {
        po = parser->tokens[i]->t + is_in_par * (int)(TOKEN_LPARENT);
        po_i = i;
      }
      else if (parser->tokens[i]->t == TOKEN_LPARENT)
      {
        is_in_par++;
      }
      else if (parser->tokens[i]->t == TOKEN_RPARENT)
      {
        is_in_par--;
      }
    }

    if (parser->tokens[po_i]->t > TOKEN_NUL)
    {
      res[po_i] = cr_binary_AST(parser->tokens[po_i]->value[0], res[po_i - 1],
                                res[po_i + 1]);
      parser->tokens[po_i]->t = TOKEN_NUL;

      unsigned long i = po_i;
      while (parser->tokens[i]->t == TOKEN_NUL ||
             parser->tokens[i]->t == TOKEN_LPARENT ||
             parser->tokens[i]->t == TOKEN_RPARENT)
      {
        if (i != po_i)
          res[i] = res[po_i];
        // if (parser->tokens[i]->t == TOKEN_LPARENT ||
        //     parser->tokens[i]->t == TOKEN_RPARENT)
        //   parser->tokens[i]->t = TOKEN_NUL;

        --i;
        if (i == 0)
          break;
      }

      i = po_i;
      while (parser->tokens[i]->t == TOKEN_NUL ||
             parser->tokens[i]->t == TOKEN_LPARENT ||
             parser->tokens[i]->t == TOKEN_RPARENT)
      {
        if (i != po_i)
          res[i] = res[po_i];

        // if (parser->tokens[i]->t == TOKEN_LPARENT ||
        //     parser->tokens[i]->t == TOKEN_RPARENT)
        //   parser->tokens[i]->t = TOKEN_NUL;

        ++i;
        if (i == parser->tokens_count)
          break;
      }
    }
    last = po_i;
  }
  return res[last];
}
