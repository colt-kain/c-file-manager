#include <stdio.h>
#include "../include/file_operations.h"

void create_file(const char* file_name)
{
  FILE* new_file = fopen(file_name, "w");

  if (new_file == NULL)
  {
    printf("Error while attempting to create the new file.\n");
    return;
  }

  fclose(new_file);
}

void rename_file(const char* file_name, const char* new_file_name)
{
  FILE* original_file = fopen(file_name, "r");
  FILE* temporary_file = fopen("temporary", "w");

  if (original_file == NULL || temporary_file == NULL)
  {
    printf("Error while attempting to rename file.\n");
    return;
  }

  char character;
  while ((character = fgetc(original_file)) != EOF)
    fputc(character, temporary_file);

  fclose(original_file);
  fclose(temporary_file);

  if (remove(file_name) != 0 || rename("temporary", new_file_name) != 0)
  {
    printf("Error while attempting to rename file.\n");
    return;
  }
}

void delete_file(const char* file_name)
{
  if (remove(file_name) != 0)
  {
    printf("Error while attempting to delete file.\n");
    return;
  }
}
