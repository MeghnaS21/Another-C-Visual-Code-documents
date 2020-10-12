#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void printlist(Node* ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node* insertATEnd(Node* head, int data)
{
    Node* new_Node=new Node();
    new_Node->data=data;
    Node* p=head;

    while(p->next!=NULL)
    {
       p=p->next;
    }
    p->next=new_Node;
    new_Node->next=NULL;

    return head;
}

int main()
{
    Node* head;
    Node* second;
    Node* third;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data=6;
    head->next=second;

    second->data=7;
    second->next=third;

    third->data=8;
    third->next=NULL;

    printlist(head);
    head=insertATEnd(head, 21);
    printlist(head);
    return 0;
}