#include "queue.h"
#include "list.h"
#include <stdio.h>

IntQueue *IntQueue_new(void){

    return IntList_new();

}

int IntQueue_enqueue(IntQueue *queue, int value){
    IntListPos start_pos = IntList_front(queue);
    if(IntList_insert(queue, start_pos, value) == NULL){
            return 0;
    }
    return 1;
}


int IntQueue_dequeue(IntQueue *queue){

    if ( IntQueue_empty(queue)== 1){
        return 0;
    }

    IntListPos back_pos =  IntList_back(queue);
    IntList_remove(queue, back_pos);
    return 1;
}


void IntQueue_delete(IntQueue *queue){
    IntList_delete(queue);
}


int IntQueue_empty(IntQueue *queue){
    IntList_empty(queue);
}
