// comsc 210 | lab17 | Christian Molina
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *head);// prototype
void addFront(Node * &head, float val);
void addTail(Node * &head, float val);

int main() {
    Node *head = nullptr;
    

    // adding nodes to the linked list
    for (int i = 0; i < SIZE; i++){
        addFront(head, rand() % 100);
    }
    cout << "Initial list:" << endl;
    output(head);


    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    cout << "After deletion:" << endl;
    output(head);

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}