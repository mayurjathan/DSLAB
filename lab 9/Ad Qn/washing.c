#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Structure to represent a booking node
struct Booking {
    int bookingID;
    int duration;
    struct Booking* next;
    struct Booking* prev;
};

typedef struct Booking* BookingPtr;

// Function to create a new booking node
BookingPtr createBooking(int bookingID, int duration) {
    BookingPtr newBooking = (BookingPtr)malloc(sizeof(struct Booking));
    newBooking->bookingID = bookingID;
    newBooking->duration = duration;
    newBooking->next = newBooking->prev = NULL;
    return newBooking;
}

// Function to add a booking to the queue
void enqueueBooking(BookingPtr* head, int bookingID, int duration) {
    BookingPtr newBooking = createBooking(bookingID, duration);
    if (*head == NULL) {
        *head = newBooking;
        newBooking->next = newBooking->prev = newBooking;
    } else {
        BookingPtr tail = (*head)->prev;
        newBooking->next = *head;
        newBooking->prev = tail;
        tail->next = newBooking;
        (*head)->prev = newBooking;
    }
}

// Function to remove and return the next booking from the queue
BookingPtr dequeueBooking(BookingPtr* head) {
    if (*head == NULL) {
        return NULL; // No bookings in the queue
    }

    BookingPtr currentBooking = *head;

    if (currentBooking->next == currentBooking) {
        *head = NULL; // Last booking in the queue
    } else {
        *head = currentBooking->next;
        currentBooking->prev->next = currentBooking->next;
        currentBooking->next->prev = currentBooking->prev;
    }

    return currentBooking;
}

// Function to simulate time passing and handle bookings
void simulateTime(BookingPtr* head, int currentTime) {
    if (*head == NULL) {
        printf("No bookings in the queue.\n");
        return;
    }

    BookingPtr currentBooking = *head;
    if (currentBooking->duration <= currentTime) {
        *head = currentBooking->next;
        free(currentBooking);
        printf("Booking completed and removed from the queue.\n");
    } else {
        printf("Currently booked by ID %d for %d minutes.\n", currentBooking->bookingID, currentBooking->duration - currentTime);
    }
}

int main() {
    BookingPtr bookingQueue = NULL;
    int bookingID = 1;
    int currentTime = 0;
    int choice;

    while (1) {
        printf("1. Book a washing machine\n");
        printf("2. Simulate time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int duration;
            printf("Enter the duration (in minutes): ");
            scanf("%d", &duration);
            enqueueBooking(&bookingQueue, bookingID++, duration);
            printf("Booking added to the queue.\n");
        } else if (choice == 2) {
            simulateTime(&bookingQueue, currentTime);
            currentTime += 5; // Simulate time passing in 5-minute intervals
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Clean up any remaining bookings in the queue
    while (bookingQueue != NULL) {
        BookingPtr completedBooking = dequeueBooking(&bookingQueue);
        free(completedBooking);
    }

    return 0;
}
