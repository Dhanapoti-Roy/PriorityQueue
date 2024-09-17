#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node* next;
};

void insert(struct node** start, int item, int itemPrn) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = item;
    newNode->priority = itemPrn;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
        return;
    }
    if ((*start)->priority < itemPrn) {
        newNode->next = *start;
        *start = newNode;
        return;
    }
    struct node* save = *start;
    struct node* ptr = (*start)->next;

    while (ptr != NULL) {
        if (newNode->priority == itemPrn) {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        } else if (ptr->priority < itemPrn) {
            newNode->next = ptr;
            save->next = newNode;
            return;
        }
        save = ptr;
        ptr = ptr->next;
    }
    save->next = newNode;
}

void display(struct node* start) {
    struct node* temp = start;
    while (temp != NULL) {
        printf("%d   %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    struct node* start = NULL;
    insert(&start, 10, 3);
    insert(&start, 14, 6);
    insert(&start, 15, 5);
    insert(&start, 16, 2);

    display(start);

    // Clean up (free memory)
    while (start != NULL) {
        struct node* temp = start;
        start = start->next;
        free(temp);
    }

    return 0;
}
