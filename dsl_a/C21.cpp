#include <iostream>
#include <iomanip>
#include <algorithm>

struct Appointment {
    int startTime; // in minutes
    int endTime;   // in minutes
    bool isBooked;
    Appointment* prev;
    Appointment* next;

    // Constructor to initialize an appointment with default values
    Appointment() : startTime(0), endTime(0), isBooked(false), prev(nullptr), next(nullptr) {}
};

class AppointmentScheduler {
private:
    Appointment* head;

public:
    // Constructor to initialize an empty schedule
    AppointmentScheduler() : head(nullptr) {}

    // Function to display free slots
    void displayFreeSlots() {
        Appointment* current = head;
        std::cout << "Free Slots:\n";
        while (current) {
            if (!current->isBooked) {
                std::cout << std::setw(5) << current->startTime << " - " << std::setw(5) << current->endTime << "\n";
            }
            current = current->next;
        }
        std::cout << "\n";
    }

    // Function to book an appointment
    void bookAppointment(int startTime, int endTime) {
        Appointment* current = head;

        // Find the appropriate slot for the appointment
        while (current) {
            if (!current->isBooked && current->startTime <= startTime && current->endTime >= endTime) {
                // Book the appointment
                current->isBooked = true;
                std::cout << "Appointment booked from " << current->startTime << " to " << current->endTime << "\n";
                return;
            }
            current = current->next;
        }

        // If no suitable slot is found
        std::cout << "No available slot for the given time range.\n";
    }

    // Function to cancel an appointment
    void cancelAppointment(int startTime, int endTime) {
        Appointment* current = head;

        // Find the appointment to cancel
        while (current) {
            if (current->isBooked && current->startTime == startTime && current->endTime == endTime) {
                // Cancel the appointment
                current->isBooked = false;
                std::cout << "Appointment canceled from " << current->startTime << " to " << current->endTime << "\n";
                return;
            }
            current = current->next;
        }

        // If the appointment is not found
        std::cout << "No appointment found for the given time range.\n";
    }

    // Function to sort the list based on time
    void sortAppointmentsByTime() {
        Appointment* current = head;

        // Convert the linked list to a vector for sorting
        std::vector<Appointment*> appointments;
        while (current) {
            appointments.push_back(current);
            current = current->next;
        }

        // Sort the vector based on start time
        std::sort(appointments.begin(), appointments.end(), [](const Appointment* a, const Appointment* b) {
            return a->startTime < b->startTime;
        });

        // Reconstruct the linked list
        for (size_t i = 0; i < appointments.size(); ++i) {
            appointments[i]->prev = (i > 0) ? appointments[i - 1] : nullptr;
            appointments[i]->next = (i < appointments.size() - 1) ? appointments[i + 1] : nullptr;
        }

        head = (appointments.empty()) ? nullptr : appointments[0];
    }

    // Function to sort the list based on time using pointer manipulation
    void sortAppointmentsByTimePointerManipulation() {
        if (!head || !head->next) {
            return; // No need to sort if the list is empty or has only one element
        }

        Appointment* sorted = nullptr;
        Appointment* current = head;

        // Traverse the original list
        while (current) {
            Appointment* next = current->next;

            if (!sorted || sorted->startTime > current->startTime) {
                // Insert at the beginning of the sorted list
                current->next = sorted;
                current->prev = nullptr;
                if (sorted) {
                    sorted->prev = current;
                }
                sorted = current;
            } else {
                // Traverse the sorted list to find the correct position
                Appointment* temp = sorted;
                while (temp->next && temp->next->startTime < current->startTime) {
                    temp = temp->next;
                }

                // Insert in between nodes or at the end of the sorted list
                current->next = temp->next;
                current->prev = temp;
                if (temp->next) {
                    temp->next->prev = current;
                }
                temp->next = current;
            }

            current = next;
        }

        // Update the head of the list
        head = sorted;
    }
};

int main() {
    // Create an appointment scheduler
    AppointmentScheduler scheduler;

    // Initialize the schedule with time slots
    for (int i = 9 * 60; i <= 17 * 60; i += 30) {
        Appointment* newAppointment = new Appointment();
        newAppointment->startTime = i;
        newAppointment->endTime = i + 30;
        if (scheduler.head) {
            newAppointment->prev = scheduler.head;
            scheduler.head->next = newAppointment;
        }
        scheduler.head = newAppointment;
    }

    // Display free slots
    scheduler.displayFreeSlots();

    // Book an appointment
    scheduler.bookAppointment(10 * 60, 10 * 60 + 30);

    // Display free slots after booking
    scheduler.displayFreeSlots();

    // Cancel an appointment
    scheduler.cancelAppointment(10 * 60, 10 * 60 + 30);

    // Display free slots after canceling
    scheduler.displayFreeSlots();

    // Sort appointments by time and display
    scheduler.sortAppointmentsByTime();
    std::cout << "Appointments after sorting by time:\n";
    scheduler.displayFreeSlots();

    // Sort appointments by time using pointer manipulation and display
    scheduler.sortAppointmentsByTimePointerManipulation();
    std::cout << "Appointments after sorting by time using pointer manipulation:\n";
    scheduler.displayFreeSlots();

    return 0;
}
