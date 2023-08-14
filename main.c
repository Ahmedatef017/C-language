#include "list.h"

int main()
{

 node_t* l1=0,*l2=0;

 list_addNodeToLast(&l1,5);

 list_addNodeToLast(&l1,7);
list_addNodeToLast(&l1,9);
list_addNodeToLast(&l1,13);
list_addNodeToLast(&l1,130);
list_addNodeToLast(&l1,1300);
list_addNodeToLast(&l1,13000);

//list_print(l1);
//list_print(l2);
list_editByData(l1,130,100);

list_editByData(l1,13000,100);
list_addNodeToLast(&l2,20);
list_addNodeToLast(&l2,40);
list_addNodeToLast(&l2,60);
list_addNodeToLast(&l1,90);
//list_print(l2);
//list_print(l1);
list_addNodeToFirst(&l1,3);
list_addNodeToFirst(&l1,30);
list_print(l1);
list_removeByData(&l1,100);
list_print(l1);
list_removeByData(&l1,90);
list_removeByData(&l1,30);
list_print(l1);
    return 0;
}