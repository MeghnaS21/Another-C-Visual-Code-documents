#include<iostream>
using namespace std;

class Node
{
public:
   int data;
   Node* next;
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



int main()
{
    Node* head;
    Node* second;
    Node* third;

    head= new Node();
    second=new Node();
    third = new Node();

    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=8;
    third->next=NULL;

    printlist(head);

    return 0;
}