#include <stdlib.h>

struct error {
  char* msg;
};

struct result {
  unsigned char ok: 1;
  union {
    void* elm;
    struct error err;
  } result;
};

struct vector {
  size_t length;
  size_t capacity;
  size_t size;
  void **data;
};
struct dstack {
  struct vector *content;
};


extern struct vector* vec_new(size_t, size_t);
extern void vec_add(struct vector*, void*);
extern void vec_append(struct vector*, void**, const size_t);
extern void vec_rm(struct vector*, size_t);
extern struct result vec_get(struct vector*, size_t);
extern struct vector* vec_copy(struct vector*);
extern struct vector *vec_copy(struct vector *);
extern void vec_free(struct vector *); 
extern void vec_print(struct vector *, const char*);
extern void vec_foreach(struct vector *, void (void*));

extern void mvec_free(struct vector*);
extern void mvec_foreach(struct vector *, void (struct vector *));

extern struct dstack *dstack_new(size_t, size_t); 
extern void dstack_free(struct dstack *); 
extern void dstack_push(struct dstack *, void*);
extern void *dstack_pop(struct dstack *); 

extern struct string *str_new(char*);
extern void str_push(struct string*, char);
extern void str_print(struct string*);

