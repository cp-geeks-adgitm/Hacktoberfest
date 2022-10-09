#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v, Node *left, Node *right)
    {
        val = v;
        this->left = left;
        this->right = right;
    }
};

class bst
{
private:
    int nodeCount = 0;
    Node *root = NULL;

    Node *add(Node *node, int elem)
    {
        if (node == NULL)
        {
            node = new Node(elem, NULL, NULL);
        }
        else
        {
            if (elem < node->val)
            {
                node->left = add(node->left, elem);
            }
            else
            {
                node->right = add(node->right, elem);
            }
        }
        return node;
    }

    Node *remove(Node *node,int elem) 
    {
        if (node == NULL) 
            return NULL;

        if (elem < node->val) {
            node->left =  remove(node->left,elem);
        }
        else if (elem > node->val) {
            node->right = remove(node->right,elem);
        }
        else {
            if (node->left == NULL) {
                return node->right;
            }
            else if (node->right == NULL) {
                return node->left;
            }
            else {
               Node *tmp = find_min(node->right);
               node->val = tmp->val;
               node->right = remove(node->right,tmp->val);
            }
        }
        return node;
    }

    Node *find_min(Node *node) 
    {
        while(node->left != NULL)
            node = node->left;
        
        return node;
    }

    bool contains(Node *node, int elem)
    {
        if (node == NULL) {
            return false;
        }
        
        if (elem < node->val) {
            return contains(node->left,elem);
        }
        else if (elem > node->val) {
            return contains(node->right,elem);
        }
        else {
            return true;
        }
        return false;
    }

    void preorder(Node *node)
    {
        if (node == NULL)
            return ;
        
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return ;
        
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == NULL)
            return ;
        
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

    void levelorder(Node *node)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) 
        {
            cout << q.front()->val << " ";
            if (q.front()->left != NULL)
                q.push(q.front()->left);

            if (q.front()->right != NULL)
                q.push(q.front()->right);

            q.pop();
        }
    }

public:
    bool isEmpty()
    {
        return size() == 0;
    }

    int size()
    {
        return nodeCount;
    }

    bool add(int elem)
    {
        if (contains(elem))
        {
            return false;
        }
        else
        {
            root = add(root, elem);
            nodeCount++;
            return true;
        }
        return false;
    }

    bool remove(int elem) 
    {
        if (contains(elem)) {
            root = remove(root,elem);
            nodeCount++;
            return true;
        }
        return false;
    } 
    bool contains(int elem) 
    {
        return contains(root,elem);
    }

    // dept first search using recursion
    void dfs()
    {
        if (isEmpty()) {
            cout << "Binary Tree is Empty.\n";
            return;
        }
       
       cout << "\nPreorder traversal : "; 
       preorder(root);
       cout << "\ninorder traversal : ";
       inorder(root);
       cout << "\nPostorder traversal : ";
       postorder(root);
    }

    void bfs()
    {
        if (isEmpty()) {
            cout << "Binary Tree is Empty.\n";
            return;
        }
        cout << "\nLevel order traversal :";
        levelorder(root);
    }
};

int main() 
{
    bst gg;
    gg.add(11);
    gg.add(6);
    gg.add(15);
    gg.add(3);
    gg.add(8);
    gg.add(13);
    gg.add(17);
    gg.add(1);
    gg.add(5);
    gg.add(12);
    gg.add(14);
    gg.add(19);
    // gg.remove(11);
    // cout << gg.add(19) << '\n';
    gg.dfs();
    gg.bfs();
}
