#include "_ASTnode.h"

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

ASTnode* cr_str_AST(char* str)
{
  ASTnode* str_node = malloc(sizeof(ASTnode));

  str_node->t = AST_STRING;
  str_node->node.str.value = str;
  str_node->node.str.len = strlen(str);

  return str_node;
}

Type inter_AST(ASTnode* node)
{
  Type result;
  switch (node->t)
  {
  case AST_STRING:
    result.t = TYPE_STRING;
    result.value.str = node->node.str;
    break;
  case AST_NUMBER:
    result.t = TYPE_NUMBER;
    result.value.num = node->node.number.val;
    break;
  case AST_UNARY:
    if (node->node.unary.op == '-')
      result = inter_AST(node->node.unary.right);
    result.value.num = -result.value.num;
    break;

  case AST_BINARY:
    Type left = inter_AST(node->node.binary.left);
    Type right = inter_AST(node->node.binary.right);

    if (left.t == right.t && right.t == TYPE_NUMBER)
      switch (node->node.binary.op)
      {
      case '+':
        result.t = TYPE_NUMBER;
        result.value.num = left.value.num + right.value.num;
        break;
      case '-':
        result.t = TYPE_NUMBER;
        result.value.num = left.value.num - right.value.num;
        break;
      case '*':
        result.t = TYPE_NUMBER;
        result.value.num = left.value.num * right.value.num;
        break;
      case '/':
        result.t = TYPE_NUMBER;
        result.value.num = left.value.num / right.value.num;
        break;
      }
  }
  return result;
}
