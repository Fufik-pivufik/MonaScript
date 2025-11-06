#include "./_tokens.h"
#include <stdlib.h>

Token* cr_Token(TOKEN_TYPE type, char* val)
{
  Token* res = malloc(sizeof(Token));
  res->t = type;
  res->value = val;

  return res;
}

Token** tokenize(const char* expr, unsigned long* count)
{
  Token** tokens = malloc(BUFF_SIZE * sizeof(Token*));
  *count = 0;
  unsigned long i = 0;

  while (expr[i] != '\0')
  {
    if (expr[i] == ' ')
    {
      ++i;
      continue;
    }

    if (isdigit(expr[i]))
    {
      unsigned long start = i;
      while (isdigit(expr[i]))
        ++i;
      unsigned long lenght = i - start;
      char* val = malloc(lenght + 1);

      strncpy(val, &expr[start], lenght);
      val[lenght] = '\0';
      Token* token = cr_Token(TOKEN_NUMBER, val);
      tokens[(*count)++] = token;
      continue;
    }

    switch (expr[i])
    {
    case '+':

      tokens[(*count)++] = cr_Token(TOKEN_PLUS, "+");
      break;

    case '-':

      tokens[(*count)++] = cr_Token(TOKEN_MINUS, "-");
      break;

    case '*':

      tokens[(*count)++] = cr_Token(TOKEN_MULT, "*");
      break;

    case '/':

      tokens[(*count)++] = cr_Token(TOKEN_DIV, "/");
      break;

    case '(':
      tokens[(*count)++] = cr_Token(TOKEN_LPARENT, "(");
      break;

    case ')':
      tokens[(*count)++] = cr_Token(TOKEN_RPARENT, ")");
      break;
    }

    ++i;
  }

  return tokens;
}
