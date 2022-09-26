#include "fObj.h"


fObj *new_scalar_int(int x) {
    fObj *obj = NEW(fObj);

    fObj->type = 'I';
    fObj->ptr = (void *) &x;
    fObj->scalar = 1;
    fObj->n = 1;
}


fObj *new_scalar_double(double x) {
    fObj *obj = NEW(fObj);

    fObj->type = 'D';
    fObj->ptr = (void *) &x;
    fObj->scalar = 1;
    fObj->n = 1;
}


fObj *new_array_int(int *x, size_t n) {
    fObj *obj = NEW(fObj);

    fObj->type = 'I';
    fObj->ptr = (void *) x;
    fObj->scalar = 0;
    fObj->n = n;
}


fObj *new_array_double(double *x, size_t n) {
    fObj *obj = NEW(fObj);

    fObj->type = 'D';
    fObj->ptr = (void *) x;
    fObj->scalar = 0;
    fObj->n = n;
}


fObj *new_array_array(fObj *x, size_t n) {
    fObj *obj = NEW(fObj);

    fObj->type = 'A';
    fObj->ptr = (void *) x;
    fObj->scalar = 0;
    fObj->n = n;
}


void del_fObj(fObj *x) {
    if (x->type == 'A') {
        /* recursively free fObj */
        fObj *p = (fObj *) x->ptr;
        for (int i = 0; i < x->n; i++)
            del_fObj(p[i]);
    }

    free(x->ptr);
    free(x);
}
