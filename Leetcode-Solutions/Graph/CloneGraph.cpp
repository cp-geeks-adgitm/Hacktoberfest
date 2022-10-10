/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* node, map <int,Node*> &mp){
    
        if(!node)
            return NULL;
        Node* newRoot = new Node(node->val);
        mp[node->val] = newRoot;
        for(auto it : node->neighbors){
            if(mp.find(it->val) == mp.end()){
                newRoot->neighbors.push_back(dfs(it,mp));
            }
            else
                newRoot->neighbors.push_back(mp[it->val]);
        }
            
        return newRoot;
    }
    
    Node* cloneGraph(Node* node) {
        
        map <int,Node*> mp;
        
        Node* newgraph;
        newgraph = dfs(node,mp);
        
        return newgraph;
    }
};