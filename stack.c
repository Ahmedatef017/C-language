
#include "stack.h"

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

stack_status pop (int* p_data)
{
    stack_status status = DONE;

    if (sp==0)
    {
       status = STACK_EMPTY;
    }

    else
    {
        *p_data = stack[sp];
         sp--;

    }

    return status;
}

/********************************/
