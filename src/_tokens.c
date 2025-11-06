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

  while (i < strlen(expr))
  {
    // printf("| %d, %c, len = %d\n", i, expr[i], strlen(expr));
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

    if (expr[i] == '"')
    {
      i++;
      unsigned long start = i;
      while (expr[i] != '"' && i < strlen(expr))
        i++;
      if (i == strlen(expr))
      {
        exit(1);
      }

      unsigned long len = i - start;

      char* string = malloc(len + 1);
      strncpy(string, &expr[start], len);
      string[len] = '\0';
      Token* str = cr_Token(TOKEN_STRING, string);
      tokens[(*count)++] = str;
      // printf("| %s\n", string);
      i++;
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
