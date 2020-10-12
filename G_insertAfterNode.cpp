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
Node* insertAfterNodee(Node* head, Node* node, int data)
{
   Node* ptr=new Node();
   ptr->data=data;

   ptr->next=node->next;
   node->next=ptr;

   return head;
}


int main()
{
    Node* head;
    Node* second;
    Node* third;

    head= new Node();
    second = new Node();
    third = new Node();

    head->data=6;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=9;
    third->next=NULL;

    printlist(head);

    head=insertAfterNodee(head, second, 21);
    printlist(head);
    return 0;
}

