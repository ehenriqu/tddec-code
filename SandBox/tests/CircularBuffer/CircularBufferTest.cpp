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

static const int setupCapacity = 10;

TEST_GROUP(CircularBuffer)
{
    void setup()
    {
      CircularBuffer_Create(setupCapacity);
    }

    void teardown()
    {
      CircularBuffer_Destroy();
    }
};

IGNORE_TEST(CircularBuffer, Destroy)
{
  int actual;
  actual = CircularBuffer_GetCapacity();
  CHECK_EQUAL(setupCapacity,actual);

  CircularBuffer_Destroy(); // Destroy anything created by the setup function
  actual = CircularBuffer_GetCapacity();
  CHECK_EQUAL(0,actual);
}

TEST(CircularBuffer, Create)
{
  const int capacity = 5;
  int actual;
  CircularBuffer_Destroy(); // Destroy anything created by the setup function
  
  CircularBuffer_Create(capacity);
  actual = CircularBuffer_GetCapacity();
  CHECK_EQUAL(capacity, actual);
}

TEST(CircularBuffer, GetSizeOfEmptyBuffer)
{
  int expectedSize = 0;
  int actual = CircularBuffer_GetSize();
  CHECK_EQUAL(expectedSize, actual);
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

TEST(CircularBuffer, AddMultipleItems)
{
  const int item = 1;
  int expectedSize, actual;

  CircularBuffer_Add(item);
  expectedSize = 1;
  actual = CircularBuffer_GetSize();
  CHECK_EQUAL(expectedSize, actual);

  CircularBuffer_Add(item);
  expectedSize = 2;
  actual = CircularBuffer_GetSize();
  CHECK_EQUAL(expectedSize, actual);
}

TEST(CircularBuffer, CheckIsEmpty)
{
  // const int item = 1;
  // BOOL actual;
  // BOOL expected = TRUE;
  // actual = CircularBuffer_IsEmpty();
  // CHECK_EQUAL(expected, actual);

  // CircularBuffer_Add(item);
  // expected = FALSE;
  // actual = CircularBuffer_IsEmpty();
  // CHECK_EQUAL(expected, actual);
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