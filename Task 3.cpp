
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
    void insertAtPosition(int value, int pos) {

        Node* newNode = new Node(value);

        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Node inserted!" << endl;
            return;
        }
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted!" << endl;
    }
    void deleteAtPosition(int pos) {

        if (head == nullptr || pos <= 0) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }
        Node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;
            cout << "Node deleted!" << endl;
            return;
        }

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << "Node deleted!" << endl;
    }

    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {

            if (temp->data == value) {
                cout << "Element found at position: "
                    << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found!" << endl;
    }
    void countNodes() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total nodes: " << count << endl;
    }

    void display() {

        Node* temp = head;

        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Linked List: ";

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
    int choice, value, pos;

    cout << "\n===== SINGLY LINKED LIST MENU =====" << endl;
    cout << "1. Insert at Specific Position" << endl;
    cout << "2. Delete at Specific Position" << endl;
    cout << "3. Search an Element" << endl;
    cout << "4. Count Total Nodes" << endl;
    cout << "5. Display List" << endl;
    cout << "6. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 6) {

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> pos;

            list.insertAtPosition(value, pos);
            break;

        case 2:
            cout << "Enter position to delete: ";
            cin >> pos;

            list.deleteAtPosition(pos);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;

            list.search(value);
            break;

        case 4:
            list.countNodes();
            break;

        case 5:
            list.display();
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "===== MENU =====" << endl;
        cout << "1. Insert at Specific Position" << endl;
        cout << "2. Delete at Specific Position" << endl;
        cout << "3. Search an Element" << endl;
        cout << "4. Count Total Nodes" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
    }

    cout << "Program terminated!" << endl;

    return 0;
}