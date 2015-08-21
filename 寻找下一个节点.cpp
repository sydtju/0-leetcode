/*
题目描述
请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
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

class Successor {
public:

    void mid(TreeNode* root,vector<int> &res){
        if(!root) return ;
        mid(root->left,res);
        res.push_back(root->val);
        mid(root->right,res);
    } 
    int findSucc(TreeNode* root, int p) {
        // write code here
        vector<int> res;
        if(!root) return -1;
        mid(root,res);
        int len=(int)res.size();
        for(int i=0;i<len;++i){
            if(p==res[i]) {
                if(i+1<len) return res[i+1];
                else
                    return -1;
            }
        }
        return -1;
    }
};
