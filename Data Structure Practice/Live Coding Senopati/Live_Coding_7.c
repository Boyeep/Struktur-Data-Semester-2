#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int main() {
    int n;
    scanf("%d", &n);
    
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = tail;
        
        if (tail != NULL) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        
        tail = newNode;
    }
    
    int sum = 0;
    Node* current = head;
    
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    
    double avg = (double)sum / n;
    
    printf("%.2lf\n", avg);
    
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;