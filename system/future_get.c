nclude<xinu.h>
#include<future.h>
int future_exclusive(future *f, int *value);

syscall future_get(future *f, int *value) {
	int status;
	status = future_exclusive(f,value);
	if (status == SYSERR) return SYSERR;
	else return OK;
}

int future_exclusive(future *f, int *value) {

	if((*f).pid == -1) (*f).pid = (pid32) getpid(); //first call to future_get function

	if((*f).flag == FUTURE_EXCLUSIVE) //subsequent calls will throw SYSERR
  		if((*f).pid != (pid32) getpid())
  			return SYSERR;

	if((*f).state == FUTURE_EMPTY) (*f).state = FUTURE_WAITING; //changes the state from FUTURE_EMPTY to FUTURE_WAITING

	value = (*f).value;
	return OK;
}
