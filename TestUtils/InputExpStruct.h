#ifndef INPUTEXPSTRUCT_H_INCLUDED
#define INPUTEXPSTRUCT_H_INCLUDED

#define SizeArrayTest ( 50U )

#pragma pack(1);
typedef struct
{
    int32_t n32_x[SizeArrayTest];
    int32_t n32_y[SizeArrayTest];

}tInputInt32_t;

typedef struct
{
    int32_t n32_OutputExp[SizeArrayTest];

}tExpOutputInt32_t;
#pragma pack(0);


#endif // INPUTEXPSTRUCT_H_INCLUDED
