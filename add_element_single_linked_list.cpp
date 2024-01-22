#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node() {
        this->value = 0;
        this->next = NULL;
    }

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class SingleLinkedList {
public:
    Node* head;

    SingleLinkedList() {
        this->head = NULL;
    }

    void insertNode(int value) {
        Node* newNode = new Node(value);

        if (this->head == NULL) {
            this->head = newNode;
            return;
        }

        Node* temp = this->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int offset) {
        if (this->head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        int index = 0;
        Node* it = this->head;
        while (it->next != NULL) {
            index++;
            if (offset == index) {
                Node* temp = it;

            }
            
            it = it->next;
            
        }
    }
};

int main() {


    return 0;
}