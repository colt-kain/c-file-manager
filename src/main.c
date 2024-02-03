#include <stdio.h>
#include <string.h>

#include "../include/file_operations.h"

#define MAX_FILENAME_LENGTH 64

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    printf("Usage: %s [option] [arg]\n", argv[0]);
    printf("(Use -h for more information)\n");

    return 1;
  }

  if (strcmp(argv[1], "-h") == 0)
  {
    printf("Options:\n");

    printf("- \"create\" [file name]\n");
    printf("- \"rename\" [old file name] [new file name]\n");
    printf("- \"delete\" [file name]\n");
  }
  else if (strcmp(argv[1], "create") == 0)
  {
    if (argc > 3)
    {
      printf("\"create\" [file name]\n");
      return 1;
    }

    const char* file_name = argv[2];

    size_t file_name_length = strlen(file_name);
    if (file_name_length > MAX_FILENAME_LENGTH)
    {
      printf("Provided file name is too long.\n");
      return 1;
    }

    create_file(file_name);
  }
  else if (strcmp(argv[1], "rename") == 0)
  {
    if (argc > 4)
    {
      printf("\"rename\" [old file name] [new file name]\n");
      return 1;
    }

    const char* old_file_name = argv[2];
    const char* new_file_name = argv[3];

    size_t old_filename_length = strlen(old_file_name);
    size_t new_filename_length = strlen(new_file_name);
    if (old_filename_length > MAX_FILENAME_LENGTH ||
        new_filename_length > MAX_FILENAME_LENGTH)
    {
      printf("One of the provided file names is too long.\n");
      return 1;
    }

    rename_file(old_file_name, new_file_name);
  }
  else if (strcmp(argv[1], "delete") == 0)
  {
    if (argc > 3)
    {
      printf("\"delete\" [file name]\n");
      return 1;
    }

    const char* file_name = argv[2];

    size_t file_name_length = strlen(file_name);
    if (file_name_length > MAX_FILENAME_LENGTH)
    {
      printf("Provided file name is too long.\n");
      return 1;
    }

    delete_file(file_name);
  }
  else
  {
    printf("Usage: %s [option] [arg]\n", argv[0]);
    printf("(Use -h for more information)\n");

    return 1;
  }

  return 0;
}
