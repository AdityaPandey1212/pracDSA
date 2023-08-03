#include <iostream>
#include <vector>
using namespace std;
class node
{
    public:
    int value ;
    node* next;
    node()
    {

    }
    node(int value)
    {
        this->value = value ;
        this->next = NULL;
    }
    void print()
    {
        cout<<this->value<<" "<<next;
    }
    //making a deconstructor since the values had been assigned in heap
    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};


void insertathead(node* &head,int d)
{
    node* temp = new node(d);
    temp->next = head;
    head = temp ;
}

void insertatend(node* &tail,int a)
{  
    node *nextentry = new node(a);
    tail->next = nextentry; 
    tail = nextentry;
}

void insertinthemiddle(node* &tail ,node* &head , int position , int value)
{
    node* toinsert = new node(value);
    if (position == 1)
    {
        insertathead(head, value);
    }
    
    int count=1;
    node* temp = head;
    while (count < position-1)
    {
        count++;
        temp = temp->next ;
        
    }
    if (temp->next == NULL){
        insertatend(tail,value);
        return ;
    }
    else {

        toinsert->next = temp->next;
        temp->next = toinsert;
    }
    

}
void deletion(node* &head, int position)
{
    node* temp = new node;
    int count = 1 ;
    if (position ==1 )
    {
        node* temp = new node;
        temp = head;
        head = temp->next;
        delete temp;
    }
    else 
    {
        node* current = new node;
        current = head;
        node* previous = new node;
        previous = NULL;
        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        delete current; 

    }
}

void print (node* &head)
{
    node* temp = new node;
    temp = head ;
    while (temp != NULL)
    {
        cout<< temp->value <<" ";
        temp = temp->next; 
    }
}

int main(){
    //creating the header node
    node* node1 = new node(5);
    node* head = node1 ;
    //now we have headder as node 1;
    //inserting element at header
    node* tail = head ;
    insertathead(head,3);
    insertatend(tail, 12);
    insertatend(tail,69);
    insertinthemiddle(tail ,head , 5 , 6969);
    print(head);
    deletion(head,5);
    cout<<endl;
    print(head);
}
