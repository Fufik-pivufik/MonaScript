#include "../src/_ASTnode.h"
// #include "../src/_main_definitions.h"
#include "../src/_parser.h"
#include "../src/_tokens.h"

#include <stdio.h>
// In main function here you can write your tests
int main()
{
  printf("Test\n");
  ASTnode* a = cr_num_AST(3);
  ASTnode* b = cr_num_AST(7);
  ASTnode* unpos = cr_unary_AST('-', b);
  ASTnode* plus = cr_binary_AST('+', a, unpos);

  printf("%0.2f\n", inter_AST(plus));

  return 0;
}
