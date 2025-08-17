#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SLOTS 5
#define MAX_QUEUE 5
#define PLATE_SIZE 20

// --------- Linked List for Parking car ---------
typedef struct car {
    char plate[PLATE_SIZE];
    struct car* next;
} car;

car* car_head = NULL;

void addcar(const char* plate) {
    car* newcar = (car*)malloc(sizeof(car));
    strcpy(newcar->plate, plate);
    newcar->next = car_head;
    car_head = newcar;
}

void printcar() {
    car* temp = car_head;
    printf("Parked car history:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->plate);
        temp = temp->next;
    }
}

// --------- Stack for Temporary Holding ---------
char tempStack[MAX_SLOTS][PLATE_SIZE];
int stackTop = -1;

void pushTemp(const char* plate) {
    if (stackTop < MAX_SLOTS - 1) {
        stackTop++;
        strcpy(tempStack[stackTop], plate);
    }
}

char* popTemp() {
    if (stackTop >= 0)
        return tempStack[stackTop--];
    return NULL;
}

// --------- Queue for Waiting Vehicles ---------
char queue[MAX_QUEUE][PLATE_SIZE];
int front= 0, rear= -1, QueueCount= 0;

void enqueue(const char* plate) {
    if (QueueCount < MAX_QUEUE) {
        rear = (rear + 1) % MAX_QUEUE;
        strcpy(queue[rear], plate);
        QueueCount++;
    } else {
        printf("Waiting queue full! Cannot enqueue %s\n", plate);
    }
}

char* dequeue() {
    static char plateCopy [PLATE_SIZE]; // static to persist after function returns
    if (QueueCount > 0) {
        strcpy(plateCopy, queue[front]);
        front = (front + 1) % MAX_QUEUE;
        QueueCount--;
        return plateCopy;
    }
    return NULL;
}



void displayQueue() {
    printf("Waiting Queue:\n");
    for ( int i = 0; i < QueueCount ; i++ ) {
        int idx = (front + i) % MAX_QUEUE;
        printf("- %s\n", queue[idx]);
    }
}

// --------- Array for Parking Garage ---------
char garage[MAX_SLOTS] [PLATE_SIZE];
int parked= 0;

// Park a car
void parkCar() {
    char plate[PLATE_SIZE];
    printf("Enter plate number: ");
    scanf("%s", plate);

    if (parked < MAX_SLOTS) {
        strcpy(garage[parked], plate);
        parked++;
        printf("Vehicle %s has been parked at: %d\n", plate, parked);
        addcar(plate);
    } else {
        printf("Garage full. Adding %s to waiting queue. \n", plate);
        enqueue(plate);
    }
}

// Remove a car
void removeCar() {
    char plate[PLATE_SIZE];
    printf("Enter plate number to remove:");
    scanf("%s", plate);

    int found = -1;
    for (int i = 0; i < parked; i++) {
        if (strcmp(garage[i], plate ) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Vehicle not found.\n");
        return;
    }

    // Temporarily remove cars above
    for (int i = parked - 1; i > found; i--) {
        pushTemp(garage[i]);
    }

    printf("Removing vehicle %s from slot %d\n", plate, found ++);
    parked = found;  // Car and above are removed

    // Restore cars from temp stack
    while (stackTop >= 0) {
        strcpy(garage[parked], popTemp());
        parked++;
    }

    // Add car from queue if any
    if (QueueCount > 0) {
        char* nextCar = dequeue();
        strcpy(garage[parked], nextCar);
        printf("Vehicle %s from queue parked in slot %d\n", nextCar, parked ++);
        addcar(nextCar);
        parked++;
    }
}

// Display garage
void displayGarage() {
    printf("\nGarage Slots:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (i < parked)
            printf("Slot %d: %s \n", i + 1, garage[i]);
        else
            printf("Slot %d: Empty\n", i + 1);
    }
}

// --------- Main Menu ---------
int main() {
    int choice;

    while (1) {
        printf("\n--- Parking Garage System ---\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Garage\n");
        printf("4. Display Waiting Queue\n");
        printf("5. Show Parking History car\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: parkCar(); break;
            case 2: removeCar(); break;
            case 3: displayGarage(); break;
            case 4: displayQueue(); break;
            case 5: printcar(); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
