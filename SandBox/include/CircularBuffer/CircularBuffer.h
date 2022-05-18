/*- ------------------------------------------------------------------ -*/
/*- Author: ehenriqu                                                   -*/
/*- Description: Sandbox file for CircularBuffer module created for    -*/
/*-              TDD end-of-chapter problems.                          -*/
/*- ------------------------------------------------------------------ -*/

#ifndef D_CircularBuffer_H
#define D_CircularBuffer_H

void CircularBuffer_Create(int bufferSize);
void CircularBuffer_Destroy(void);

int CircularBuffer_GetCapacity(void);
int CircularBuffer_Read(void);
void CircularBuffer_Add(int item);
int CircularBuffer_Remove(void);

#endif  /* D_CircularBuffer_H */
