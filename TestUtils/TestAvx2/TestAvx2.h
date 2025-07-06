#ifndef TESTAVX2_H_INCLUDED
#define TESTAVX2_H_INCLUDED
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../InputExpStruct.h"
#include "../../Avx2/Avx2Func.h"

int32_t TestArrayIntAddAvx2( tInputInt32_t* pv_Input, tExpOutputInt32_t* pv_Exp);

#endif // TESTAVX2_H_INCLUDED
