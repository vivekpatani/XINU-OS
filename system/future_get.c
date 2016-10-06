#include<xinu.h>
#include<future.h>

syscall future_get(future *f, int *value) {
	int status;

	if ((*f).state == FUTURE_EMPTY && (*f).pid == -1) {
		(*f).state = FUTURE_WAITING;
		(*f).pid = getpid();
		suspend((*f).pid);
		*value = *(*f).value;
		return OK;

	} else if ((*f).state == FUTURE_EMPTY) {
		(*f).state = FUTURE_WAITING;
		suspend((*f).pid);
		*value = *(*f).value;
		return OK;
	} else if ((*f).state == FUTURE_VALID) {
		(*f).state = FUTURE_EMPTY;
		*value = *(*f).value;
		return OK;
	} else {
		return SYSERR;
	}
}
