#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include "Operator/OperationFunc.h"
#include "Version.h"



int main()
{

    #ifdef __AVX512F__
    printf("AVX-512 supported by compiler\n");
    #elif defined(__AVX2__)
    printf("AVX2 supported by compiler\n");
    #elif defined(__AVX__)
    printf("AVX supported by compiler\n");
    #elif defined(__SSE2__)
    printf("SSE2 supported by compiler\n");
    #else
    printf("Nessuna SIMD supportata\n");
    #endif

    uint64_t N = 16U;
    int a[N], b[N], result[N];

    // Inizializzazione array
    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    ArrayIntAdd(a, b, result, &N );

    // Stampa risultato
    for (int i = 0; i < N; i++) {
        printf("%d + %d = %d\n", a[i], b[i], result[i]);
    }
    return 0;
}
