#include <stdio.h>
#include <stdlib.h>

// Backjoon https://www.acmicpc.net/problem/1021

void print(int *queue, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void setQueue(int *queue, int size) {
    for (int i = 0; i < size; i++) {
        queue[i] = i + 1;
    }
}

void pullElement(int *queue, int *size) {
    for (int i = 0; i < *size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    (*size)--;
}

void moveLeft(int *queue, int size) {
    int tmp = queue[0];
    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    queue[size - 1] = tmp;
}

void moveRight(int *queue, int size) {
    int tmp = queue[size - 1];
    for (int i = size - 1; i > 0; i--) {
        queue[i] = queue[i - 1];
    }
    queue[0] = tmp;
}

int countMin(int *queue, int *size, int target) {
    int left = 0, right = 0;

    int position = 0;
    for (int i = 0; i < *size; i++) {
        if (queue[i] == target) {
            position = i;
            break;
        }
    }

    left = position;        
    right = *size - position;

    if (left <= right) {
        for (int i = 0; i < left; i++) moveLeft(queue, *size);
        pullElement(queue, size);
        return left;
    } else {
        for (int i = 0; i < right; i++) moveRight(queue, *size);
        pullElement(queue, size);
        return right;
    }
}

int main(void) {
    int size, num, count = 0;

    scanf("%d %d", &size, &num);

    int *queue = malloc(sizeof(int) * size);
    int *location = malloc(sizeof(int) * num);

    setQueue(queue, size);

    for (int i = 0; i < num; i++) {
        scanf("%d", &location[i]);
    }

    for (int i = 0; i < num; i++) {
        count += countMin(queue, &size, location[i]);
    }

    printf("%d\n", count); 

    free(queue);
    free(location);
    return 0;
}