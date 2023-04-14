#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interpreter.h"

int main(int argc, char *argv[]) {
  char *HELP = "usage: fint.exe [-e expression] [filepath]";
  switch (argc) {
  case 1:
    fprintf(stderr, "%s\n", HELP);
    break;
  case 2:
    if (strcmp(argv[1], "-e") == 0) {
      fprintf(stderr, "fint.exe -e [expression]\n");
    } else {
      FILE *file = fopen(argv[1], "rb");
      if (file == NULL) {
        fprintf(stderr, "Error: failed to open the file!\n");
        exit(EXIT_FAILURE);
      }
      long length;
      fseek(file, 0, SEEK_END);                           // seeks to the eof
      length = ftell(file);                               // length of the file
      fseek(file, 0, SEEK_SET);                           // seeks to bof
      char *string = malloc(sizeof(char) * (length + 1)); // file contents
      char ch;
      size_t i = 0;
      while ((ch = fgetc(file)) != EOF) {
        string[i] = ch;
        i += 1;
      }
      interpreter(string);
      fclose(file);
    }
    break;
  case 3:
    if (strcmp(argv[1], "-e") == 0) {
      interpreter(argv[2]);
    } else {
      fprintf(stderr, "%s", HELP);
    }
    break;
  default:
    fprintf(stderr, "Error: too many arguments!");
  }
}
