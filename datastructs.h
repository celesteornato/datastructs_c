#include <stdlib.h>

extern struct vector* vec_new(size_t);
extern void vec_add(struct vector*, int);
extern void vec_rm(struct vector*, size_t);
extern struct vector* vec_copy(struct vector*);
extern void vec_print(struct vector*);
extern struct vector *vec_copy(struct vector *);
extern void vec_free(struct vector *); 
extern void vec_print(struct vector *);

extern struct dstack *dstack_new(size_t); 
extern void dstack_free(struct dstack *); 
extern void dstack_push(struct dstack *, int );
extern int dstack_pop(struct dstack *); 

