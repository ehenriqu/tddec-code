/*- ------------------------------------------------------------------ -*/
/*- Author: ehenriqu                                                   -*/
/*- Description: Sandbox file for CircularBuffer module created for    -*/
/*-              TDD end-of-chapter problems.                          -*/
/*- ------------------------------------------------------------------ -*/

#ifndef D_CircularBuffer_H
#define D_CircularBuffer_H

#define TRUE 1
#define FALSE 0
typedef int BOOL;

void CircularBuffer_Create(int bufferSize);
void CircularBuffer_Destroy(void);

int CircularBuffer_GetCapacity(void);
int CircularBuffer_GetSize(void);
int CircularBuffer_Read(void);
void CircularBuffer_Add(int item);
int CircularBuffer_Remove(void);

/* Check state */
BOOL CircularBuffer_IsEmpty(void);
BOOL CircularBuffer_IsFull(void);

#endif  /* D_CircularBuffer_H */
