#include "_main_definitions.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TOKENS_H
#define TOKENS_H

typedef enum
{
  TOKEN_NUL,
  TOKEN_NUMBER,
  TOKEN_STRING,
  TOKEN_CONST,

  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_MULT,
  TOKEN_DIV,

  TOKEN_LPARENT,
  TOKEN_RPARENT,
  TOKEN_IMPORT,
} TOKEN_TYPE;

typedef struct
{
  TOKEN_TYPE t;
  char* value;
} Token;

Token* cr_Token(TOKEN_TYPE type, char* val);
Token** tokenize(const char* expr, unsigned long* count);

#endif
