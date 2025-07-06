#include "TestUtils.h"

tInputInt32_t vInputInt32_t[ 10U ];
tExpOutputInt32_t vExpOutputInt32_t[ 10U ];

int32_t gn32_MaxNumExpPacket;
int32_t gn32_MaxNumInputPacket;

int32_t LetturaFileBinariTest()
{
    int32_t n32_RetCode = 0;

    memset( vInputInt32_t, 0, sizeof( vInputInt32_t ) );
    memset( vExpOutputInt32_t, 0, sizeof( vExpOutputInt32_t ) );

    FILE* fInput = fopen( "TestBin/Int32_tAddInput.bin", "rb" );
    if( fInput == NULL )
    {
        printf("Errore apertura Int32_tAddInput\n");
        n32_RetCode = -1;
    }

    if( n32_RetCode == 0 )
    {
        gn32_MaxNumInputPacket = fread( vInputInt32_t, sizeof( int32_t ), sizeof( vInputInt32_t ), fInput );
        if( gn32_MaxNumInputPacket == 0 )
        {
            printf("Nessun pacchetto in Input Letto\n");
            n32_RetCode = -1;
        }
    }

    FILE* fExp = fopen( "TestBin/Int32_tAddExpect.bin", "rb" );
    if( fExp == NULL )
    {
        printf("Errore apertura Int32_tAddExpect.bin\n");
        n32_RetCode = -1;
    }

    if( n32_RetCode == 0 )
    {
        gn32_MaxNumExpPacket = fread( vExpOutputInt32_t, sizeof( int32_t ), sizeof( vExpOutputInt32_t ), fExp );
        if( gn32_MaxNumExpPacket == 0 )
        {
            printf("Nessun pacchetto in Exp Letto\n");
            n32_RetCode = -1;
        }
    }

    if( n32_RetCode == 0 )
    {

        gn32_MaxNumInputPacket /= ( SizeArrayTest * 2 );
        gn32_MaxNumExpPacket /= ( SizeArrayTest );
        if( gn32_MaxNumInputPacket !=  gn32_MaxNumExpPacket )
        {
            printf("Nessun pacchetti non congruenti gn32_MaxNumInputPacket %d, gn32_MaxNumExpPacket %d\n", gn32_MaxNumInputPacket, gn32_MaxNumExpPacket );
            n32_RetCode = -1;
        }
        printf("gn32_MaxNumInputPacket %d, gn32_MaxNumExpPacket %d\n", gn32_MaxNumInputPacket, gn32_MaxNumExpPacket );
    }

    ( void ) fclose( fInput );
    ( void ) fclose( fExp );

    return n32_RetCode;
}

int32_t Test()
{
    int32_t n32_RetCode = 0;
    int32_t n32_TempRetCode = 0;
    n32_RetCode = LetturaFileBinariTest();

    if( n32_RetCode == 0 )
    {
        #ifdef __AVX512F__
        printf("AVX-512 supported by compiler\n");

        #elif defined(__AVX2__)
        n32_TempRetCode = TestArrayIntAddAvx2( &vInputInt32_t, &vExpOutputInt32_t );
        if( n32_TempRetCode != 0 )
        {
            printf("TestArrayIntAddAvx2 Test Failed\n");
        }

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
