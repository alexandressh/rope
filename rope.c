#include <stdio.h>
#include <stdlib.h>

#define LEAF_LEN 2

typedef struct node {
  struct node *left, *right, *parent;
  char * str;
  int lCount;
} Node;

typedef Node * Rope;

Rope create_rope(Node * parent, char str[], int l, int r) {
  Node * tmp = malloc(sizeof(Node));

  tmp->left = NULL;
  tmp->right = NULL;
  tmp->parent = parent;

  if((r-l) > LEAF_LEN) {
    tmp->str = NULL;
    tmp->lCount = (l + r) / 2;
    int m =  (l + r) / 2;
    tmp->left = create_rope(tmp, str, l, m);
    tmp->right = create_rope(tmp, str, m + 1, r);
  } else {
    tmp->lCount = (r-l);
    tmp->str = malloc(sizeof(char) * (LEAF_LEN + 1));
    int j = 0;
    int i;

    for(i = l; i <= r; i++) {
      tmp->str[j] = str[i];
      j++;
    }
    tmp->str[j] = '\0';
  }

  return tmp;
}

Rope new_rope(char str[], int size) {
 return create_rope(NULL, str, 0, size - 1);
}

void append(Rope * root, Node * left, Node * right) {
  Node * tmp = malloc(sizeof(Node));
  tmp->parent = NULL;
  tmp->left = left;
  tmp->right = right;
  tmp->lCount = left->lCount;
  tmp->str = NULL;

  * root = tmp;
}

void private_print_rope(Node * p) {
  if(p != NULL) {
    if(p->left == NULL && p->right == NULL) {
      printf("%s", p->str);
      fflush(stdout);
    } else {
      private_print_rope(p->left);
      private_print_rope(p->right);
    }
  }
}

void printRope(Node * p) {
  private_print_rope(p);
  printf("\n");
  fflush(stdout);
}

/* Retorna 1 se a chave for encontrada */
int search(Node p, char str[]) {
  return 0;
}

void insert(Node *p, char str[]) {

}

/* Retorna 0 se a chave não for encontrada */
int remove_string(Node *p, char str[]) {
  return 0;
}


void cleanup(Node * p) {
  if(p != NULL) {
      cleanup(p->left);
      cleanup(p->right);
      free(p);
  }
}
