/*Implementaion of Hash Table using Seperate Chaining*/

#include <bits/stdc++.h>
using namespace std;

class pairs
{
    public:
    int key;
    int value;

    pairs(int k,int v) {
        this->key = k;
        this->value = v;
    }
};

class Hash_table
{
    private:
    int capacity;
    list<pairs*> *table;

    int hashfunc(int key)
    {
        return key % capacity;
    }

    public:
    Hash_table(int cap)
    {

        this->capacity = cap;
        table = new list<pairs*>[capacity];
    }

    void insert(int key, int value)
    {
        pairs *new_pair = new pairs(key,value);
        int hashindex = hashfunc(key);
        table[hashindex].push_back(new_pair);
    }

    void deleteitem(int key)
    {
        int hashindex = hashfunc(key);
        list <pairs*> :: iterator it;
        for (it = table[hashindex].begin(); it != table[hashindex].end(); it++)
        {
            if ((*it)->key == key)
            {
                break;
            }
        }
        if (it != table[hashindex].end())
        {
            table[hashindex].erase(it);
        }
    }

    void show()
    {
        for (int i = 0;i < capacity; ++i)
        {
            cout << i << " : " ;
            for (auto x : table[i])
                cout << "(" << (x)->key << "," << (x)->value << ")" << "->";

            cout << "NULL\n";
        }      
    }  

};

int main()
{
    Hash_table gg(10);
    gg.insert(10,100);
    gg.insert(30,200);
    gg.insert(20,300);
    gg.insert(50,400);
    gg.insert(70,500);
    gg.insert(60,600);
    gg.insert(24,900);
    gg.insert(34,69);
    gg.insert(86,88);
    gg.deleteitem(50);
    gg.show();
}