#include <stdio.h>
#include <stdlib.h>

#define LEAF_LEN 2

typedef struct node {
  struct node *left, *right, *parent;
  char * str;
  int lCount;
} Node;

typedef Node * Rope;

void create_rope(Node * root, Node * parent, char str[], int l, int r);

void inorder(Node * p);

/* Retorna 1 se a chave for encontrada */
int search(Node p, char str[]);

void insert(Node *p, char str[]);

/* Retorna 0 se a chave não for encontrada */
int remove_string(Node *p, char str[]);
