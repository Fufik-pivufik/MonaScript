#include <stdlib.h>

#ifndef ASTNODE_H
#define ASTNODE_H

typedef enum
{
  AST_UNARY,
  AST_BINARY,
  AST_NUMBER,
} AST_t;

typedef struct ASTnode ASTnode;

struct ASTnode
{
  AST_t t;
  union
  {
    struct
    {
      double val;
    } number;

    struct
    {
      char op;
      ASTnode* right;
    } unary;

    struct
    {
      char op;
      ASTnode* left;
      ASTnode* right;
    } binary;
  } node;
};

ASTnode* cr_num_AST(double num);
ASTnode* cr_binary_AST(char op, ASTnode* left, ASTnode* right);
ASTnode* cr_unary_AST(char op, ASTnode* right);
double inter_AST(ASTnode* node);
#endif
