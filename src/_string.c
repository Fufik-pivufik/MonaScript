#include "./_string.h"

String* cr_String(const char* value)
{
  String* result = malloc(sizeof(String));
  strcpy(result->value, value);
  result->len = strlen(value);

  return result;
}

String str_merge(const String* str1, const String* str2)
{
  String result;
  result.len = str1->len + str2->len;
  result.value = malloc(result.len + 1);
  unsigned long indx = 0;
  for (; indx < str1->len; indx++)
    result.value[indx] = str1->value[indx];

  for (unsigned long j = 0; j < str2->len; j++)
    result.value[indx + j] = str2->value[j];

  result.value[result.len] = '\0';
  return result;
}

String conc(const String* str, unsigned long num)
{
  String result;
  result.len = str->len * num;
  result.value = malloc(result.len + 1);
  for (unsigned long i = 0; i < result.len; i++)
    result.value[i] = str->value[i % str->len];

  return result;
}
