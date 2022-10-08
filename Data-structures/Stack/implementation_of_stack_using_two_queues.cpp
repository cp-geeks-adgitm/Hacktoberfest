/* Implementation of Stack using two Queues*/
#include <bits/stdc++.h>
using namespace std;

// created a class named as stack
class Stack {
	// Two inbuilt queues inherited from STL C++
	queue<int> q1, q2;

public:
    // pushed an item into the stack
	void push(int x)
	{
		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

    // pop out an item from Stack
	void pop()
	{
		// if no elements are there in q1
		if (q1.empty())
        {
			cout << "Error: Stack is Empty can't pop out anything!" << endl;
            return;
        }
		q1.pop();
	}

    // return the top item of stack , if stack is already empty then it returns -1
	int top()
	{
		if (q1.empty())
        {
            return -1;
        }
			
		return q1.front();
	}

    // returns the size of the stack or the number of items present in a stack currently
	int size()
	{
		return q1.size();
	}
};


int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size()<< endl;

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size()<< endl;

    s.pop();

    cout << "current size: " << s.size()<< endl;
    s.pop();
   
	return 0;
}
// This code is contributed by Rohan Bhatia.......💗
