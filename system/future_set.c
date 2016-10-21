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
	return SYSERR;
}