/*- ------------------------------------------------------------------ -*/
/*- Author: ehenriqu                                                   -*/
/*- Description: Sandbox file for CircularBuffer module created for    -*/
/*-              TDD end-of-chapter problems.                          -*/
/*- ------------------------------------------------------------------ -*/

#include "CircularBuffer.h"
#include <stdlib.h>
#include <memory.h>

static int* buffer;
static int  capacity;
static int  size;
static int  head;

void CircularBuffer_Create(int bufferSize)
{
    capacity = bufferSize;
    size = 0;   // Empty buffer
    head = 0;   // Initial index
    buffer = (int*) malloc(capacity * sizeof(int));
}

void CircularBuffer_Destroy(void)
{
    free(buffer);
}

int CircularBuffer_GetCapacity(void)
{
    return capacity;
}

int CircularBuffer_GetSize(void)
{
    return size;
}

int CircularBuffer_Read(void)
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        return buffer[head-1];
    }
}

int CircularBuffer_Remove(void)
{
    size--;
    return buffer[--head];
}

void CircularBuffer_Add(int item)
{
    size++;
    buffer[head++] = item;
}

BOOL CircularBuffer_IsEmpty(void)
{
    return (size == 0);
}

BOOL CircularBuffer_IsFull(void)
{
    return (size == capacity);
}