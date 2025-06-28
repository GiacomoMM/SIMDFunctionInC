#ifndef OPERATIONFUNC_H_INCLUDED
#define OPERATIONFUNC_H_INCLUDED

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <string.h>


#ifdef __AVX512F__

#elif defined(__AVX2__)

#include "../Avx2/Avx2Func.h"

#elif defined(__AVX__)

#elif defined(__SSE2__)

#endif // __AVX512F__


int32_t ArrayIntAdd( const int32_t* pvn32_Array1, const int32_t* pvn32_Array2, int32_t* pvn32_ArraySum, uint64_t* u64_ArrayLen );


#endif // OPERATIONFUNC_H_INCLUDED
