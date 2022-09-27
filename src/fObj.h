#pragma once
#include <stddef.h>
#include <stdlib.h>

#define MALLOC(n, t) (t *) malloc((n) * sizeof(t))
#define NEW(t) MALLOC(1, t)

typedef struct fObj {
    char type;
    void *ptr;
    int scalar;  /* is scalar? */
    size_t n;
} fObj;

/* constructors */
fObj *new_scalar_int(int x);
fObj *new_scalar_double(double x);
fObj *new_array_int(int *x, size_t n);
fObj *new_array_double(double *x, size_t n);
fObj *new_array_array(fObj *x, size_t n);

/* methods */
void fObj_println(fObj *x);
void fObj_print(fObj *x);

/* destructors */
void del_fObj(fObj *x);
