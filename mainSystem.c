#include <stdio.h>
#include <stdlib.h>
#include "polarCodes.h"

int main() {

    srand(108);

    // Polar Code Config
    pcConfig.E = 192;
    pcConfig.K = 96;
    pcConfig.nMax = 10;
    pcConfig.iBIL = 1;
    pcConfig.iIL = 0;
    pcConfig.UL_DL = 0;
    pcConfig.L = 8;
    pcConfig.crcLen = 24;
    pcConfig.crcPolyID = 1; 

    int * dataBits = DATA_GEN(10);

    int poly[] = {1, 0, 0, 0, 0, 0, 1};
    PRINT_ARRAY_INT(poly, 7);
    printf("Degree: %d\n", degree_poly(poly, 7));

    int * polyNew = incr_degree_poly(poly, 7, 3);
    printf("Degree: %d\n", degree_poly(polyNew, 10));
    PRINT_ARRAY_INT(polyNew, 10);

    return 0;
}