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

static const int capacity = 10;

TEST_GROUP(CircularBuffer)
{
    void setup()
    {
      CircularBuffer_Create(capacity);
    }

    void teardown()
    {
      //CircularBuffer_Destroy();
    }
};

TEST(CircularBuffer, Create)
{
  const int capacity = 10;
  int actualCapacity;
  CircularBuffer_Create(capacity);
  actualCapacity = CircularBuffer_GetCapacity();
  CHECK_EQUAL(capacity, actualCapacity);
}

TEST(CircularBuffer, ReadEmptyBuffer)
{
  int expected = 0;
  int actual;
  actual = CircularBuffer_Read();
  CHECK_EQUAL(expected, actual);
}

TEST(CircularBuffer, AddItemAndRead)
{
  const int item = 1;
  int readValue;
  CircularBuffer_Add(item);
  readValue = CircularBuffer_Read();
  CHECK_EQUAL(item, readValue);
}

TEST(CircularBuffer, RemoveItem)
{
  const int item = 1;
  int removedValue;
  CircularBuffer_Add(item);
  removedValue = CircularBuffer_Remove();
  CHECK_EQUAL(item, removedValue);
}

TEST(CircularBuffer, RemoveItemAndReadEmptyBuffer)
{
  const int item = 1;
  int readValue;
  int expectedReadValue = 0;
  CircularBuffer_Add(item);
  CircularBuffer_Remove();
  readValue = CircularBuffer_Read();
  CHECK_EQUAL(expectedReadValue, readValue);
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