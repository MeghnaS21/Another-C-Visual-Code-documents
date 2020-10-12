#include <iostream>

using namespace std;

class Node         // STEP-1--> CREATE THE CLASS OF NAME (NODE)
{
public:            // STEP-2--> DATA MEMBERS OF A NODE= KEY, DATA, NEXT OF NODE POINTER
  int key;         // KEY==== act as index
  int data;        // DATA=== value inside the node
  Node *next;      // Next=== it is the pointer that will store the address of next node i.e. why pointer is of node type

  Node()             // STEP-3--> CREATE A DEFAULT CONSTRUCTOR
  {
    key = 0;         // STEP-4--> INITIALISE EVERY DATA MEMEBER WITH 0, 0 & NULL respectively
    data = 0;
    next = NULL;
  }
  Node(int k, int d)   // STEP-5--> CREATE A PARAMETERIZED CONSTRUCTOR
  {
    key = k;           //Assign it with the values passed as arguments inside the constructor definition
    data = d;
  }
};

class SinglyLinkedList    //STEP-6--> CREATE ANOTHER CLASS NAME- SINGLY LINKED LIST
{
public:                   //STP-7--> DATA MEMBER == head pointer that will store the address of node at the first position
  Node *head;

  SinglyLinkedList()      //STEP-8--> DEFAULT CONSTRUCTOR 
  {
    head = NULL;          //STEP-9--> INITIALISE   ||==HEAD POINTER==||   AS   ||==NULL==||
  }
  SinglyLinkedList(Node *n) //STEP-10--> CREATE PARAMETERIZED CONSTRUCTOR & pass ||=====address of ---NODE OBJECT----======||
  {
    head = n;               //ASSIGN THE HEAD POINTER WITH THE ADDRESS OF NODE POINTER PASSED AS ARGUMENTS
  }

// 1. CHeck if node exists using key value||
  Node *nodeExists(int k)                      //STEP-11--> CREATE A MEMBER TO CHECK IF NODE EXISTS JUST LIKE IN STACKS & QUEUES, 
  {                                            //IF IT IS EMPTY OR NOT. BECAUSE, IF WE WANT TO ENTER AN ELEMENT OF KEY-1. tHEN WE HAVE
    Node *temp = NULL;                         // TO CHECK IF THE NODE OF KEY 1 EXISTS OR NOT. IF IT EXISTS, THEN IT WILL GIVE US A MESSAGE TO 
                                               //TO PASS THE NODE OF SOME OTHER KEY VALUE. INSIDE THIS METHOD, WHAT WE WIL DO. 
                                               //AT FIRST WE WILL CREATE A TEMP POINTER TO STORE THE TEMPORARY VALUE
    Node *ptr = head;                          //THEN, CREATE ANOTHER POINTER TO TRAVERSE OVER THE ENTIRE LONKED LIST 
    while (ptr != NULL)               //THIS WHILE LOOP HAS THE CONDITION WHICH SAYS THAT, IF THE ADDRESS STORES INSIDE THE PTR POINTER IS NULL
    {                                 //TEHN IT INDICATES THAT THE LIST IS NOT EMPTY
      if (ptr->key == k)              //& IF THE KEY OF POINTER FOUND TO BE EQUAL TO THE KEY PASSED IN THE METHOD
      {
        temp = ptr;                   //THEN THAT TEMP POINTER WILL STORE THE ADDRESS STORED BY THE POINTER
      }
      ptr = ptr->next;                //ELSE PTR WILL STORE THE ADDRESS INSIDE OF THE NEXT POINTER
    }
    return temp;                      //WHILE IF THE POINTER IS NULL THEN IT WILL RETURN TEMP VALUE.
  }

