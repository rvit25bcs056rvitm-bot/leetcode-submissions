#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int insInd;
    int delInd;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));

    queue->arr = malloc((k + 1) * sizeof(int));
    queue->insInd = 0;
    queue->delInd = 0;
    queue->size = k + 1;

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->insInd + 1) % obj->size == obj->delInd) {
        return false;
    }
    obj->arr[obj->insInd] = value;
    obj->insInd = (obj->insInd + 1) % obj->size;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->delInd == obj->insInd) {
        return false;
    }

    obj->delInd = (obj->delInd + 1) % obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->delInd == obj->insInd) {
        return -1;
    }

    return obj->arr[obj->delInd];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->delInd == obj->insInd) {
        return -1;
    }

    return obj->arr[(obj->insInd - 1 + obj->size) % obj->size];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->delInd == obj->insInd;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->insInd + 1) % obj->size == obj->delInd;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}
