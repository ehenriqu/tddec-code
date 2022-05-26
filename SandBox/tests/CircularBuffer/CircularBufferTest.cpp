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

TEST(CircularBuffer, AddItem)
{
  const int item = 1;
  int actual;
  CircularBuffer_Add(item);
  actual = CircularBuffer_GetSize();
  CHECK_EQUAL(1, actual);
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

TEST(CircularBuffer, AddItemAndRead)
{
  int readValue;
  CircularBuffer_Add(1);
  readValue = CircularBuffer_Read();
  CHECK_EQUAL(1, readValue);
}

TEST(CircularBuffer, RemoveItem)
{
  const int item = 1;
  int removedValue, actual;
  CircularBuffer_Add(item);
  removedValue = CircularBuffer_Remove();
  CHECK_EQUAL(item, removedValue);
  actual = CircularBuffer_GetSize();
  CHECK_EQUAL(0, actual);
}

TEST(CircularBuffer, AddAndRemoveItemsAndReadHead)
{
  int actual;
  CircularBuffer_Add(1);
  CircularBuffer_Add(2);
  CircularBuffer_Add(3);
  CircularBuffer_Remove();
  actual = CircularBuffer_Read();
  CHECK_EQUAL(2, actual);
}

TEST(CircularBuffer, CheckIsEmpty)
{
  BOOL actual;
  actual = CircularBuffer_IsEmpty();
  CHECK_EQUAL(TRUE, actual);

  CircularBuffer_Add(1);
  actual = CircularBuffer_IsEmpty();
  CHECK_EQUAL(FALSE, actual);
}

TEST(CircularBuffer, CheckIsFull)
{
  BOOL actual;

  // Create a circular buffer with capacity of 1
  CircularBuffer_Destroy(); // Destroy anything created by the setup function 
  CircularBuffer_Create(1);
  CHECK_EQUAL(1, CircularBuffer_GetCapacity());

  actual = CircularBuffer_IsFull();
  CHECK_EQUAL(FALSE, actual);

  CircularBuffer_Add(1);
  actual = CircularBuffer_IsFull();
  CHECK_EQUAL(TRUE, actual);
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