#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printlist(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout<<endl;
}

Node *insertAtBeginning(Node *head, int data)
{
    Node *new_Node = new Node();
    new_Node->data = data;
    new_Node->next = head;
    return new_Node;
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *new_Node;

    head = new Node();
    second = new Node();
    third = new Node();
    new_Node = new Node();

    head->data = 21;
    head->next = second;

    second->data = 06;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    printlist(head);
    head = insertAtBeginning(head, 56);
    printlist(head);

    return 0;
}