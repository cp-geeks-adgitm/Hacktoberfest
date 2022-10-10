#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node 
{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int val) 
    {
        this->val = val;
        left = right = NULL;
    }
};

class Tree
{
    private:
    Node *root;
    int nodeCount;

    void bfs()
    {
        queue<Node*> q;
        q.push(root);
        Node *trav = root;
        while(!q.empty())
        {
            trav = q.front();
            q.pop();
            cout << trav->val <<  " ";
            if (trav->left != NULL) q.push(trav->left);
            if (trav->right != NULL) q.push(trav->right);
        }
    }

    void preorder()
    {
        stack<Node*> s;
        s.push(root);

        Node *trav;
        while(!s.empty())
        {
            trav = s.top();
            s.pop();
            cout << trav->val << " ";
            if (trav->right)   s.push(trav->right);
            if (trav->left)    s.push(trav->left);
        } 
    }

    void inorder()
    {
        stack<Node*> s;

        Node *trav = root;
        while(trav != NULL || !s.empty())
        {
            // Dig left
            while (trav != NULL)
            {
                s.push(trav);
                trav = trav->left;
            }

            trav = s.top(); 
            s.pop();
            cout << trav->val << " ";

            trav = trav->right;
        }
    }

    void postorder()
    {
        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);

        while(!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left != NULL) s1.push(temp->left);
            if (temp->right != NULL) s1.push(temp->right);       
        }

        while(!s2.empty())
        {
            cout << s2.top()->val << " ";
            s2.pop();
        }

    }

    void dfs()
    {
        cout << "\npreorder Traversal : ";
        preorder();
        cout << "\nInorder Traversal : ";
        inorder();
        cout << "\nPostorder Traversal : ";
        postorder();

    }

    // Delete the Deepest Node.
    void deleteDeepest(Node * d_node)
    {
        queue<Node*> q;
        q.push(root);

        Node *trav;
        while(!q.empty())
        {
            trav = q.front();
            q.pop();

            if (trav == d_node) 
            {
                trav = NULL;
                delete(d_node);
                return; 

            }
            if (trav->right)
            {
                if (trav->right == d_node)
                {
                    trav->right = NULL;
                    delete(d_node);
                    return;
                }
                else 
                {
                    q.push(trav->right);
                }
            }
            if (trav->left)
            {
                if (trav->left == d_node)
                {
                    trav->left = NULL;
                    delete(d_node);
                    return;
                }
                else
                {
                    q.push(trav->left);
                }
            }
        }
    }

    public:
    Tree()
    {
        root = NULL;
        nodeCount = 0;
    }

    bool isEmpty() 
    {
        return size() == 0;
    }

    int size()
    {
        return nodeCount;
    }

    void  insert(int elem)
    {
        if (isEmpty()) {
            root  = new Node(elem);
            nodeCount++;
            return ;
        }
        queue<Node*> q;
        Node *trav = root;
        q.push(root);
        while (!q.empty()) {
            trav = q.front();
            q.pop();
            if (trav->left == NULL) {
                trav->left = new Node(elem);
                nodeCount++;
                return;
            }
            else {
                q.push(trav->left);
            }
            if (trav->right == NULL) {
                trav->right = new Node(elem);
                nodeCount++;
                return;
            }
            else {
                q.push(trav->right);
            }
        }
    }

    void deletion(int elem)
    {
        if (isEmpty()) {
            cout << "Tree is Empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        // find deepest node and node to be deleted.
        Node *d_node;
        Node *key_node = NULL;
        while (!q.empty())
        {
            d_node = q.front();
            q.pop();
            if (d_node->val == elem) 
            {
                key_node = d_node;
            }

            if (d_node->left)
            {
                q.push(d_node->left);
            }

            if (d_node->right)
            {
                q.push(d_node->right);
            }
        }
        if (key_node != NULL)
        {
            key_node->val = d_node->val;
            deleteDeepest(d_node);
            nodeCount--;
        }
    }

    void show()
    {
        cout << "\nLevel Order Traversal : "; 
        bfs();
        dfs();
    }

};

int main()
{
    Tree gg;
    gg.insert(11);
    gg.insert(6);
    gg.insert(15);
    gg.insert(3);
    gg.insert(8);
    gg.insert(13);
    gg.insert(17);
    gg.insert(1);
    gg.insert(5);
    gg.insert(12);
    gg.insert(14);
    gg.insert(19);
    gg.show();
    // gg.deletion(12);
    // gg.show();
}