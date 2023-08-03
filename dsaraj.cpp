#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertEnd(struct Node **start, int value)
{
    if (*start == NULL)
    {
        struct Node *new_node = new Node;
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    Node *last = (*start)->prev;
    struct Node *new_node = new Node;
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}
void display(struct Node *start)
{
    struct Node *temp = start;
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

void printPatern(Node *start, int n)
{
    // warning this is an neverending loop;
    int count = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        count++;
        if (i > n)
            i = i % n;
        int startIndex = i;
        int x = 1;
        Node *temp = new Node;
        temp = start;
        while (x != startIndex)
        {
            temp = temp->next;
            x++;
        }
        int loopingThrice = 3;
        while (loopingThrice--)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        if (count == 100)
            break;
    }
}
int main()
{
    struct Node *start = NULL;
    cout << "Enter the number of elements" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        insertEnd(&start, a);
    }
    cout << "The given Linked List is" << endl;
    display(start);
    cout << endl;

    cout << "Now calling the patern function" << endl;
    printPatern(start, n);
    return 0;
}