  // 2. Append a node to the list
  void appendNode(Node *n)               //Method to append node will take the address of node pointer as argument
  {
    if (nodeExists(n->key) != NULL)      //to add a particular node first we will check if the node exists or not by using its key value
    {                                    // i.e. if the key value of the node passed is not equal to null then it will say-> node exists
      cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
    }
    else                                //else we will check if the linked list is empty or not. by using the head pointer
    {
      if (head == NULL)                 //if the value of head is null
      {
        head = n;                       // then we will add the node at the head position & print the message
        cout << "Node Appended" << endl;
      }
      else                              //else, when the node to be added doesn't exists also the list isn't empty then we will traverse 
      {                                 //through the list and add the node at the end
        Node *ptr = head;                      //.'. tTo traverse, we will take a pointer storing the value, stored by the head(address of next node)
        while (ptr->next != NULL)              //then we wil chwck if the value of pointer is not null, then we will change the value stored 
        {                                      //in the pointer with the next nodes address
          ptr = ptr->next;
        }
        ptr->next = n;                         //after that when the node pointer value is empty, then we will add the value of the node to
        cout << "Node Appended" << endl;       //the pointer.
      }
    }
  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node *n)           //now to add the node ath teh start, we will follow the same procedure as append
  {
    if (nodeExists(n->key) != NULL)   //first check if the node to be added exists or not, if it already exists then we will 
    {                                 //then print the message that noe already exists
      cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
    }                                 //else we have to perform next steps i.e. change the next value of the pointer with the address
    else
    {                                 //stored inside of head and point the head to node this will change the linking (mtlb ki, node ko first position pe add krne k liye, node ko point kro us node ki taraf jisko head pointer bhi point kr rha hai, fir us head pointer ko new wali node ki tarah pointer krdo )
      n->next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node *n)      //now to insert the nod eat any position what we have to do, firts we have to tell this method
  {                                         // that after which key, do you want to enter your node. Along withe obj node address itself
    Node *ptr = nodeExists(k);              //now we will use nodeExists method to check if key value exists or not, if the pointer value is null
    if (ptr == NULL)                      //then it means that, no node of this key exists, so you won't be able to append afterr this node
    {
      cout << "No node exists with key value: " << k << endl;  //hence prints the message
    }
    else                                 //else if node exists, then we will check the key value of the node to be the added, exists or not
    {
      if (nodeExists(n->key) != NULL)    //if the node with key value exists then print, node iwth this key value already exists
      {
        cout << "Node Already exists with key value : " << n->key << ". Append another node with different Key value" << endl;
      }
      else                              //else if the key value doesn't exists then we will perform insertion of node
      {
        n->next = ptr->next;            //change the linking, understand it using the given image
        ptr->next = n;
        cout << "Node Inserted" << endl;
      }
    }
  }

  // 5. Delete node by unique key
  void deleteNodeByKey(int k)          //now we have to delet the noe by passing key value of that node to be deleted
  {
    if (head == NULL)                  //step-1:- check if the list is empty 
    {
      cout << "Singly Linked List already Empty. Cant delete" << endl;  //then display:- List already Empty. Cant delete
    }
    else if (head != NULL)             //step-2:- so, when the list is not empty, 
    {
      if (head->key == k)              //then check if the key of the head == value of key passed
      {
        head = head->next;             //if the condition is true, then value of head should be changed to the value of next node
        cout << "Node UNLINKED with keys value : " << k << endl;
      }
      else                             //else, if the key value of first value is not to be deleted,
      {                                //then we will again perform traversal, 
        Node *temp = NULL;
        Node *prevptr = head;          //previous pointer will store the address of head
        Node *currentptr = head->next; //current pointer will store the address of the next node which is stored in the head->next pointer
        while (currentptr != NULL)     //now, if the current pointer is not null i.e. if the current pointer is the last pointer 
        {
          if (currentptr->key == k)    //we'll check if the key value of current pointer is equal to the key value to be deleted
          {
            temp = currentptr;         //then store the value of current pointer in the temp pointer
            currentptr = NULL;         //and change the address of current pointer as empty
          }
          else
          {
            prevptr = prevptr->next;   //now if the node to be deleted is not at first position, and also not at last position then we will 
            currentptr = currentptr->next; //change the linking and lets understand it with the help of diagram.
          }
        }
        if (temp != NULL)              //if temp value is not empty
        {
          prevptr->next = temp->next;   //then we will change the next value of previous pointer to the next value of temp pointer
          cout << "Node UNLINKED with keys value : " << k << endl;
        }
        else
        {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }
  }
  // 6th update node
  void updateNodeByKey(int k, int d)        //now we have to update the data value of the node in the list
  {

    Node *ptr = nodeExists(k);              //Now we will check if the node with the key value, whether it exists or not?
    if (ptr != NULL)                        //if the node exists the the pointer value will get the address of the same
    {
      ptr->data = d;                        //then change the data of the pointer changes to the data to be updated
      cout << "Node Data Updated Successfully" << endl; //print Node Data Updated Successfully
    }
    else
    {                                       //else, it the pointer value is null, then simply the node value doesn't exists
      cout << "Node Doesn't exist with key value : " << k << endl;//print this-Node Doesn't exist with key value
    }
  }

  // 7th printing
  void printList()                          //now to print the linkedlist we will traverse through the linkedd list
  {
    if (head == NULL)                       //if address of head is null then simply, there are no nodes in the inked list
    {
      cout << "No Nodes in Singly Linked List"; //print this-No Nodes in Singly Linked List
    }
    else
    {
      cout << endl                            //else when the nodes are present inside the linked list then it's time to print the nodes
           << "Singly Linked List Values : ";
      Node *temp = head;                      //we will create the temp pointer will be equal to the head pointer

      while (temp != NULL)                    //if the temp is not empty then, we will print in this order, understand by 
      {                                       //looking at the code carefully
        cout << "(" << temp->key << "," << temp->data << ") --> "; //
        temp = temp->next;
      }
    }
  }
};

int main()                                     //main function
{

  SinglyLinkedList s;                          //create the object of SinglyLinkedList
  int option;                                  //create the data member-- option, key1, k1, data
  int key1, k1, data1;
  do
  {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;           //printing messages
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl
         << endl;

    cin >> option;                                //take the input from the user, as options
    Node *n1 = new Node();                        //creating a pointer of node type using new keyword
    //Node n1;

    switch (option)                                //switch case using option
    {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}