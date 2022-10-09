 /**
  *    author:  abhiy2k
  *    created: 14.07.2022 21:56:12        
 **/
 // Implementation of Avl Tree
 #include <bits/stdc++.h>
 
 using namespace std;
 
 class Node {
 public:	
 	int bf;
  int height;
  int value;
  Node *left,*right;
  Node(int val) {
    this->value = val;
    left = right = NULL;
   }                                          
 };
 
 class AvlTree {
 private:
   Node* root = NULL;
   int nodeCount = 0;
  
   Node *leftrotation(Node *node) {
   	 Node* newparent = node->right;
   	 node->right = newparent->left;
   	 newparent->left = node;
   	 update(node);
   	 update(newparent);
   	 return newparent;
   }
   
   Node *rightrotation(Node *node) {
   	 Node *newparent = node->left;
   	 node->right = newparent->left;
   	 newparent->left = node;
   	 update(node);
   	 update(newparent);
   	 return newparent;
   }
   
   bool contains(Node* node,int value) {
     if (node == NULL) return false;
     
     if (node->value > value) {
       return contains(node->left,value);
     }
     if (node->value < value) {
       return contains(node->right,value);
     }
     return true;
   }
     
   Node* insert(Node* node,int value) {
     // Base case
     if (node == NULL) return new Node(value);
     
     if (node->value > value) {
       node->left = insert(node->left,value);
     } 
     else {
       node->right = insert(node->right,value);  
     }
     update(node);
     return balance(node);
   }
	
   Node* del(Node* node,int value) {
   	 if (node == NULL) return NULL;
   	 
   	 if (node->value > value) {
   	 	 node->left = del(node->left,value);
   	 } else if (node->value < value) {
   	 	 node->right = del(node->right,value);
   	 } else {
   	 	 if (node->left == NULL) {
   	 	 	 return node->right;
   	 	 }
   	 	 else if (node->right == NULL) {
   	 	 	 return node->left;
   	 	 }
   	 	 else {
   	 	 	 if (node->left->height > node->right->height) {
   	 	 	 	 int var = findmax(node->left);
   	 	 	 	 node->value = var;
   	 	 	 	 node->left = del(node->left,var);
   	 	 	 }
   	 	 	 else {
   	 	 	 	 int var = findmin(node->right);
   	 	 	 	 node->value = var;
   	 	 	 	 node->right = del(node->left,var);
   	 	 	 }
   	 	 }
   	 }
   	 update(node);
   	 return balance(node);	 
   }
   
   int findmax(Node *node) {
   	 while (node->right != NULL) {
   	 	 node = node->right;
   	 }
   	 return  node->value;
   }
   
   int findmin(Node *node) {
   	 while (node->left != NULL) 
   	 	 node = node->left;
   	 return node->value;
   }
  
   void update(Node *node) {
     int lh = (node->left == NULL) ? -1 : node->left->height;
     int rh = (node->right == NULL) ? -1 : node->right->height;
     node->height = 1 + max(lh,rh);
     node->bf = rh - lh;
   }
   
   Node* leftleftcase(Node *node) {
   	 return rightrotation(node);
   }
   
   Node* leftrightcase(Node *node) {
   	 node->left = leftrotation(node);
   	 return leftleftcase(node);
   }
   
   Node* rightrightcase(Node *node) {
   	 return leftrotation(node);
   }
   
   Node* rightleftcase(Node *node) {
   	 node->right = rightrotation(node);
   	 return rightrightcase(node);
   }
   
   Node* balance(Node* node) {
   	 // left heavy tree
   	 if (node->bf == -2) {
   	 	 //left-left case
   	 	 if (node->left->bf <= 0) {
   	 	 	 return leftleftcase(node);
   	 	 } else {
   	 	 	 return  leftrightcase(node);
   	 	 }  	 	
   	 }
   	 // right heavy tree
   	 else if (node->bf == +2) {
   	 	 // right-right case
   	 	 if (node->right->bf >= 0) {
   	 	   return rightrightcase(node);
   	 	 } else {
   	 	 	 return rightleftcase(node);
   	 	 }
   	 }
   	 return node;
   } 	
  
 public:
   int height() {
     if (root == NULL) return 0;
     return root->height;
   }
   
   int size() {
     return nodeCount;
   }
   
   bool isEmpty() {
     return size() == 0;
   }
   
   bool contains(int value) {
     return contains(root,value);
   }
   
   bool insert(int value) {
     if (value == NULL) return false;
     if (!contains(root,value)) {
       root = insert(root,value);
       nodeCount++;
       return true;
     }
     return false;
   }
   
   bool del(int value) {
   	 if (value == NULL) return 	false;
   	 
   	 if (contains(root,value)) {
   	 	 root = del(root,value);
   	 	 nodeCount--;
   	 	 return true;
   	 }
   	 return false;
   }
      
   void show() {
   	 Node *trav = root;
   	 stack<Node*> s;
   	 while (trav != NULL || !s.empty()) {
   	 	 while (trav != NULL) {
   	 	 	 s.push(trav);
   	 	 	 trav = trav->left;
   	 	 }
   	 	 trav = s.top();
   	 	 s.pop();
   	 	 cout << trav->value << " ";
   	 	 trav = trav->right;
   	 }
   }
 };
  
 int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   AvlTree gg;
   gg.insert(10);
   gg.insert(5);
   gg.insert(20);
   gg.insert(19);
   gg.insert(26);
   gg.insert(34);
   gg.del(19);
   gg.del(10);
   gg.show(); 
   
   return 0;
 }