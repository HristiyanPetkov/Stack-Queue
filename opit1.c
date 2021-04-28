#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int val;
    struct queue *next;
} Queue;

int Enqueue(Queue**, int);
int Dequeue(Queue**);
int peek(Queue*);

int main(){
    Queue* head = NULL;

    printf("%d\n", Enqueue(&head, 1));
    printf("%d\n", Enqueue(&head, 3));
    printf("%d\n", Dequeue(&head));
    printf("%d\n", Enqueue(&head, 7));
    printf("%d\n", peek(head));
    printf("%d\n", Dequeue(&head));
    printf("%d\n", Dequeue(&head));
}

int Enqueue(Queue** head, int val){
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->val = val;
    temp->next = (*head);
    (*head) = temp;

    return val;
}

int Dequeue(Queue** head) {
    Queue* dequeued = (Queue *)malloc(sizeof(Queue));
    Queue* previous = (Queue *)malloc(sizeof(Queue));
    dequeued = *head;
    int retval = -1;

    while(dequeued->next != NULL){
        previous = dequeued;
        dequeued = dequeued->next;
    }

    retval = dequeued->val;
    free(dequeued);

    if(previous != NULL) {
        previous->next = NULL;
    } else {
        *head = NULL;
    }

    return retval;
}

int peek(Queue* head) {
    while(head->next){
        head = head->next;
    }
    return head->val;
}
