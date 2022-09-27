#include "fObj.h"

int main() {
    int a[] = { 1, 2, 3, 4 };
    fObj *x = new_array_int(a, 4);

    int b[] = { 2, 3, 4, 5 };
    fObj *y = new_array_int(b, 4);

    fObj_println(x);
    fObj_println(y);

    return 0;
}
