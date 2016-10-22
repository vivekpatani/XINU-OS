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

		return OK;
	}

	// Else if the flag is QUEUE
	else if (f->flag == 3) {

		return OK;
	}

	//Else there is an ERR
	return SYSERR;
}