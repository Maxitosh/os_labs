#include <stdio.h>
#include <stdlib.h>

struct LL {
    int data;
    struct LL *next;
};

typedef struct LL *node;
int listLength = 0;
node head;

node createNode(int data) {
    node temp;
    temp = (node) malloc(sizeof(struct LL));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void print_list() {
    node temp = head;
    while (temp != NULL) {
        printf("Node value: %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(int data) {
    node temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node newNode = createNode(data);
    temp->next = newNode;
    listLength++;
}

int delete_node(int pos, struct LL **list) {
    if (pos > listLength || pos < 0) {
        return -1;
    }

    struct LL* temp = *list;
    for (int i = 0; i < pos - 1; ++i) {
        temp = temp->next;
    }
    struct LL* after = temp->next->next;
    struct LL* before = temp;
    int value = temp->next->data;
    free(temp->next);
    before->next = after;

    listLength--;
    return value;
}

int main() {
    head = createNode(0);

    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);

    print_list();

    printf("Delete element on pos 2!\n");
    delete_node(2, &head);
    print_list();

    printf("Delete element on pos 1!\n");
    delete_node(1, &head);
    print_list();

    return 0;
}