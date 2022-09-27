#include <stdio.h>
#include "fObj.h"

static void _fObj_print_s(fObj *x, int nl) {
    if (x->type == 'D')
        printf("%lf", * (double *) x->ptr);
    else if (x->type == 'I')
        printf("%d", * (int *) x->ptr);
    else {
        fprintf(stderr, "Invalid type '%c' for fObj as scalar.\n", x->type);
        exit(1);
    }

    if (nl)
        printf("\n");
}

static void _fObj_print_a(fObj *x, int nl) {
    if (x->type == 'D') {
        double *p = (double *) x->ptr;

        printf("[");
        for (size_t i = 0; i < x->n; i++) {
            printf("%lf", p[i]);
            if (i != x->n - 1)
                printf(", ");
        }
        printf("]");
    } else if (x->type == 'I') {
        int *p = (int *) x->ptr;

        printf("[");
        for (size_t i = 0; i < x->n; i++) {
            printf("%d", p[i]);
            if (i != x->n - 1)
                printf(", ");
        }
        printf("]");
    } else if (x->type == 'A') {
        fObj *p = (fObj *) x->ptr;

        printf("[");
        for (size_t i = 0; i < x->n; i++) {
            fObj_print(p + i);
            if (i != x->n - 1)
                printf(", ");
        }
        printf("]");
    } else {
        fprintf(stderr, "Invalid type '%c' for fObj.\n", x->type);
        exit(1);
    }

    if (nl)
        printf("\n");
}

void fObj_println(fObj *x) {
    if (x->scalar)
        _fObj_print_s(x, 1);
    else
        _fObj_print_a(x, 1);
}

void fObj_print(fObj *x) {
    if (x->scalar)
        _fObj_print_s(x, 0);
    else
        _fObj_print_a(x, 0);
}
