
/// Linked list Funcs

#include "list.h"

/********************************/

node_t* list_create_new_node (int data) // create a node not connected to any list
// not used on main - addtolast bt3ml kol 7aga
{
    node_t* new_node = malloc (sizeof(node_t));  // a full node allocated dynamically
    if (new_node==NULLPTR)
    {
        return 0 ;   // no place in heap
    }

    new_node->data = data;
    new_node->next=NULLPTR;
    return new_node;    // return address of a new node to be saved in head of a list

}


/********************************/

void list_print (node_t* head)
{
    node_t* current = head;

     printf("==========\n");

    while(current!=0) // as we want to print data in the last node - also if empty won't print
    {
        printf("%4d\n",current->data);
        current=current->next;   // like i++ in arrays
    }
    printf("==========\n");
}

/********************************/

void list_addNodeToLast (node_t** phead, int data)   // we send ptr to ptr head - as we may edit head itself if the list is empty
{
    node_t* new_node = list_create_new_node(data); // new not connected node created
    node_t* current = *phead;               // *phead here is a ptr

    if (*phead==0) // nullptr - empty list
    {
        *phead - new_node;
        return;
    }

    while (current->next!=0) // we will edit the "next" not the current (local variable) - loop to reach the last node of the list to put the new after it
    {
        current=current->next;  // incrementing
    }

    current->next=new_node;   // we now assigned the new node to next of the last node .. now it's not the last node

}

/********************************/

int list_editByData (node_t* head, int old_data, int new_data)   // head won't be edited - takes an old data and edits it
{
    int status=0;
    node_t* current = head;

    if (head==0)
    {
        return -1;    // empty list - not edited
    }

    while (current!=0) // we search for data till the last node - so (current!=0)
    {
        if (current->data==old_data)
        {
            current->data==new_data;
            status=1;          // found & edited successfully
        }

        current=current->next;  // runtime error if not written

    }

    return status ;  // if =0 , not found & not edited
}

/********************************/

void list_addNodeToFirst (node_t** phead, int data)  // node added after head everytime
{
    node_t* new_node = list_create_new_node(data);  // new list created

    new_node->next = *phead ;  // next in new node take the addr that was in head

    *phead = new_node;       // head took addr of new node to be the 1st

}

/********************************/

void list_removeByData (node_t** phead, int old_data)   // takes a data in a node - deletes a whole node
{
    if (*phead == NULLPTR)
    {
        return ; // empty
    }

    node_t* current = *phead;
    node_t* temp;

    if (current->data==old_data)  // if the node is the 1st in the list
    {
        temp=current;
        *phead=current->next; // now the node is not in the list
        free(temp);          // now node deleted from heap
        return;
    }

    while (current->next!=0) // deleting is by addr - so no need to reach last node by current
    {

        if (current->next->data==old_data) // starting from 2nd node
        {
            temp=current->next;   // not only = current

            current->next=current->next->next; // VIP - now the node before the one to be removed - points to the node after the one to be removed
            // so the node is removed from list

            free(temp);    // node deleted from heap

            return;  // removal happens 1 time - if you want to delete all nodes include the old_data - remove "return"
        }

        current=current->next;
    }

}



/********************************/
///         Tasks

///     Insert by 3 ways
/********************************/

int list_insertAfter (node_t** phead, int old_data, int new_data)    // returns status
{
    if (*phead==NULLPTR)
    {
        return EMPTY;          // no nodes in here - so no old data to search for
    }

    node_t* new_node = list_create_new_node(new_data);
    node_t* current = *phead;

    if (current->data==old_data)  // if after 1st node in list
    {
        new_node->next = current->next;  // el trtib mohem hena
        current->next = new_node;

        return SUCCESS;         // succeeded
    }

    while(current->next!=0) // we will edit next   // loop from 2nd node to last node
    {
        if (current->next->data==old_data)
        {
            new_node->next = current->next->next;
            current->next->next=new_node;
            return SUCCESS;

        }

        current=current->next;
    }

    return NOT_FOUND;
}


/********************************/


int list_insertBefore (node_t** phead, int old_data, int new_data)    // returns status
{
    if (*phead==NULLPTR)
    {
        return EMPTY;          // no nodes in here - so no old data to search for
    }

    node_t* new_node = list_create_new_node(new_data);
    node_t* current = *phead;

    if (current->data==old_data)  // if after 1st node in list
    {
        new_node->next = *phead;  // el trtib mohem hena
        *phead=new_node;

        return SUCCESS;         // succeeded
    }

    while(current->next!=0) // we will edit next   // loop from 2nd node to last node
    {
        if (current->next->data==old_data)
        {
            new_node->next = current->next;
            current->next=new_node;
            return SUCCESS;

        }

        current=current->next;
    }

    return NOT_FOUND;
}


/********************************/

int list_insertByIndex (node_t** phead, int index, int data)    //considering 1st nodes index =1 ,, i is index that the node need to be put in
{
    if (index<1)
    {
        return FAILED;
    }


    node_t* new_node = list_create_new_node(data);
    node_t* current = *phead;
    int i;


    if (index==1)
    {
        new_node->next= *phead;
        *phead=new_node;
        return SUCCESS;
    }

    for (i=2 ; i<=index ; i++)   // current is at head now -- its index is zero -- you are 2 steps ahead of current
    {

        if (current==0)
        {
            return FAILED;  // index is larger than the list

        }

        if (i==index)
        {
            new_node->next = current->next;
            current->next=new_node;
            return SUCCESS;
        }

        current=current->next;
    }

    return NOT_FOUND;
}

/********************************/
///     Stack & Queue
/********************************/

void push2 (node_t** phead, int data)  //same function as add to last
{

    node_t* new_node = list_create_new_node(data);

    new_node->next = *phead ;

    *phead = new_node;
}


/********************************/

int pop2 (node_t** phead, int* pdata)
{

    if (*phead == NULLPTR )
    {
        return EMPTY;  // empty stack
    }

    node_t* current = *phead;

    *pdata= current->data;

    *phead=(*(phead))->next;


    free(current); // current already is addr of 1st node (the popped one)

    return SUCCESS;
}



/********************************/

void inqueue2 (node_t** phead, int data)    // same as add to the first
{
    node_t* new_node = list_create_new_node(data);

    new_node->next = *phead ;

    *phead = new_node;
}

/********************************/

int dequeue2 (node_t** phead, int* pdata)
{
    if (*phead == NULLPTR )
    {
        return EMPTY;  // empty stack
    }


    node_t* before_tail=*phead;

    while (before_tail->next->next!=0)
    {
        before_tail=before_tail->next;
    }


    *pdata= before_tail->next->data;

    free(before_tail->next); // node deleted

    before_tail->next = NULLPTR;


    return SUCCESS;
}

/********************************/
///      Task (3)
/********************************

void list_reverse (node_t** phead)
{
 node_t* current = *phead;
 int flag=0;


 while (current!=0)
 {
  current=current->next;

  if (flag==0) // 1st node only
 {
  current->next == NULLPTR;
  flag++;
 }

  *phead=current;
 }

}

/********************************

void list_print_reversed (node_t* head)
{
    node_t* current = head;

     printf("==========\n");

    while(current!=0) // as we want to print data in the last node - also if empty won't print
    {
        printf("%4d\n",current->data);
        current=current->next;   // like i++ in arrays
    }
    printf("==========\n");
}


********************************/



