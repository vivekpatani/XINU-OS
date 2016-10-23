#include <xinu.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*------------------------------------------------------------------------
 *  Enqueue  -  Insert a process at the tail of a queue.
 *------------------------------------------------------------------------
 */
void Enqueue (queue* q, pid32 process_id) {
	
	// Assigning Space to the Node.
	struct Node* temp = 
	(struct Node*)getmem(sizeof(struct Node));

	// Setting up references
	temp->process_id = process_id;
	temp->next = NULL;

	// Handling new queue references
	if (q->front == NULL || q->rear == NULL) {
		q->front = q->rear = temp;
	} else {
		q->rear->next = temp;
		q->rear = temp;
	}
}

/*------------------------------------------------------------------------
 *  dequeue  -  Remove and return the first process on the queue
 *------------------------------------------------------------------------
 */
pid32 Dequeue (queue* q) {

	struct Node* temp = q->front;
	pid32 retVal = -1;
	// If Front is null, queue is empty
	if (q->front == NULL) {
		return retVal;
	}

	// If there is only one element.
	if (q->front == q->rear) {
		retVal = q->front->process_id;
		q->front = q->rear = NULL;
		return retVal;
	}

	// Remove the element at the front of the queue.
	retVal = q->front->process_id;
	temp = temp->next;

	q->front = temp;

	return retVal;
}

/*------------------------------------------------------------------------
 *  Print  -  Print the complete Queue.
 *------------------------------------------------------------------------
 */
void Print(queue* q) {
	struct Node* temp = q->front;
	while (temp != NULL) {
		printf("%d ", temp->process_id);
		temp = temp->next;
	}
	printf("\n");
}

/*------------------------------------------------------------------------
 *  IsEmpty  -  Returns a boolean telling whether if it is empty or not.
 *------------------------------------------------------------------------
 */
 bool IsEmpty(queue* q) {

 	if (q->front == NULL) {
 		return TRUE;
 	}
 	return FALSE;
 }