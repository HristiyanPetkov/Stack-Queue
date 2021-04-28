#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILE_PATH "C:\\Users\\HR\\Desktop\\Dumi.txt"

typedef struct node {
    int val;
    struct node* next;
} NODE;

int push(NODE** steck, int val);
int pop(NODE** steck);
int peek(NODE* steck);

int main() {
    NODE* steck;

    FILE* fp;
    fp = fopen(FILE_PATH, "r");

    char* operation;
    int number;

    while(fscanf(fp, "%s", operation) != EOF) {
        if (strstr(operation, "PUSH")) {
            sscanf(operation, "%*[^0123456789]%d", &number);
            printf("%d\n", push(&steck, number));
        } else if (strstr(operation, "POP")) {
            printf("%d\n", pop(&steck));
        } else if (strstr(operation, "PEEK")) {
            printf("%d\n", peek(steck));
        }
    }

    fclose(fp);

    return 0;
}

int push(NODE** steck, int val) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->val = val;
    temp->next = (*steck);
    (*steck) = temp;

    return val;
}

int pop(NODE** steck) {
    int retval;

    NODE* popped = (*steck);
    (*steck) = popped->next;
    retval = popped->val;
    free(popped);

    return retval;
}

int peek(NODE* steck) {
    return steck->val;
}
