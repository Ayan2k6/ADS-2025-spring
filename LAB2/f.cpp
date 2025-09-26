#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    // Вставка в начало
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    
    // Ищем узел перед позицией вставки
    SinglyLinkedListNode* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    // Вставляем после current
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

// Функция печати списка (уже есть в locked code)
void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;
    
    // Чтение списка
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int data, position;
    cin >> data;
    cin >> position;
    
    head = insertNodeAtPosition(head, data, position);
    
    printLinkedList(head);
    
    return 0;
}