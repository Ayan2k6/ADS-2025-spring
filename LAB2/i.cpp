#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    
    Node(string value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add_front(string value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        cout << "ok" << endl;
    }

    void add_back(string value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        cout << "ok" << endl;
    }

    void erase_front() {
        if (head == nullptr) {
            cout << "error" << endl;
            return;
        }
        
        Node* temp = head;
        string erasedValue = temp->data;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        size--;
        cout << erasedValue << endl;
    }

    void erase_back() {
        if (tail == nullptr) {
            cout << "error" << endl;
            return;
        }
        
        Node* temp = tail;
        string erasedValue = temp->data;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        size--;
        cout << erasedValue << endl;
    }

    void front() {
        if (head == nullptr) {
            cout << "error" << endl;
        } else {
            cout << head->data << endl;
        }
    }

    void back() {
        if (tail == nullptr) {
            cout << "error" << endl;
        } else {
            cout << tail->data << endl;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
        cout << "ok" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    string command;
    
    while (cin >> command) {
        if (command == "add_front") {
            string book;
            cin >> book;
            list.add_front(book);
        }
        else if (command == "add_back") {
            string book;
            cin >> book;
            list.add_back(book);
        }
        else if (command == "erase_front") {
            list.erase_front();
        }
        else if (command == "erase_back") {
            list.erase_back();
        }
        else if (command == "front") {
            list.front();
        }
        else if (command == "back") {
            list.back();
        }
        else if (command == "clear") {
            list.clear();
        }
        else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    
    return 0;
}