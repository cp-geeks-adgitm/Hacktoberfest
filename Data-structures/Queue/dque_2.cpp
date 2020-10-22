#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};   
class dque
{
	node *front,*rear;  // points to head and tail in the list
	public:
	dque()
	{
	front=NULL; 
	rear=NULL                                                         
	}
	// method using push to add a data element
	void fpush(int);
	void rpush(int);
	// pop method to remove data element
	void rpop();
	void fpop();
	// top method to return top data element from stack
	int ftop();
	int rtop();
	void printS();
};

