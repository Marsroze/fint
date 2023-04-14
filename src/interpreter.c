#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 30000

// Interpreter
void interpreter(char *src) {
  uint8_t memory[MEMORY_SIZE] = {0}; // memory array
  size_t index = 0;                  // memory index
  for (size_t i = 0; src[i] != '\0'; i++) {
    switch (src[i]) {
    case '+':
      memory[index] += 1;
      break;
    case '-':
      memory[index] -= 1;
      break;
    case '>':
      if (index == (MEMORY_SIZE - 1)) {
        fprintf(stderr, "Error: out of upper index range!\n");
        exit(EXIT_FAILURE);
      }
      index += 1;
      break;
    case '<':
      if (index == 0) {
        fprintf(stderr, "Error: out of lower index range!\n");
        exit(EXIT_FAILURE);
      }
      index -= 1;
      break;
    case '.':
      fprintf(stdout, "%c", memory[index]);
      break;
    case ',':
      fscanf(stdin, "%c", &memory[index]);
      break;
    case '[':
      if (memory[index] == 0) {
        uint64_t start = i;
        size_t depth = 1;
        while (i < strlen(src) - 1) {
          i += 1;
          uint8_t seek_char = src[i];
          if (seek_char == ']') {
            depth -= 1;
          }
          if (depth == 0) {
            break;
          }
          if (seek_char == '[') {
            depth += 1;
          }
        }
        if (i == strlen(src) - 1 && depth != 0) {
          fprintf(stderr,
                  "Error: missing closing bracket to opening bracket at char "
                  "%lld\n",
                  start);
        }
      }
      break;
    case ']':
      if (memory[index] != 0) {
        uint64_t start = i;
        size_t depth = 1;
        while (i > 0) {
          i -= 1;
          uint8_t seek_char = src[i];
          if (seek_char == '[') {
            depth -= 1;
          }
          if (depth == 0) {
            break;
          }
          if (seek_char == ']') {
            depth += 1;
          }
        }
        if (i == 0 && depth != 0) {
          fprintf(
              stderr,
              "Error missing opening bracket to closing bracket at char %lld\n",
              start);
        }
      }
      break;
    default: {
    }
    }
  }
}
