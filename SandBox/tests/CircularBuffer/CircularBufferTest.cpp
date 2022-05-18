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

TEST(CircularBuffer, AddItem)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, RemoveItem)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, CheckIsEmpty)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, CheckIsFull)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, AddItemToFullBuffer)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, RemoveItemFromEmptyBuffer)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, AddInteger)
{
//  FAIL("Start here");
}

TEST(CircularBuffer, AddNonInteger)
{
//  FAIL("Start here");
}