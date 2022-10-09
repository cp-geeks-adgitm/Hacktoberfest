#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data,Node* next,Node* prev) 
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class LinkedList
{
    private:
    int size;
    Node *head;
    Node *tail;

    public:
    LinkedList() {
       size = 0;
       this->head = NULL;
       this->tail = NULL; 
    }
    
    int Getsize() const {
        return size;
    }

    bool isEmpty() {
        return Getsize() == 0;
    }

    void addFirst(int data) 
    {
        if (isEmpty()) {
            head = tail = new Node(data,NULL,NULL);
        } 
        else {
            head->prev = new Node(data,head,NULL);
            head = head->prev;
        }
        size++;
    }

    void addLast(int data) 
    {
         if (isEmpty()) {
            head = tail = new Node(data,NULL,NULL);
        }
        else {
            tail->next = new Node(data,NULL,tail);
            tail = tail->next;
        }
        size++;
    }

    void addAt(int index, int data) 
    {
        if (index < 0 || index > size) 
            throw invalid_argument("Index is out of bounds");

        if (index == 0) {
            addFirst(data);
            return;
        }

        if (index == size) {
            addLast(data);
            return;
        }

        Node *temp = head;
        for (int i = 0;i < index-1; ++i) {
            temp = temp->next;
        }
        Node *new_node = new Node(data,temp->next,temp);
        temp->next->prev = new_node;
        temp->next = new_node;

        size++;  
    }

    void removeFirst() 
    {
        if (isEmpty()) {
            cout << "Linked List is Empty\n";
            return;
        }

        Node *ptr = head;
        head = head->next;
        size--;
        delete(ptr);
        if (size == 0)
            tail = NULL;
        else
            head->prev = NULL;        
    }

    void removeLast() 
    {
        if (isEmpty()) {
            cout << "Linked List is Empty\n";
            return;
        }

        Node *ptr = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        delete(ptr);
        size--;
        if (size == 0)
            head = NULL;

    }

    void removeAt(int index) 
    {
        if (index < 0 || index >= size)
            throw invalid_argument("Index is out of bounds");

        if (isEmpty()) {
            cout << "Linked List is Empty\n";
            return;
        }

        if (index == 0) {
            removeFirst();
            return;
        }

        if (index  == size-1) {
            removeLast();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index; ++i) 
        {
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        size--;
        delete(temp);
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

int main() {

    LinkedList student;

    student.addAt(0,10);
    student.addAt(1,20);
    student.addAt(2,30);
    student.addAt(3,40);
    student.addAt(4,50);
    student.addAt(5,60);
    cout << student.Getsize() << '\n';
    student.Show();
    student.removeAt(5);
    student.removeAt(4);
    student.removeAt(3);
    student.removeAt(2);
    student.removeAt(1);
    cout << student.Getsize() << '\n';
    student.removeAt(0);
    cout << student.Getsize() << '\n';




    // student.removeAt(5);
    // student.removeAt(4);
    // student.removeAt(3);
    // student.removeAt(2);
    // student.removeAt(1);
    // // student.removeAt(0);
    // cout << student.Getsize() << '\n';

    // student.removeAt(0);
    student.Show();

}