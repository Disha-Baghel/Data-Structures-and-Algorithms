#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;

    public: 
    LinkedList() {
        head = NULL;
    }

    void insertNode(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertBeg(int data) {
        Node* newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    void insertBeforeData(int bdata, int data) {
        Node* newNode = new Node(data);

        if (head->data == bdata) {
            insertBeg(data);
            return;
        }

        Node* temp = head;
        while (temp->next->data != bdata) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfterData(int adata, int data) {
        Node* newNode = new Node(data);

        Node* temp = head;
        while (temp->data != adata) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int data) {
        if (head->data == data) {
            
        }
    }

    void printNode() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};


int main() {
    LinkedList list;
    
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(11);

    list.insertBeg(0);

    list.insertBeforeData(3, 5);
    list.insertBeforeData(0, -1);

    list.printNode();
}