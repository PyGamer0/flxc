#include "fObj.h"


fObj *new_scalar_int(int x) {
    fObj *obj = NEW(fObj);

    obj->type = 'I';
    obj->ptr = (void *) &x;
    obj->scalar = 1;
    obj->n = 1;

    return obj;
}


fObj *new_scalar_double(double x) {
    fObj *obj = NEW(fObj);

    obj->type = 'D';
    obj->ptr = (void *) &x;
    obj->scalar = 1;
    obj->n = 1;

    return obj;
}


fObj *new_array_int(int *x, size_t n) {
    fObj *obj = NEW(fObj);

    obj->type = 'I';
    obj->ptr = (void *) x;
    obj->scalar = 0;
    obj->n = n;

    return obj;
}


fObj *new_array_double(double *x, size_t n) {
    fObj *obj = NEW(fObj);

    obj->type = 'D';
    obj->ptr = (void *) x;
    obj->scalar = 0;
    obj->n = n;

    return obj;
}


fObj *new_array_array(fObj *x, size_t n) {
    fObj *obj = NEW(fObj);

    obj->type = 'A';
    obj->ptr = (void *) x;
    obj->scalar = 0;
    obj->n = n;

    return obj;
}


void del_fObj(fObj *x) {
    if (x->type == 'A') {
        /* recursively free fObj */
        fObj *p = (fObj *) x->ptr;
        for (size_t i = 0; i < x->n; i++)
            del_fObj(p + i);
    }

    free(x->ptr);
    free(x);
}
