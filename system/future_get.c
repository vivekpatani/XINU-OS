#include<xinu.h>

/* Get the value for the future, otherwise wait */
syscall future_get(future *f, int *value) {
	int status;

	// If Mode is exclusive
	if (f->flag == 1) {
		if (f->state == FUTURE_EMPTY) {
			f->state = FUTURE_WAITING;
			f->pid = getpid();
			suspend(f->pid);
			*value = f->value;
			return OK;
		}
	}
	return SYSERR;
}
