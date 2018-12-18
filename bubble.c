#include <stdio.h>
 

void swap_mem (void *p1, void *p2, int elem_size){
  char *pp1 = (char*) p1;
  char *pp2 = (char*) p2;
  char tmp;

  for (int i = 0; i < elem_size; i++){
      tmp = pp1[i];
      pp1[i] = pp2[i];
      pp2[i] = tmp;
    }
}
 
void bubblesort (void *arr, int num_elems, int elem_size, int (*cmp_func) (void*, void*)){
  void *pi, *pj;
 
  for (int i = 0; i < (num_elems - 1); i++)
    for (int j = i + 1; j < num_elems; j++) {
        pi = (char*)arr + i * elem_size;
        pj = (char*)arr + j * elem_size;
 
        if (cmp_func (pi, pj) > 0)
          swap_mem (pi, pj, elem_size);
      }
}
 
/* --------- Это пользовательские коды ---------- */
 
int cmp_int (void *p1, void *p2){
  int *pp1 = (int*) p1;
  int *pp2 = (int*) p2;
 
  if (*pp1 < *pp2)return -1;
  else if (*pp1 == *pp2)return 0;
  else  return 1;
}
int cmp_double (void *p1, void *p2){
  double *pp1 = (double*) p1;
  double *pp2 = (double*) p2;
 
  if (*pp1 < *pp2)return -1;
  else if (*pp1 == *pp2)return 0;
  else return 1;
}
int cmp_char (void *p1, void *p2){
  char *pp1 = (char*) p1;
  char *pp2 = (char*) p2;
 
  if (*pp1 < *pp2)return -1;
  else if (*pp1 == *pp2) return 0;
  else return 1;
}
 
int main (void){
  int max_a = 10;
  int a[] = { 1, 7, 8, 34, 2, 5, 0, 6, 9, 3 };
  int max_b = 12;
  double b[] = { 1.0, 7.0, 8.0, 34.0, 2.0, 5.0, 0.0, 6.0, 9.0, 3.0, 12.0, 17.0 };
  
  char c[] = {"jihgfedcba"};

  bubblesort (a, max_a, sizeof (a[0]), cmp_int);
  for (int i = 0; i < max_a; i++)
    printf ("%d ", a[i]);
  printf ("\n");
 
  bubblesort (b, max_b, sizeof (b[0]), cmp_double);
  for (int i = 0; i < max_b; i++)
    printf ("%f ", b[i]);
  printf ("\n");
  
  bubblesortsort (c, max_a, sizeof (c[0]), cmp_char);
  for (int i = 0; i < max_a; i++)
    printf ("%c ", c[i]);
    
  printf ("\n");
 
  return 0;
}
