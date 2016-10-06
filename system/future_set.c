#include<xinu.h>
#include<future.h>

syscall future_set(future *f, int *value) {
	
	if ((*f).state == FUTURE_EMPTY && (*f).pid == -1) {//changes the state from FUTURE_EMPTY to FUTURE_WAITING
		(*f).pid = getpid();
		(*f).value = value; //sets the future value
		(*f).state = FUTURE_VALID;
		printf("%d\n",(*f).pid);
		printf("Value: %d\n",*((*f).value));
		return OK;
	} else if ((*f).state == FUTURE_EMPTY) {
		(*f).value = value;
		(*f).state = FUTURE_VALID;
		resume((*f).pid);
		return OK;
	} else {
		return SYSERR;
	}
	return SYSERR;
}