#include<xinu.h>

/* Setting the value for a ceratin future */
syscall future_set(future *f, int *value) {

	// If flag is EXCLUSIVE
	if (f->flag == 1) {
		if (f->state == FUTURE_WAITING || f->state == FUTURE_EMPTY) {
			f->value = value;
			f->state = FUTURE_VALID;
			resume(f->pid);
			return OK;
		}
	}

	// Else if the flag is SHARED
	else if (f->flag == 2) {
		if (f->state == FUTURE_WAITING || f->state == FUTURE_EMPTY) {
			f->value = value;
			f->state = FUTURE_VALID;

			// Pop All the processes in the Get Queue
			while (!IsEmpty(f->get_queue)) {
				resume(Dequeue(f->get_queue));
			}

			future_free(f);
			return OK;
		}

		else if (f->state == FUTURE_VALID) {
			return SYSERR;
		}
	}

	// Else if the flag is QUEUE
	else if (f->flag == 3) {

		// If Get Queue is Not Empty
		if (!IsEmpty(f->get_queue)) {
			f->value = value;
			f->state = FUTURE_VALID;
			resume(Dequeue(f->get_queue));
		}

		// If Get Queue is Empty.
		else {
			Enqueue(f->set_queue, getpid());
			suspend(getpid());
			f->value = value;
			f->state = FUTURE_VALID;
		}

		return OK;
	}

	return SYSERR;
}
