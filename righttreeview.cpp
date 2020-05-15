  vector<int>v;
    int maxl = -1;
    void helper(TreeNode* root , int level)
    {
        if(root==NULL)
            return ;
        if(level > maxl)
        {
            maxl = level;
            v.push_back(root->val);
        }
        helper(root->right, level+1);
        helper(root->left, level+1);
            
    }
    vector<int> rightSideView(TreeNode* root) {
       helper(root, 0);
        return v;
    }
