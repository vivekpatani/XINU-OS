#include<xinu.h>
#include<future.h>
syscall future_set(future *f, int *value{

if((*f).flag==FUTURE_EXCLUSIVE)//subsequent calls will throw SYSERR
{
  if((*f).pid!=(pid32)getpid()){
  return SYSERR;
  }
}


if((*f).state==FUTURE_EMPTY)//changes the state from FUTURE_EMPTY to FUTURE_WAITING
{  
   (*f).value = value;//sets the future value
   (*f).state=FUTURE_VALID;
}

return OK;
}
