#include "./_string.h"

#ifndef TYPES_H
#define TYPES_H

typedef enum
{
  TYPE_NUMBER,
  TYPE_STRING,
} TYPES;

typedef struct
{
  TYPES t;
  union
  {
    String str;
    double num;
  } value;
} Type;

#endif
