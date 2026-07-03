#include <iostream>
#include <list>

using namespace std;

class Event;
class Session;
class Ticket;
class TicketWallet;
class Person;
class Attendee;

class Event {
    string eventId;
    string eventName;
    string price;
    list<Session *> sessions;
public:
    Event(string eventId, string eventName, string price) {
        this->setEventId(eventId);
        this->setEventName(eventName);
        this->setPrice(price);
    }

    string getEventId() { return eventId; }
    string getEventName() { return eventName; }
    string getPrice() { return price; }

    void setEventId(string eventId) {
        this->eventId = eventId; 
    }
    void setEventName(string eventName) {
        this->eventName = eventName; 
    }
    void setPrice(string price) {
        this->price = price; 
    }

    Session *createSession(string sessionID, string time);

    void display() {
        cout << "=============Event=============" << endl;
        cout << "Event ID: " << this->getEventId() << endl;
        cout << "Event Name: " << this->getEventName() << endl;
        cout << "Price: " << this->getPrice() << endl;
    }

    ~Event();
};

class Session {
    string sessionId;
    string time;
    Event *event;
    list<Attendee *> attendees;
public:
    Session(string sessionId, string time, Event *event) {
        this->setSessionId(sessionId);
        this->setTime(time);
        this->setEvent(event);
    }
    string getSessionId() { return sessionId; }
    string getTime() { return time; }
    Event *getEvent() { return this->event; }

    void setSessionId(string sessionId) {
        this->sessionId = sessionId; 
    }
    void setTime(string time) {
        this->time = time;
    }
    void setEvent(Event *event) {
        this->event = event;
    }

    void bookTicket(Attendee *attendee);

    void display();
};

Session* Event::createSession(string sessionID, string time) {
    Session *session = new Session(sessionID, time, this);
    this->sessions.push_back(session);
    return session;
}

Event::~Event() {
    for (auto session : this->sessions) {
        delete session;
    }
    this->sessions.clear();
}

class Ticket {
    Session *session;
    bool isCheckIn;
public:
    Ticket(Session *session, bool isCheckIn) {
        this->setSession(session);
        this->setIsCheckIn(isCheckIn);
    }
    Session* getSession() { return session; }
    bool getIsCheckIn() { return isCheckIn; }

    void setSession(Session* session) {
        this->session = session; 
    }
    void setIsCheckIn(bool isCheckIn) {
        this->isCheckIn = isCheckIn; 
    }

    void display() {
        cout << "=============Ticket=============" << endl;
        cout << "Session ID: " << this->getSession()->getSessionId() << endl;
        cout << "Is Check In: " << this->getIsCheckIn() << endl;
    }
};

class TicketWallet {
    list<Ticket *> tickets;
public:
    TicketWallet() {}

    void addTicket(Ticket *ticket) {
        this->tickets.push_back(ticket);
    }

    list<Ticket *> getTickets() {
        return this->tickets;
    }

    void checkIn(Session *session) {
        string sessionId = session->getSessionId();
        for (auto ticket : this->tickets) {
            if (ticket->getSession()->getSessionId() == sessionId) {
                ticket->setIsCheckIn(true);
                cout << "Check in successfully!!!" << endl;
                break;
            }
        }
    }

    ~TicketWallet() {
        for (auto ticket : this->tickets) {
            delete ticket;
        }
        this->tickets.clear();
    }

    void printWallet() {
        cout << "=============Ticket Wallet=============" << endl;
        for (auto ticket : this->tickets) {
            cout << "Event Name: " << ticket->getSession()->getEvent()->getEventName() << endl;
            cout << "Price: " << ticket->getSession()->getEvent()->getPrice() << endl;
            cout << "Session ID: " << ticket->getSession()->getSessionId() << endl;
            cout << "Is Check In: " << ticket->getIsCheckIn() << endl;
            cout << "--\n";
        }
    }
};

class Person {
    string id;
    string name;

public:
    Person(string id, string name) {
        this->setId(id);
        this->setName(name);
    }

    void setId(string id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }
    string getId() { return this->id; }
    string getName() { return this->name; }

    virtual void display() = 0;
};

class Attendee : public Person {
    string email;
    TicketWallet *wallet;
public:
    Attendee(string email, string id, string name) : Person(id, name) {
        this->setEmail(email);
        this->wallet = new TicketWallet();
    }

    void setEmail(string email) {
        this->email = email;
    }

    TicketWallet *getWallet() {
        return this->wallet;
    }

    string getEmail() { return this->email; }

    void display() {
        cout << "=============Ticket=============" << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Email: " << this->getEmail() << endl;
        cout << "Ticket Wallet: \n";
        for (auto ticket : this->wallet->getTickets()) {
            cout << "Session ID: " << ticket->getSession()->getSessionId() << endl;
        }
    }

    ~Attendee() {
        delete wallet;
    }

};

void Session::display() {
    cout << "=============Session=============" << endl;
    cout << "Session ID: " << this->getSessionId() << endl;
    cout << "Time: " << this->getTime() << endl;
    cout << "Event Name: " << this->getEvent()->getEventName() << endl;
    cout << "Attendees:\n";
    for (auto attendee : this->attendees) {
        cout << "Attendee Name: " << attendee->getName() << endl;
    }
}

void Session::bookTicket(Attendee *attendee) {
    Ticket *ticket = new Ticket(this, false);
    TicketWallet *wallet = attendee->getWallet();
    wallet->addTicket(ticket);
    this->attendees.push_back(attendee);
}


int main() {
    // Create 2 events
    Event black("1", "Black", "1");
    Event pink("2", "Pink", "2");

    // Create 3 attendees
    Attendee alice("ha@gmail.com", "9", "Alice");
    Attendee pop("he@gmail.com", "8", "Pop");
    Attendee pip("hi@gmail.com", "7", "Pip");

    // Create 3 sessions from 2 events
    Session *se01 = black.createSession("3", "10h");
    Session *se02 = black.createSession("4", "10h");
    Session *se03 = pink.createSession("5", "10h");

    // Display session
    se01->display();

    // Alice, Pop -> Se01
    se01->bookTicket(&alice);
    se01->bookTicket(&pop);

    // Alice, Pip -> Se02
    se03->bookTicket(&alice);
    se03->bookTicket(&pip);

    // Display session after having attendee booking
    se01->display();

    // Alice checkin Se01
    alice.getWallet()->checkIn(se01);

    // Display Alice's wallet (notice the checkin status after calling `checkIn` function)
    alice.getWallet()->printWallet();
    return 0;
}
