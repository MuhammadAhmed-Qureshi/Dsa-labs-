
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    void addPatient(int id, string name) {
        Node* newNode = new Node;
        newNode->id = id;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Patient added successfully!\n";
    }
    void removePatient(int id) {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Patient not found!" << endl;
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        }
        else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Patient removed successfully!\n";
    }

    void displayPatients() {
        if (head == nullptr) {
            cout << "No patients in the queue." << endl;
            return;
        }

        Node* temp = head;

        cout << "Patients Waiting in Queue:" << endl;

        while (temp != nullptr) {
            cout << "ID: " << temp->id<< " | Name: " << temp->name << endl;

            temp = temp->next;
        }
    }
    int countPatients() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ~PatientQueue() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PatientQueue hospital;

    cout << "--- Adding Patients ---" << endl;

    hospital.addPatient(101, "Ali");
    hospital.addPatient(102, "Ahmed");
    hospital.addPatient(103, "Sara");
    hospital.addPatient(104, "Fatima");

    hospital.displayPatients();

    cout << "Total Patients: "
        << hospital.countPatients() << endl;

    cout << "--- Cancelling Appointment ---" << endl;
    hospital.removePatient(102);

    hospital.displayPatients();

    cout << "Total Patients: "<< hospital.countPatients() << endl;

    return 0;
}
