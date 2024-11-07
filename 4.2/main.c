#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int priority;
    int data;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

PriorityQueue* createQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->head = NULL;
    return queue;
}

void enqueue(PriorityQueue* queue, int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (queue->head == NULL || queue->head->priority > priority) {
        newNode->next = queue->head;
        queue->head = newNode;
    } else {
        Node* current = queue->head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(PriorityQueue* queue) {
    if (queue->head == NULL) {
        printf("Очередь пуста!\n");
        return -1; 
    }
    Node* temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    free(temp);
    return data;
}

int dequeueWithPriority(PriorityQueue* queue, int priority) {
    Node* current = queue->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->priority == priority) {
            if (prev == NULL) {
                queue->head = current->next;
            } else {
                prev->next = current->next;
            }
            int data = current->data;
            free(current);
            return data;
        }
        prev = current;
        current = current->next;
    }
    printf("Элемент с приоритетом %d не найден!\n", priority);
    return -1;
}

int dequeueWithMinPriority(PriorityQueue* queue, int minPriority) {
    Node* current = queue->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->priority >= minPriority) {
            if (prev == NULL) {
                queue->head = current->next;
            } else {
                prev->next = current->next;
            }
            int data = current->data;
            free(current);
            return data;
        }
        prev = current;
        current = current->next;
    }
    printf("Элементы с приоритетом не ниже %d не найдены!\n", minPriority);
    return -1;
}

void freeQueue(PriorityQueue* queue) {
    Node* current = queue->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main() {
    PriorityQueue* queue = createQueue();

    enqueue(queue, 10, 5);
    enqueue(queue, 20, 1);
    enqueue(queue, 30, 3);
    enqueue(queue, 40, 2);
    enqueue(queue, 50, 0);

    printf("Извлечение с наивысшим приоритетом: %d\n", dequeue(queue));
    printf("Извлечение элемента с приоритетом 3: %d\n", dequeueWithPriority(queue, 3));
    printf("Извлечение элемента с приоритетом не ниже 2: %d\n", dequeueWithMinPriority(queue, 2));

    freeQueue(queue);

    return 0;
}
