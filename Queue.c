#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_PATH "C:\\Users\\HR\\Desktop\\Dumi.txt"

typedef struct node_q {
    int val;
    struct node_q * next;
} NODE_Q;

int Enqueue(NODE_Q** queue_t, int val);
int Dequeue(NODE_Q** queue_t);
int peek(NODE_Q* queue_t);

int main() {
    NODE_Q* queue = NULL;

    FILE* fp;

    fp = fopen(FILE_PATH, "r");

    char* operation;
    int number;

    while(fscanf(fp, "%s", operation) != EOF) {
        if (strcmp(operation, "PUSH") == 0) {
            fscanf(fp, "%d", &number);
            printf("%d\n", Enqueue(&queue, number));
        } else if (strcmp(operation, "POP") == 0) {
            printf("%d\n", Dequeue(&queue));
        } else if (strcmp(operation, "PEEK") == 0) {
            printf("%d\n", peek(queue));
        }
    }

    fclose(fp);

    return 0;
}

int Enqueue(NODE_Q** queue_t, int val) {
    NODE_Q* temp = *queue_t;
    NODE_Q* new_val = (NODE_Q*)malloc(sizeof(NODE_Q));
    new_val->val = val;
    new_val->next = NULL;

    if(*queue_t == NULL) {
        *queue_t = new_val;
        return val;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_val;

    return val;
}

int Dequeue(NODE_Q** queue_t) {
    NODE_Q* temp = *queue_t;
    int retval = temp->val;
    *queue_t = (*queue_t)->next;
    free(temp);

    return retval;
}

int peek(NODE_Q* queue_t) {
    return queue_t->val;
}
