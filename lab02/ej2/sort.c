#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */

    /* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */

    unsigned int ppiv;
    ppiv = partition(a,izq,der);

    if (der > izq)
    {
        if (ppiv > izq)
        {
            quick_sort_rec(a,izq,ppiv-1);
        }

        if (ppiv < der)
        {
            quick_sort_rec(a, ppiv+1,der);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

