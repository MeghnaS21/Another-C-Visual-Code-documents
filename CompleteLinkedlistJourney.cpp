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
        cout<<ptr->data<<" ";
        ptr=ptr->next;
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

Node* insertinBetween(Node* head, int data, int index)
{
    Node* new_node=new Node();
    Node* p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    new_node->data=data;
    new_node->next=p->next;
    p->next=new_node;

    return head;

}

Node* insertAtend(Node* head, int data)
{
    Node* new_node= new Node();
    Node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    new_node->data=data;
    p->next=new_node;
    new_node->next=NULL;
    return head;
}

Node* insertAfterNode(Node* head, Node* prevNode, int data)
{
    Node* new_node=new Node();
    new_node->data=data;
    new_node->next=prevNode->next;
    prevNode->next=new_node;

    return head;
}

int main()
{
    Node* head;
    Node* second;
    Node* third;

    head= new Node();
    second = new Node();
    third= new Node();

    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=8;
    third->next=NULL;

    cout<<"ORIGINAL LINKED LIST"<<endl;
    printlist(head);
    head = insertAtBeginning(head, 56);
    cout<<"AFTER PERFORMING INSERTION OPERATION at beginning LINKED LIST"<<endl;
    printlist(head);

    head = insertinBetween(head, 56, 2);
    cout<<"AFTER PERFORMING INSERTION OPERATION in between LINKED LIST"<<endl;
    printlist(head);

    head = insertAtend(head, 56);
    cout<<"AFTER PERFORMING INSERTION OPERATION at endLINKED LIST"<<endl;
    printlist(head);


    head = insertAfterNode(head,third, 56);
    cout<<"AFTER PERFORMING INSERTION OPERATION after given node LIST"<<endl;
    printlist(head);

    return 0;
    
}