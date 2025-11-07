#include "./_ASTnode.h"
#include "./_intepretation.h"
#include "./_main_definitions.h"
#include "./_parser.h"
#include "./_tokens.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  const char* MnS_version = "v0.0001 alpha Egor";
  char expr[BUFF_SIZE];
  unsigned long tokens_count;

  if (argc > 1)
  {
    if (strcmp(argv[1], "--version") == 0)
    {
      printf("MnS version: %s\n", MnS_version);
      return 0;
    }

    exec(argv[1]);
    return 0;
  }

  system("clear");
  printf("\tWelcome to MonaScript %s\n", MnS_version);
  while (1)
  {
    printf("> ");
    void* handl = fgets(expr, BUFF_SIZE - 1, stdin);
    if (strcmp(expr, "exit\n") == 0 || handl == NULL)
    {
      if (handl == NULL)
        printf("\n");
      printf("> exit shell...\n");
      break;
    }
    expr[strlen(expr) - 1] = '\0';
    if (strcmp(expr, "") == 0)
      continue;

    Token** tokens = tokenize(expr, &tokens_count);
    Parser* parser = cr_Parser(tokens, tokens_count);
    // show_parser(parser);

    ASTnode* node = parse(parser);
    Type result = inter_AST(node);

    switch (result.t)
    {
    case TYPE_NUMBER:
      printf("> %.2f\n", result.value.num);
      break;

    case TYPE_STRING:
      printf("> %s\n", result.value.str);
      break;
    }
    free(node);
    free(parser);
    free(tokens);
  }

  return 0;
}
