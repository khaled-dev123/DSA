// Operations on Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // exit if malloc fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count the number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Create nodes
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Print the linked list
    printf("Linked List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Count the number of nodes
    int total = countNodes(head);
    printf("Number of nodes in the list: %d\n", total);

    // Free allocated memory
    current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
        printf("Freed a node\n");
    }

    printf("All nodes freed. The list is now empty.\n");
    return 0;
}
