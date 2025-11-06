#include "./_ASTnode.h"
#include "./_intepretation.h"
#include "./_main_definitions.h"
#include "./_parser.h"
#include "./_tokens.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char expr[BUFF_SIZE];
  unsigned long tokens_count;

  if (argc > 1)
  {
    exec(argv[1]);

    return 0;
  }

  printf("\tWelcome to calculator\n");
  while (1)
  {
    printf("> ");
    fgets(expr, BUFF_SIZE - 1, stdin);
    if (strcmp(expr, "exit\n") == 0 || expr[0] == EOF)
    {
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
    double result = inter_AST(node);

    printf("> %.2f\n", result);

    free(node);
    free(parser);
    free(tokens);
  }

  return 0;
}
