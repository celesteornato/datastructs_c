#include "datastructs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const struct error GET_ERROR = {
  "Cannot access index"
};

struct vector *vec_new(size_t capacity, const size_t size) {
  void **data = malloc(size * capacity);
  struct vector *new_vec = malloc(sizeof(struct vector));

  new_vec->data = data;
  new_vec->length = 0;
  new_vec->capacity = capacity;
  new_vec->size = size;

  return new_vec;
}

void vec_add(struct vector *v, void *elm) {
  if (v->length == v->capacity)
    v->data = realloc(v->data, v->size * (++v->capacity));
  (v->data)[v->length++] = elm;
}

struct result vec_get(struct vector *v, size_t index) {
  struct result to_return;
  if (index > v->length - 1) {
    to_return.ok = 0;
    to_return.result.err = GET_ERROR;
  }
  else
  {
    to_return.ok = 1;
    to_return.result.elm = v->data[index];
  }
  return to_return;
}

void vec_append(struct vector *v, void **arr, const size_t size) {
  if (v->length + size >= v->capacity)
    v->data = realloc(v->data, v->size * (v->capacity + size));
  memcpy(v->data + v->length, arr, size * v->size);
  v->length += size * v->size;
}

void vec_foreach(struct vector *v, void f(void *)) {
  for (size_t i = 0; i < v->length; ++i)
    f(v->data[i]);
}

void mvec_foreach(struct vector *v, void f(struct vector *)) {
  for (size_t i = 0; i < v->length; ++i)
    vec_foreach(v->data[i], (void (*)(void *))f);
}

void vec_rm(struct vector *v, size_t index) {
  for (size_t i = index; i <= v->length; ++i)
    v->data[i] = v->data[i + 1];
  --v->length;
}

struct vector *vec_copy(struct vector *v) {
  struct vector *new_vector = vec_new(v->capacity, v->size);
  new_vector->length = v->length;
  memcpy(new_vector->data, v->data, v->size * v->length);
  return new_vector;
}

void vec_free(struct vector *vec) {
  free(vec->data);
  free(vec);
}

void mvec_free(struct vector *vec) {
  for (size_t i = 0; i < vec->length; ++i)
    vec_foreach(vec, (void (*)(void *))vec_free);
  free(vec);
}

void vec_print(struct vector *v, const char *fmt) {
  putchar('[');
  for (size_t i = 0; i < v->length; ++i) {
    printf(fmt, v->data[i]);
  }
  putchar(']');
  putchar('\n');
}

struct dstack *dstack_new(size_t capacity, size_t size) {
  struct vector *v = vec_new(capacity, size);
  struct dstack *new_dstack = malloc(sizeof(struct dstack));
  new_dstack->content = v;
  return new_dstack;
}
void dstack_free(struct dstack *stk) {
  vec_free(stk->content);
  free(stk);
}
void dstack_push(struct dstack *stk, void *elm) { vec_add(stk->content, elm); }
void *dstack_pop(struct dstack *stk) {
  return (stk->content->data)[--stk->content->length];
}
