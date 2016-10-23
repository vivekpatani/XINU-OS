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
			pid32 i = 4;

			// Pop All the processes in the Get Queue
			while (!IsEmpty(f->get_queue)) {
				resume(Dequeue(f->get_queue));
			}

			future_free(f);
			return OK;
		}

		else if (f->state == FUTURE_VALID) {
			printf("Error, Consecutive Set Call!\n");
			return SYSERR;
		}
	}

	// Else if the flag is QUEUE
	else if (f->flag == 3) {
                 if(f->state == FUTURE_EMPTY || f->state == FUTURE_WAITING){
                  f->state = FUTURE_WAITING;
                 if(IsEmpty(f->get_queue))
                {
                  Enqueue(f->set_queue,f->pid);
                }
                 else if(!IsEmpty(f->get_queue))
                   {
                      f->value = value;
                      resume( Dequeue(f->get_queue));
                  }
                return OK;
             }

	}
	return SYSERR;
}
