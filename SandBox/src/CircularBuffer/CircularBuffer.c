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

void CircularBuffer_Create(int bufferSize)
{
    capacity = bufferSize;
    size = 0;   // Empty buffer
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
        return buffer[0];
    }
}

int CircularBuffer_Remove(void)
{
    int retVal;
    retVal = buffer[0];
    buffer[0] = 0;
    return retVal;   
}

void CircularBuffer_Add(int item)
{
    buffer[0] = item;
    size++;
}

BOOL CircularBuffer_IsEmpty(void)
{
    return TRUE;
}