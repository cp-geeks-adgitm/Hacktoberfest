/*
Reversing a stack using recursion
    [0]             [4]
    [1]             [3]
    [2]     ====>   [2]
    [3]             [1]
    [4]             [0]

Author : github.com/Anirudhece
*/

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& st , int element){
    if(st.empty()){
        st.push(element);
    }
    else{
        int topElement= st.top();
        st.pop();
        insertAtBottom(st,element);
        st.push(topElement);
    }
}

void reverse(stack<int>& st){
    if(st.empty()){
        return;  // base condition
    }
    int element= st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,element);
}

int main()
{
    stack<int> stack1;
    stack<int> stack2;
    // push data into stack 1 (demoData-> 0 1 2 3)
    for (int i=0;i<4;i++) {  
        stack1.push(i); // updated
    }

    stack2 = stack1;
    cout << "Original Stack" << endl;
    while (!stack2.empty()) {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    cout<<endl;
    reverse(stack1);
    cout << "Reversed Stack" << endl;
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    return 0;
}
/*
Original Stack
3 2 1 0
Reversed Stack
0 1 2 3
*/