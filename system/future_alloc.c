#include <xinu.h>

/* Allocates Memory for the Future */
future* future_alloc(int future_flag){
	future *f = (future *)getmem(sizeof(future));
	f->flag = future_flag ;
	f->state = FUTURE_EMPTY;
	f->pid = -1;
	f->value = NULL;

	// Assigning Space for both Queues
	f->get_queue = (queue*)getmem(sizeof(queue));
	f->set_queue = (queue*)getmem(sizeof(queue));

	// Initialising references for get Queue
	f->get_queue->front = NULL;
	f->get_queue->rear = NULL;

	// Intitialising Space for set Queue
	f->set_queue->front = NULL;
	f->set_queue->rear = NULL;
	return f;
}