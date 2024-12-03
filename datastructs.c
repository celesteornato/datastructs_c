#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructs.h"

struct vector *vec_new(size_t capacity, size_t size) {
  void **data = malloc(size * capacity);
  struct vector *new_vec = malloc(sizeof(struct vector));

  new_vec->data = data;
  new_vec->length = 0;
  new_vec->capacity = capacity;

  return new_vec;
}
void vec_add(struct vector *v, void *elm) {
  if (v->length == v->capacity)
    v->data = realloc(v->data, v->size * (++v->capacity));
  (v->data)[v->length++] = elm;
}

void vec_rm(struct vector *v, size_t index) {
  for (size_t i = index; i <= v->length; ++i)
    v->data[i] = v->data[i+1];
  --v->length;
}

struct vector *vec_copy(struct vector *v)
{
  struct vector *new_vector = vec_new(v->capacity, v->size);
  new_vector->length = v->length;
  memcpy(new_vector->data, v->data, v->size*v->length);
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
    printf("%d,", v->data[i]);
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

struct string *str_new(char str[]){
  size_t counter = 1;
  for(size_t i = 0; str[i] != '\0'; ++i)
    ++counter;

  char *data = malloc(counter*sizeof(char));
  struct string *new_str = malloc(sizeof(struct string));
  memcpy(data, str, counter*sizeof(char));
  new_str->data = data;
  new_str->length = counter;

  return new_str;
}

void str_print(struct string *s)
{
  for(size_t i = 0; i < s->length; ++i)
    printf("%c", s->data[i]);
}

void str_push(struct string* s, char c)
{
  s->data = realloc(s->data, sizeof(char)*(++s->length));
  (s->data)[s->length++] = c;
}
