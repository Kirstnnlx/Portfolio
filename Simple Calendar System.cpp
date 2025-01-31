#include <iostream>
#include <string>
using namespace std;

const int MAX_EVENTS = 100;

struct Event {
    string date;
    string title;
    string description;
};

Event events[MAX_EVENTS];
int eventCount = 0;

void addEvent();
void viewEvents();
void updateEvent();
void deleteEvent();
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        cout << "Hi! What do you want to do?: ";
        cin >> choice; 
        cin.ignore();

        switch (choice) {
            case 1: addEvent(); break;
            case 2: viewEvents(); break;
            case 3: updateEvent(); break;
            case 4: deleteEvent(); break;
            case 5: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}

void showMenu() {
    cout << "\n=== Timely: Easy Planner ===\n";
    cout << "1. Add Event\n";
    cout << "2. View Events\n";
    cout << "3. Update Event\n";
    cout << "4. Delete Event\n";
    cout << "5. Exit\n";
}

void addEvent() {
    if (eventCount < MAX_EVENTS) {
        Event newEvent;

        cout << "Enter date (YYYY-MM-DD): ";
        getline(cin, newEvent.date);
        cout << "Enter title: ";
        getline (cin, newEvent.title);
        cout << "Enter description: ";
        getline(cin, newEvent.description);

        events[eventCount++] = newEvent;
        cout << "Event added successfully!\n";
    } else {
        cout << "Event storage is full! Cannot add more events.\n";
    }
}

void viewEvents() {
    string date;
    cout << "Enter date to view events (YYYY-MM-DD): ";
    getline(cin, date);

    bool found = false;
    for (int i = 0; i < eventCount; i++) {
        if (events[i].date == date) {
            cout << "\nEvent " << i + 1 << ":\n";
            cout << "Title: " << events[i].title << "\n";
            cout << "Description: " << events[i].description << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "You have no event for this date.\n";
    }
}

void updateEvent() {
    string date;
    cout << "Enter the date of the event to update (YYYY-MM-DD): ";
    getline (cin, date);

    bool found = false;
    for (int i = 0; i < eventCount; i++) {
        if (events[i].date == date) {
            cout << "\nUpdating Event " << i + 1 << "\n";
            cout << "Current Title: " << events[i].title << "\n";
            cout << "Enter new title: ";
            getline(cin, events[i].title); 
            cout << "Current Description: " << events[i].description << "\n";
            cout << "Enter new description: ";
            getline(cin, events[i].description); 
            cout << "Event updated successfully!\n";
            found = true; 
            break;
        }
    }
    if (!found) { 
        cout << "You have no event for this date.\n";
    }
}

void deleteEvent() {
    string date; 
    cout << "Enter the date of the event to delete (YYYY-MM-DD): ";
    getline(cin, date);

    for (int i = 0; i < eventCount; i++) {
        if (events[i].date == date) { 
            for (int j = i; j < eventCount - 1; j++) {
                events[j] = events[j + 1];
            }
            eventCount--; 
            cout << "Event deleted successfully!\n";
            return; 
        }
    }
    cout << "You have no event for this date.\n";
}