#include "./_intepretation.h"
#include "_main_definitions.h"

void exec(const char* filepath)
{
  char expr[BUFF_SIZE];
  unsigned long tokens_count = 0;

  FILE* src;
  src = fopen(filepath, "r");
  if (src == NULL)
  {
    printf("Error opening file: \e[38;2;255;100;150m%s\n\e[0m", filepath);
    exit(1);
  }

  while (fgets(expr, BUFF_SIZE - 1, src) != NULL)
  {
    if (expr[0] == '#')
      continue;

    if (expr[0] == '@')
    {
      char new_file[BUFF_SIZE];
      strcpy(new_file, get_pathdir(filepath));
      int plen = strlen(new_file);
      int j = 1, start = j;
      while (isalpha(expr[j]))
        j++;

      int len = j - start;
      char* fname = malloc(len + 5);
      strncpy(fname, &expr[1], len);
      fname[len] = '.';
      fname[len + 1] = 'm';
      fname[len + 2] = 'n';
      fname[len + 3] = 's';
      fname[len + 4] = '\0';
      for (int i = 0; i <= len + 4; i++)
      {
        new_file[i + plen] = fname[i];
      }

      free(fname);
      exec(new_file);
      continue;
    }
    expr[BUFF_SIZE - 1] = '\0';

    if (strcmp(expr, "") == 0)
      continue;

    Token** tokens = tokenize(expr, &tokens_count);

    Parser* parser = cr_Parser(tokens, tokens_count);

    ASTnode* node = parse(parser);
    double result = inter_AST(node);

    printf("> %.2f\n", result);

    free(node);
    free(parser);
    free(tokens);
  }

  fclose(src);
}

char* get_pathdir(const char* filepath)
{
  const char* last_slash = strrchr(filepath, '/');

  if (last_slash == NULL)
  {
    char* result = malloc(2);
    strcpy(result, ".");
    return result;
  }

  size_t length = last_slash - filepath;
  char* result = malloc(length + 1);

  if (result == NULL)
  {
    return NULL;
  }

  strncpy(result, filepath, length + 1);
  result[length + 1] = '\0';

  return result;
}
