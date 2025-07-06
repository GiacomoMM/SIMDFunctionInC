#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include "Operator/OperationFunc.h"
#include "Version.h"
#include <time.h>
#include <unistd.h>
#include "TestUtils/TestUtils.h"


int main()
{
    clock_t time1, time2;
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



    LetturaFileBinariTest();

    return 0;
}
