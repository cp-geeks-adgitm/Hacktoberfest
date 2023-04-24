//This Cpp program implements stack using linked lists and class in cpp.

#include<bits/stdc++.h>
using namespace std;

class Node{

public:
	int data;
	Node *next;

	Node(){

	}

	Node(int data){
		this->data = data;
		this->next = NULL;
	}	
	
};

class Stack{
	
public:

    Node* top;

	Stack(){
		top = NULL;
	}

	void push(int data){
		Node *tmp = new Node(data);
		tmp->next = top;
		top = tmp;
	}

	void display(){
		Node* tmp = top;
		while(tmp != NULL){
			cout<<tmp->data<<endl;
			tmp = tmp->next;
		}
	}

	void pop(){
		Node *tmp = top;
		top = top->next;
		delete tmp;
	}

};

int main(){
	Stack s;
	s.push(300);
	s.push(200);
	s.push(100);
	s.push(500);
	s.push(700);
	s.push(900);
	s.pop();
	s.pop();
	s.display();
	
}