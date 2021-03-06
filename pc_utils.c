#include <stdio.h>
#include <stdlib.h>
#include "polarCodes.h"

int * DATA_GEN(int numBits) {
    int iter_bits;

    int * dataBits = (int *)malloc(sizeof(int) * numBits);

    for (iter_bits = 0; iter_bits < numBits; iter_bits++) {
        *(dataBits + iter_bits) = rand() % 2;
    }

    return dataBits;
}

void PRINT_ARRAY_INT(int * dataBits, int numBits) {
    int iter_bits;
    
    for (iter_bits = 0; iter_bits < numBits; iter_bits++) {
        printf("%d,", *(dataBits + iter_bits));
    }
    printf("\n");
  
}

// Performs Long Division between Two Polynomials
int * poly_long_div(int * P1, int * P2, int L1, int L2, int * remLen) {
    int iter_bits, tmp, deg1, deg2;
    int * tmp_poly;

    int * rem = (int *)malloc(sizeof(int) * L1);

    for (iter_bits = 0; iter_bits < L1; iter_bits++) {
        *(rem + iter_bits) = *(P1 + iter_bits);
    }

    while((degree_poly(rem, L1) - degree_poly(P2, L2)) >= 0) {
        tmp = degree_poly(rem, L1) - degree_poly(P2, L2);
        tmp_poly = incr_degree_poly(P2, L2, tmp);

        // Replace with BITXOR Fn
        // for (iter_bits = 0; iter_bits < L1; iter_bits++) {
        //     if ((*(rem + iter_bits) - *(tmp_poly + iter_bits)) != 0) {
        //         *(rem + iter_bits) = 1;
        //     } else {
        //         *(rem + iter_bits) = 0;
        //     }
        // }

        bitxor(rem, tmp_poly, L1);

        deg1 = degree_poly(rem, L1);
        rem = rem + L1 - deg1 - 1;
        L1 = deg1 + 1;

        free(tmp_poly);
    }

    *remLen = L1;

    return rem;
}

// Returns Degree of a Polynomial
int degree_poly(int * poly, int numBits) {
    // For iter var and return var
    int iter_bits, deg;

    // Iterating over the polynomial and finding the degree
    for (iter_bits = 0; iter_bits < numBits; iter_bits++) {
        if (*(poly + iter_bits)) {
            deg = numBits - iter_bits - 1;
            break;
        }
    }

    return deg;
}

// Increase the Degree of the Polynomial
int * incr_degree_poly(int * poly, int numBits, int incr_deg) {
    int iter_bits;
    int * newPoly = (int * )malloc(sizeof(int) * (numBits + incr_deg));

    for (iter_bits = 0; iter_bits < numBits; iter_bits++) {
        *(newPoly + iter_bits) = *(poly + iter_bits);

        if (iter_bits < incr_deg) {
            *(newPoly + iter_bits + numBits) = 0;
        }
    }

    return newPoly;
}

int * ones(int len) {
    int iter_bits;
    int * dataBits = (int *)malloc(sizeof(int) * len);

    for (iter_bits = 0; iter_bits < len; iter_bits++) {
        *(dataBits + iter_bits) = 1;
    }

    return dataBits;
}

void bitxor(int * x1, int * x2, int len) {
    int iter_bits;
    // int * y = (int *)malloc(sizeof(int) * len);

    for (iter_bits = 0; iter_bits < len; iter_bits++) {
        *(x1 + iter_bits) = *(x1 + iter_bits) ^ *(x2 + iter_bits);
    }

}