#include <stdio.h>
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int mutex = 1;
int empty = BUFFER_SIZE;
int full = 0;

void produce() {
    if (empty == 0) {
        printf("\nBuffer is FULL. Producer waiting...");
        return;
    }

    mutex--;
    empty--;

    int item;
    printf("\nEnter item to produce: ");
    scanf("%d", &item);

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;

    printf("Produced item: %d", item);

    mutex++;
    full++;
}

void consume() {
    if (full == 0) {
        printf("\nBuffer is EMPTY. Consumer waiting...");
        return;
    }

    mutex--;
    full--;

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    printf("\nConsumed item: %d", item);

    mutex++;
    empty++;
}

int main() {
    int choice;
    while (1) {
        printf("\n\n--- Producer Consumer Problem ---");
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: produce(); break;
            case 2: consume(); break;
            case 3: return 0;
            default: printf("Invalid choice!");
        }
    }
}
