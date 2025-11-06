#include "./_parser.h"

Parser* cr_Parser(Token** tokens, unsigned long count)
{
  Parser* res = malloc(sizeof(Parser));

  res->tokens = tokens;
  res->tokens_count = count;
  res->token_current = 0;
  return res;
}

void show_parser(const Parser* parser)
{
  printf("All tokens: \n");
  for (unsigned long i = 0; i < parser->tokens_count; ++i)
  {
    printf("%d, %s\n", parser->tokens[i]->t, parser->tokens[i]->value);
  }
}

int is_all_null(const Parser* parser)
{
  for (unsigned long i = 0; i < parser->tokens_count; ++i)
    if (parser->tokens[i]->t != TOKEN_NUL &&
        parser->tokens[i]->t < TOKEN_LPARENT)
      return 1;
  return 0;
}
