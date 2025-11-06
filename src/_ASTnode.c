#include "./_ASTnode.h"

ASTnode* cr_num_AST(double num)
{
  ASTnode* node = malloc(sizeof(ASTnode));

  node->t = AST_NUMBER;
  node->node.number.val = num;
  return node;
}

ASTnode* cr_unary_AST(char op, ASTnode* right)
{
  ASTnode* un_node = malloc(sizeof(ASTnode));
  un_node->t = AST_UNARY;
  un_node->node.unary.op = op;
  un_node->node.unary.right = right;

  return un_node;
}

ASTnode* cr_binary_AST(char op, ASTnode* left, ASTnode* right)
{
  ASTnode* bin_node = malloc(sizeof(ASTnode));

  bin_node->t = AST_BINARY;
  bin_node->node.binary.op = op;
  bin_node->node.binary.left = left;
  bin_node->node.binary.right = right;
  return bin_node;
}

double inter_AST(ASTnode* node)
{
  switch (node->t)
  {
  case AST_NUMBER:
    return node->node.number.val;

  case AST_UNARY:
    if (node->node.unary.op == '-')
      return -inter_AST(node->node.unary.right);

  case AST_BINARY:
    double left = inter_AST(node->node.binary.left);
    double right = inter_AST(node->node.binary.right);

    switch (node->node.binary.op)
    {
    case '+':
      return left + right;
    case '-':
      return left - right;
    case '*':
      return left * right;
    case '/':
      return left / right;
    }
  }
  return 0;
}
