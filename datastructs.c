#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructs.h"

struct vector {
  size_t length;
  size_t capacity;
  int *data;
};
struct dstack {
  struct vector *content;
};
struct vector *vec_new(size_t capacity) {
  int *data = malloc(sizeof(int) * capacity);
  struct vector *new_vec = malloc(sizeof(struct vector));

  new_vec->data = data;
  new_vec->length = 0;
  new_vec->capacity = capacity;

  return new_vec;
}
void vec_add(struct vector *vec, int elm) {
  if (vec->length == vec->capacity)
    vec->data = realloc(vec->data, sizeof(int) * (++vec->capacity));
  (vec->data)[vec->length++] = elm;
}

void vec_rm(struct vector *v, size_t index) {
  for (size_t i = index; i <= v->length; ++i)
    v->data[i] = v->data[i+1];
  --v->length;
}

struct vector *vec_copy(struct vector *v)
{
  struct vector *new_vector = vec_new(v->capacity);
  new_vector->length = v->length;
  memcpy(new_vector->data, v->data, sizeof(int)*v->length);
  return new_vector;
}

void vec_free(struct vector *vec) {
  free(vec->data);
  free(vec);
}

void vec_print(struct vector *v)
{
  putchar('[');
  for(size_t i = 0; i < v->length; ++i)
  {
    printf("%d ", v->data[i]);
  }
  putchar(']');
  putchar('\n');
}
struct dstack *dstack_new(size_t capacity) {
  struct vector *v = vec_new(capacity);
  struct dstack *new_dstack = malloc(sizeof(struct dstack));
  new_dstack->content = v;
  return new_dstack;
}
void dstack_free(struct dstack *stk) {
  vec_free(stk->content);
  free(stk);
}
void dstack_push(struct dstack *stk, int elm) { vec_add(stk->content, elm); }
int dstack_pop(struct dstack *stk) {
  return (stk->content->data)[--stk->content->length];
}
