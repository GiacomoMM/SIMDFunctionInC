#ifndef AVX2FUNC_H_INCLUDED
#define AVX2FUNC_H_INCLUDED

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <string.h>

void ArrayIntAddAvx2( const int32_t* pvn32_Array1, const int32_t* pvn32_Array2, int32_t* pvn32_ArraySum, uint64_t* u64_ArrayLen );


#endif // AVX2FUNC_H_INCLUDED
