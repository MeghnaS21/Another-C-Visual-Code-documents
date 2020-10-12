//created linkedlist with three nodes

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    //allocated 3 nodes in heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 2;
    head->next = second;

    second->data = 3;
    second->next=third;

    third->data=5;
    third->next=NULL;

    return 0;
}