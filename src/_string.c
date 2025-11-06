#include "./_string.h"

String* cr_String(const char* value)
{
  String* result = malloc(sizeof(String));
  strcpy(result->value, value);
  result->len = strlen(value);

  return result;
}
