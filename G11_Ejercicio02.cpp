#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Event {
    std::string name;
    std::string date;
    std::vector<std::string> attendees;
};

class EventOrganizer {
private:
    std::vector<Event> events;

public:
    void addEvent(const std::string& name, const std::string& date) {
        Event newEvent;
        newEvent.name = name;
        newEvent.date = date;
        events.push_back(newEvent);
    }

    void addAttendee(const std::string& eventName, const std::string& attendeeName) {
        auto event = findEvent(eventName);
        if (event != nullptr) {
            event->attendees.push_back(attendeeName);
        } else {
            std::cout << "Evento no encontrado." << std::endl;
        }
    }

    void showAttendees(const std::string& eventName) {
        auto event = findEvent(eventName);
        if (event != nullptr) {
            std::cout << "Asistentes al evento \"" << event->name << "\":" << std::endl;
            std::sort(event->attendees.begin(), event->attendees.end());
            for (const auto& attendee : event->attendees) {
                std::cout << attendee << std::endl;
            }
        } else {
            std::cout << "Evento no encontrado." << std::endl;
        }
    }

    void searchEventsByDate(const std::string& date) {
        std::cout << "Eventos en la fecha \"" << date << "\":" << std::endl;
        for (const auto& event : events) {
            if (event.date == date) {
                std::cout << event.name << std::endl;
            }
        }
    }

private:
    Event* findEvent(const std::string& eventName) {
        for (auto& event : events) {
            if (event.name == eventName) {
                return &event;
            }
        }
        return nullptr;
    }
};

int main() {
    EventOrganizer organizer;

    organizer.addEvent("Conferencia A", "2023-07-15");
    organizer.addEvent("Seminario B", "2023-08-02");
    organizer.addEvent("Taller C", "2023-09-10");

    organizer.addAttendee("Conferencia A", "Juan Perez");
    organizer.addAttendee("Conferencia A", "Maria Sanchez");
    organizer.addAttendee("Seminario B", "Pedro Gomez");

    organizer.showAttendees("Conferencia A");
    organizer.showAttendees("Seminario B");

    organizer.searchEventsByDate("2023-09-10");

    return 0;
}
