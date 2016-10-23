#include<xinu.h>

/* Get the value for the future, otherwise wait */
syscall future_get(future *f, int *value) {
	int status;

	// If Mode is EXCLUSIVE
	if (f->flag == 1) {
		if (f->state == FUTURE_EMPTY) {
			f->state = FUTURE_WAITING;
			f->pid = getpid();
			suspend(f->pid);
			*value = f->value;
			return OK;
		}
	}

	// Else if Mode is SHARED
	else if (f->flag == 2) {

		if (f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING) {
			f->state = FUTURE_WAITING;
			// Enqueue all the incoming process.
			Enqueue(f->get_queue, getpid());
			suspend(getpid());
			*value = f->value;
			return OK;
		}
	}

	// Else if Mode is QUEUE
	 else if (f->flag == 3) {

	 	if (f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING) {

	 		//printf("Get Valud PID:%d\n",getpid());
	 		// If Set Queue is not Empty
	 		if (!IsEmpty(f->set_queue)) {
	 			resume(Dequeue(f->set_queue));
	 		}

	 		// If the Set Queue is Empty 
	 		else {
	 			Enqueue(f->get_queue, getpid());
	 			suspend(getpid());
	 		}
	 	}

	 	// If State is Valid, set Value
	 	if (f->state == FUTURE_VALID) {
	 		*value = f->value;
	 		f->state = FUTURE_EMPTY;
	 	} else {
	 		return SYSERR;
	 	}


	 	return OK;
	 }
	 // Else there is an ERR
	 return SYSERR;
}