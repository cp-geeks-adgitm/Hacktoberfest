class Solution {
public:
    
    vector<string> vs;
    
    void path(TreeNode* root, string s)
    {
        if(root==NULL)  return;
        
        if(root->left or root->right)
            s += to_string(root->val) + "->";
        else
            s += to_string(root->val);
        
        if(!root->left and !root->right)
            vs.push_back(s);
        
        path(root->left,s);
        path(root->right,s);        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(root==NULL)  return {};
        
        path(root,"");
        return vs;
    }
};