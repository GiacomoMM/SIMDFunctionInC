#include "OperationFunc.h"


int32_t ArrayIntAdd( const int32_t* pvn32_Array1, const int32_t* pvn32_Array2, int32_t* pvn32_ArraySum, uint64_t* u64_ArrayLen )
{
    int32_t n32_RetCode = 0;

    if( pvn32_Array1 == NULL || pvn32_Array2 == NULL || pvn32_ArraySum == NULL )
    {
        n32_RetCode = -1;
    }

    if( n32_RetCode == 0 )
    {
        if( *u64_ArrayLen == 0U )
        {
            n32_RetCode = -1;
        }
    }

    if( n32_RetCode == 0 )
    {
        #ifdef __AVX512F__
        printf("AVX-512 supported by compiler\n");

        #elif defined(__AVX2__)
        ArrayIntAddAvx2( pvn32_Array1, pvn32_Array2, pvn32_ArraySum, u64_ArrayLen );

        #elif defined(__AVX__)
        printf("AVX supported by compiler\n");

        #elif defined(__SSE2__)
        printf("SSE2 supported by compiler\n");

        #else
        n32_RetCode = -1;

        #endif

    }


    return n32_RetCode;
}
