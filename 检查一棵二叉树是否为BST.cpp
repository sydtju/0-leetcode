/*
题目描述

请实现一个函数，检查一棵二叉树是否为二叉查找树。
给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。

*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
/*最简代码*/
class Checker {
public:
    bool checkBST(TreeNode* root) {
        // write code here
        if(root==NULL)
            return true;
         
        if(root->left!=NULL&&root->left->val>root->val)
            return false;
         
        if(root->right!=NULL&&root->right->val<root->val)
            return false;
         
        return checkBST(root->left)&&checkBST(root->right);
    }
};
//比较笨的代码
class Checker {
public:
    void mid(vector<int> &res,TreeNode* root){
        if(!root)  return;
        	mid(res,root->left);
        	res.push_back(root->val);
        	mid(res,root->right);
    }
    bool checkBST(TreeNode* root) {
        // write code here
        vector<int>  res;
        mid(res,root);
        int len=(int)res.size();
        if(len==0) return false;
        if(len==1) return true;
        for(int i=1;i<len;++i)
            if(res[i]<res[i-1]) return false;
        return true;
    }
};
