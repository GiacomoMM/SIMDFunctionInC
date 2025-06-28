#include "Avx2Func.h"


void ArrayIntAddAvx2( const int32_t* pvn32_Array1, const int32_t* pvn32_Array2, int32_t* pvn32_ArraySum, uint64_t* u64_ArrayLen )
{
    __m256i v1, v2, vsum;
    uint64_t u64_Idx = 0U;
    for( u64_Idx = 0U; u64_Idx <= *u64_ArrayLen - 8U; u64_Idx += 8U )
    {
        v1 = _mm256_loadu_si256( (__m256i const*) &pvn32_Array1[ u64_Idx ] );
        v2 = _mm256_loadu_si256( (__m256i const*) &pvn32_Array2[ u64_Idx ] );
        vsum = _mm256_add_epi32( v1, v2 );
        _mm256_storeu_si256( (__m256i*) &pvn32_ArraySum[ u64_Idx ], vsum);
    }
    // Gestione dei rimanenti (n non multiplo di 8)
    while( u64_Idx < *u64_ArrayLen )
    {
        pvn32_ArraySum[ u64_Idx ] = pvn32_Array1[ u64_Idx ] + pvn32_Array2[ u64_Idx ];
        u64_Idx++;
    }
}
