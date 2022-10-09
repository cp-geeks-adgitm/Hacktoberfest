#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int elem)
    {
        val = elem;
        prev = next = NULL;
    }
};

class Deque
{
private:
    int num;
    Node* front;
    Node* rear;

public:
    Deque()
    {
        num = 0;
        front = rear = NULL;
    }

    void Insert_front(int val)
    {
        Node* elem = new Node(val);
        if(num == 0)
        {
            front = rear = elem;
            num++;
            return;
        }

        elem->next = front;
        front->prev = elem;
        front = elem;
        num++;
        return;
    }

    void Insert_rear(int val)
    {
        Node* elem = new Node(val);
        if(num == 0)
        {
            front = rear = elem;
            num++;
            return;
        }

        elem->prev = rear;
        rear->next = elem;
        rear = elem;
        num++;
        return;
    }

    void Delete_front()
    {
        if(num == 0)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = front;
        if(num == 1)
        {
            front = rear = NULL;
            delete(ptr);
            num--;
            return;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
            delete(ptr);
            num--;
            return;
        }
    }

    void Delete_rear()
    {
        if(num == 0)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = rear;
        if(num == 1)
        {
            front = rear = NULL;
            delete(ptr);
            num--;
            return;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
            delete(ptr);
            num--;
            return;
        }
    }

    void Show()
    {
        if(!num)
        {
            cout<<"Empty List\n";
            return;
        }
        Node* ptr = front;
        cout<<"List: ";
        do
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        } while (ptr != NULL);
        cout<<endl;
    }

};

int main()
{
    Deque dq;
    dq.Insert_front(10);
    dq.Insert_front(20);
    dq.Insert_front(30);
    dq.Insert_front(40);
    dq.Insert_front(50);
    dq.Insert_front(60);
    dq.Insert_front(70);
    dq.Show();
    dq.Insert_rear(80);    
    dq.Insert_rear(90);    
    dq.Insert_rear(100);    
    dq.Insert_rear(110);    
    dq.Insert_rear(120);    
    dq.Insert_rear(130);    
    dq.Insert_rear(140);
    dq.Show();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Delete_front();
    dq.Show();
    dq.Delete_rear();
    dq.Delete_rear();
    dq.Delete_rear();
    dq.Delete_rear();
    dq.Show();
    

}
