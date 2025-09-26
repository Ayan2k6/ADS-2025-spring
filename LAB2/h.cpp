#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Вставка элемента на позицию p
Node* inserts(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    for (int i = 0; i < p - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Удаление элемента с позиции p
Node* remove(Node* head, int p) {
    if (p == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* temp = head;
    for (int i = 0; i < p - 1; i++) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;
}

// Печать списка
void print(Node* head) {
    if (head == nullptr) {
        cout << "-1" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Перемещение узла из p1 в p2 (p2 считается после удаления p1)
Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;
    
    // Находим узел p1 и его предыдущий
    Node* prev1 = nullptr;
    Node* curr1 = head;
    for (int i = 0; i < p1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    
    // Удаляем curr1 из списка
    if (prev1 == nullptr) {
        head = head->next;
    } else {
        prev1->next = curr1->next;
    }
    curr1->next = nullptr;
    
    // Вставляем curr1 на позицию p2
    if (p2 == 0) {
        curr1->next = head;
        return curr1;
    }
    Node* temp = head;
    for (int i = 0; i < p2 - 1; i++) {
        temp = temp->next;
    }
    curr1->next = temp->next;
    temp->next = curr1;
    return head;
}

// Разворот списка
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Циклический сдвиг влево x раз
Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || x == 0) return head;
    
    // Находим длину списка
    int len = 0;
    Node* temp = head;
    Node* tail = nullptr;
    while (temp != nullptr) {
        len++;
        tail = temp;
        temp = temp->next;
    }
    
    x = x % len;
    if (x == 0) return head;
    
    // Находим новый хвост после сдвига
    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    
    return newHead;
}

// Циклический сдвиг вправо x раз
Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || x == 0) return head;
    
    // Находим длину списка
    int len = 0;
    Node* temp = head;
    Node* tail = nullptr;
    while (temp != nullptr) {
        len++;
        tail = temp;
        temp = temp->next;
    }
    
    x = x % len;
    if (x == 0) return head;
    
    // Сдвиг вправо на x = сдвиг влево на len - x
    return cyclic_left(head, len - x);
}

int main() {
    Node* head = nullptr;
    int command;
    
    while (true) {
        cin >> command;
        
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = inserts(head, x, p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    
    // Очистка памяти (опционально, т.к. программа завершается)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}