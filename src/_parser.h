#include "./_tokens.h"

#ifndef PARSER_H
#define PARSER_H

typedef struct
{
  Token** tokens;
  unsigned long tokens_count;
  unsigned long token_current;
} Parser;

Parser* cr_Parser(Token** tokens, unsigned long count);
void show_parser(const Parser* parser);
int is_all_null(const Parser* parser);

#endif
