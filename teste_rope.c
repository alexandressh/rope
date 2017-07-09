#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rope.c"
#include "timer.h"

FILE * openFile() {
  // FILE * fp = fopen("./files/try.txt", "r");
  FILE * fp = fopen("./files/moby_dick.txt", "r");
  if (fp == NULL) {
      printf("File does not exist");
      exit(EXIT_FAILURE);
  }

  return fp;
}

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void concatenate(char * s1, char * s2) {
  realloc(s1, strlen(s1) + strlen(s2) + 1);
  strcat(s1, s2);
}

int main() {
  Node * rope = NULL;
  Node * tmp;
  Node * appender;

  char * strTest = "";

  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  double inicio_tempo_abb,
     fim_tempo_abb,
     inicio_tempo_avl,
     fim_tempo_avl;

  fp = openFile();

  GET_TIME(inicio_tempo_avl);
  while ((read = getline(&line, &len, fp)) != -1) {

      char *toBeFree = strTest;
      strTest = concat(strTest, line);
      free(toBeFree);

      fflush(stdout);
  }
	GET_TIME(fim_tempo_avl);

  free(line);
  free(strTest);
  len = 0;
  read = 0;
  line = NULL;


  fclose(fp);
  fp = openFile();

  GET_TIME(inicio_tempo_abb);
  while ((read = getline(&line, &len, fp)) != -1) {

      if(rope == NULL) {
        rope = new_rope(line, read);
      }
      else {
        tmp = new_rope(line, read);
        append(&appender, rope, tmp);
        rope = appender;
      }
  }
  GET_TIME(fim_tempo_abb);

  cleanup(rope);
  free(line);
  fclose(fp);

  printf("ROPE %7.6f\n", fim_tempo_abb - inicio_tempo_abb);
  printf("STRING %7.6f\n", fim_tempo_avl - inicio_tempo_avl);


  return 0;
}
