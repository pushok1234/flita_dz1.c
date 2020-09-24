#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct node{
    int value;
    struct node* next;
} n_node;

n_node* start = NULL;
n_node* end = NULL;
int length = 0;

n_node* create_node (int value){
    n_node* newnode = (n_node*)malloc(sizeof(n_node));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

void push(int value){
    n_node* tmp = create_node(value);
    if(length == 0){
        start = tmp;
        end = tmp;
    } else {
        start->next = tmp;
        start = tmp;
    }
    length++;
}

int pop(void){
    if (length == 0){
        printf("queue is empty\n");
        return NULL;
    } else {
        length--;
        n_node* tmp = end;
        int value = tmp->value;
        end = end->next;
        free(tmp);
        return value;
    }
}

int main(void) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("commands:\n");
    printf("i - input and push integer value\n");
    printf("o - output integer value\n");
    printf("l - length\n");
    printf("e - exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    char command;
    int value;
    while(true){
        printf("input command: ");
        scanf(" %c",&command);
        if (command == 'i'){
            printf("input: ");
            scanf("%d", &value);
            push(value);
        }
        if(command == 'o'){
            printf("output: %d\n", pop());
        }
        if(command == 'l'){
            printf("length: %d\n",length);
        }
        if (command == 'e'){
            return 0;
        }
    }
    return 0;
}
