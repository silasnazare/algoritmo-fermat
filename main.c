#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long int ulint;

#define VALOR 48292699

ulint fator (ulint n) {
    if (!n) return 0;
    if (!(n >> 1)) return 1;
    if (~n & 1) return ((n >> 1) > 2 ? 2 : (n >> 1));

    ulint i = n, j = 0, k = 0;

    do {
        i += j;
        k = (int) sqrt((double) i);
        j += ((!j) ? 1 : 2);
    } while (i - k * k > 0);

    k += (j - 1) >> 1;
    n /= k;

    return (n > k ? k : n);
}
int main(int argc, char** argv) {
    ulint n = VALOR;
    ulint p = 1, q = 1;

    do {
        p = fator (n);
        do {
            q = fator (p);
            p /= q;
        } while (q > 1);

        n /= p;

        if (p != 1) printf ("%u ", p);
        else printf ("%u\n", n);

    } while (p > 1);
    return (EXIT_SUCCESS);
}
