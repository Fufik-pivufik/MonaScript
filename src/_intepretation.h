#include "./_ASTnode.h"
#include "./_parser.h"
#include "./_tokens.h"

#ifndef INTERPRETATION_H
#define INTERPRETATION_H

ASTnode* parse(Parser* parser);
ASTnode* next_binary_node(Parser* parser);

#endif
