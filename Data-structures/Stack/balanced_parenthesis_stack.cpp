// CPP program to check for balanced parenthesis.
#include <bits/stdc++.h>
using namespace std;
 
// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{ 
    stack<char> s;
    char x;
 
   
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
 
        // IF current current character is not opening
        // bracket, then it must be closing.
        if (s.empty())
            return false;
 
        switch (expr[i]) {
        case ')':
             
       
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
       
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
           
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
 
  
    return (s.empty());
}
 

int main()
{
    string expr = "{)}[]";
 
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "UnBalanced";
    return 0;
}
