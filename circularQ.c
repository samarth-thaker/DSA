#include <stdio.h>
#define MAX_SIZE 5

// Structure to represent a circular queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to add an element to the circular queue
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Circular queue is full. Cannot enqueue element.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->items[queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to remove an element from the circular queue
void dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty. Cannot dequeue element.\n");
    } else if (queue->front == queue->rear) {
        printf("Dequeued %d\n", queue->items[queue->front]);
        queue->front = -1;
        queue->rear = -1;
    } else {
        printf("Dequeued %d\n", queue->items[queue->front]);
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

// Function to display the elements in the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Circular queue elements: ");
        while (i != queue->rear) {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    CircularQueue queue;
    queue.front = -1;
    queue.rear = -1;

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5); // The circular queue is now full.

    display(&queue); // Output: Circular queue elements: 1 2 3 4 5

    dequeue(&queue);
    dequeue(&queue);

    display(&queue); // Output: Circular queue elements: 3 4 5

    enqueue(&queue, 6);
    enqueue(&queue, 7); // The circular queue is now full.

    display(&queue); // Output: Circular queue elements: 3 4 5 6 7

    return 0;
}
