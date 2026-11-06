
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = nullptr;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << "Node deleted successfully!" << endl;
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~LinkedList() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    LinkedList list;

    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();

    list.deleteByValue(30);

    cout << "After Deletion: ";
    list.display();

    return 0;
}
