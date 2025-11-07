#include <stdlib.h>
#include <string.h>

#ifndef STRING__H
#define STRING__H

typedef struct
{
  char* value;
  unsigned long len;
} String;

String* cr_String(const char* value);
String str_merge(const String* str1, const String* str2);
String conc(const String* str, unsigned long num);

#endif
