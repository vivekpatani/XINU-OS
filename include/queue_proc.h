/* queue_proc.h */
#ifndef _QUEUE_PROC_H_
#define _QUEUE_PROC_H_
#include <xinu.h>

struct Node {
	pid32 process_id;
	struct Node* next;
};

typedef struct queue {
	struct Node* front;
	struct Node* rear;		
} queue;

void Enqueue (queue* , pid32);
pid32 Dequeue (queue*);
void Print(queue*);

#endif