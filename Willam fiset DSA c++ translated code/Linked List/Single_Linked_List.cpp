#include <iostream>
using namespace std;
/*  A Single Linked List Implementation */

// Node of the linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
private:
    int size;
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    // Returns the size of linked list
    int Getsize() const
    {
        return size;
    }

    // checks if the linked list is empty ?
    bool isEmpty()
    {
        return (Getsize() == 0);
    }

    // Add an element to the tail of the linked list, O(1)
    void add(int elem)
    {
        addLast(elem);
    }

    // add a node to the tail of the linked list O(1)
    void addLast(int elem)
    {
        if (isEmpty())
        {
            head = tail = new Node(elem, NULL);
        }
        else
        {
            Node *temp = new Node(elem, NULL);
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // Add an element to the beginning of this linked list, O(1)
    void addFirst(int elem)
    {
        if (isEmpty())
        {
            head = tail = new Node(elem, NULL);
        }
        else
        {
            Node *temp = new Node(elem, head);
            head = temp;
        }
        size++;
    }

    // Add an element at a specified index
    void addAt(int index, int data)
    {
        if (index < 0 || index > size)
            throw invalid_argument("Index is out of bounds");

        if (index == 0)
        {
            addFirst(data);
            return;
        }

        if (index == size)
        {
            addLast(data);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index-1; ++i)
        {
            temp = temp->next;
        }
        Node *new_node = new Node(data, temp->next);
        temp->next = new_node;

        size++;

    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
            throw invalid_argument("Index is out of bounds");

        if (isEmpty()) {
            cout << "Linked List is Empty\n";
            return;
        }

        if (index == 0)
            return removeFirst();

        Node *temp = head;
        Node *ptr;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = temp->next->next;
        delete(ptr);
        size--;

    }
    
    void removeFirst() 
     {
        if (isEmpty()) {
            cout << "Linked List is Empty\n";
            return;
        }

        Node* ptr;
        ptr = head;
        head = head->next;
        delete(ptr);
        size--;
     }

    
    void Show()
    {
        if (isEmpty()) {
            cout << "Linked List is Empty\n";
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList student;

    student.addAt(0, 5);
    student.addAt(1, 10);
    student.addAt(2, 15);
    student.addAt(3, 20);
    student.addAt(4, 30);
    student.addAt(4, 50);
    student.addAt(4, 60);
    student.Show();
    student.removeAt(4);
    student.removeAt(4);
    student.removeAt(4);
    student.removeAt(3);
    student.removeAt(2);
    student.removeAt(1);
    student.removeAt(0);
    cout << student.Getsize() << '\n';

    student.Show();
}