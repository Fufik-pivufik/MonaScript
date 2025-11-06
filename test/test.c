#include "../src/_ASTnode.h"
#include "../src/_main_definitions.h"
#include "../src/_parser.h"
#include "../src/_tokens.h"

#include <stdio.h>
#include <string.h>
// In main function here you can write your tests
int main()
{
  printf("Test\n");
  FILE* src;
  src = fopen(
      "/home/mitra/Desktop/Programming/Study/C/calculator/test_src/hello.mns",
      "r");

  unsigned long count = 0;
  char expr[BUFF_SIZE];

  while (fgets(expr, BUFF_SIZE, src) != NULL)
  {
    Token** tokens = tokenize(expr, &count);

    for (int i = 0; i < count; i++)
    {
      printf("|%d, %s\n", tokens[i]->t, tokens[i]->value);
    }

    count = 0;
  }

  return 0;
}
