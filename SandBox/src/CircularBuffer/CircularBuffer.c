/*- ------------------------------------------------------------------ -*/
/*- Author: ehenriqu                                                   -*/
/*- Description: Sandbox file for CircularBuffer module created for    -*/
/*-              TDD end-of-chapter problems.                          -*/
/*- ------------------------------------------------------------------ -*/

#include "CircularBuffer.h"
#include <stdlib.h>
#include <memory.h>

static int buffer;

void CircularBuffer_Create(int bufferSize)
{
    buffer = 0;
}

void CircularBuffer_Destroy(void)
{
}

int CircularBuffer_GetCapacity(void)
{
    return 10;
}

int CircularBuffer_Read(void)
{
    return buffer;
}

int CircularBuffer_Remove(void)
{
    int retVal;
    retVal = buffer;
    buffer = 0;
    return retVal;   
}

void CircularBuffer_Add(int item)
{
    buffer = item;
}