
#include "stack,Q.h"
# define NULLPTR  (void*)0

/********************************/
/// Stack
/********************************/

static int stack[STACK_SIZE];
static int sp=0;  // our starting from zero


/********************************/

stack_t* stack_create (int size)
{

    stack_t* Pstack = malloc(sizeof(stack_t));  // pointer with size stack_t
    Pstack->dataArray = malloc (size * sizeof(int));   // array of size
    Pstack->sp = 0; // initialize sp to 0
    Pstack->StackSize = size;

    return Pstack;

}



/********************************/

void stack_delete (stack_t* stack)
{
    free (stack->dataArray);   // must delete the arr 1st as it's not in the stack - only its address - so if stack deleted 1st - we can't reach the arr
    free(stack);
}


/********************************/

stack_status push (stack_t* Pstack, int data)
{
    stack_status status = DONE;

    if (Pstack == NULLPTR )
    {
        printf("stack not created\n");
        return;
    }


    if (Pstack->sp==Pstack->StackSize)
    {
        status = STACK_FULL;
    }

    else
    {
        Pstack->dataArray[Pstack->sp]=data;
        Pstack->sp ++;

    }

    return status;
}


/********************************/

stack_status pop (stack_t* Pstack, int* p_data)
{
    stack_status status = DONE;

    if (Pstack == NULLPTR )
    {
        printf("stack not created\n");
        return;
    }


    if (Pstack->sp==0)
    {
        status = STACK_EMPTY;
    }

    else
    {
        *p_data = Pstack->dataArray[Pstack->sp];   //popped and stored somewhere else outside the stack - but can be overwritten in stack
        Pstack->sp --;

    }

    return status;
}

/********************************/
/// Circular Queue
/********************************/


static int queue[QUEUE_SIZE];
static int in=0;  // our starting from zero
static int out=0;  // our starting from zero
static int circular_flag=0;  // starts at empty =0 // 1 = full // only 2 values


/********************************/

queue_status inqueue (int data)
{
    queue_status status = Q_DONE;

    if (in==out && circular_flag==1)
    {
        status = Q_FULL;
    }

    else
    {
        queue[in]=data;
        in++;
    }


    if (in==QUEUE_SIZE)  // must be after not before - session 29 last page notebook
    {
        in=0;
        circular_flag=1;
    }

    return status;
}


/********************************/

queue_status dequeue (int* p_data)
{
    queue_status status = Q_DONE;

    if (out==QUEUE_SIZE)  // must be after not before - session 29 last page notebook
    {
        out=0;
        circular_flag=0;
    }


    if (in==out && circular_flag==0)
    {
        status = Q_EMPTY;
    }

    else
    {
        *p_data = queue[out];
        out++;               // unlike stack pop -- sp--;
    }


    return status;
}

/********************************/
/// Ordinary Queue
/********************************/

/********************************/

queue_status inqueue_not_circular (int data)
{
    queue_status status = Q_DONE;

    if (in==out && in==QUEUE_SIZE)  // refresh queue
    {
        in=0;
        out=0;
    }

    if (in==QUEUE_SIZE)
    {
        status = Q_FULL;
    }

    else
    {
        queue[in]=data;
        in++;
    }


    return status;
}


/********************************/

queue_status dequeue_not_circular (int* p_data)
{
    queue_status status = Q_DONE;

    if (in==out && out==QUEUE_SIZE)  //refresh Queue
    {
        out=0;
        in=0;
    }

    if (out==QUEUE_SIZE)  // must be after not before - session 29 last page notebook
    {
        status = Q_EMPTY;
    }


    else
    {
        *p_data = queue[out];
        out++;               // unlike stack pop -- sp--;
    }


    return status;
}



/********************************/
/// Old alternative stack codes
/********************************


stack_t stack_create (int size)  // only array in the stack is dynamically allocated  // returns struct of stack type
{

stack_t stack;
stack.dataArray = malloc (size * sizeof(int));   // array of size
stack.sp = 0; // initialize sp to 0
stack.StackSize = size;

return stack;
}



/********************************

void stack_delete (stack_t stack)  // only can delete the array inside the stack
{
 free (stack.dataArray);

}


/********************************

stack_status push (int data)
{
    stack_status status = DONE;

    if (sp==STACK_SIZE)
    {
       status = STACK_FULL;
    }

    else
    {
        stack[sp]=data;
        sp++;

    }

    return status;
}


/********************************

stack_status pop (int* p_data)
{
    stack_status status = DONE;

    if (sp==0)
    {
       status = STACK_EMPTY;
    }

    else
    {
        *p_data = stack[sp];   //popped and stored somewhere else outside the stack - but can be overwritten in stack
         sp--;

    }

    return status;
}

********************************/
