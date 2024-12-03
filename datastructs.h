#include <stdlib.h>

struct vector {
  size_t length;
  size_t capacity;
  size_t size;
  void **data;
};
struct dstack {
  struct vector *content;
};

struct string {
  size_t length;
  char *data;
};

extern struct vector* vec_new(size_t, size_t);
extern void vec_add(struct vector*, void*);
extern void vec_rm(struct vector*, size_t);
extern struct vector* vec_copy(struct vector*);
extern void vec_print(struct vector*);
extern struct vector *vec_copy(struct vector *);
extern void vec_free(struct vector *); 
extern void vec_print(struct vector *);

extern struct dstack *dstack_new(size_t, size_t); 
extern void dstack_free(struct dstack *); 
extern void dstack_push(struct dstack *, void*);
extern void *dstack_pop(struct dstack *); 

extern struct string *str_new(char*);
extern void str_push(struct string*, char);
extern void str_print(struct string*);

