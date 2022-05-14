//- ------------------------------------------------------------------
//- ------------------------------------------------------------------
//- Author: ehenriqu                                                  
//- Description: Sandbox file for CicularBuffer module created for    
//-              TDD end-of-chapter problems.                         
//- ------------------------------------------------------------------

extern "C"
{
#include "CircularBuffer.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(CircularBuffer)
{
    void setup()
    {
      CircularBuffer_Create();
    }

    void teardown()
    {
       CircularBuffer_Destroy();
    }
};

TEST(CircularBuffer, Create)
{
//  FAIL("Start here");
}

