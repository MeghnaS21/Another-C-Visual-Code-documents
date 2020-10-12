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

Node* insertInBetween(Node* head, int data, int index)
{
    Node* ptr = new Node();
    Node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

int main()
{
    Node* head;
    Node* second;
    Node* third;

    head=new Node();
    second=new Node();
    third=new Node();

    head->data=6;
    head->next=second;

    second->data=7;
    second->next=third;

    third->data=8;
    third->next=NULL;

    printlist(head);

    head=insertInBetween(head, 21, 2);
    printlist(head);
    return 0;
}