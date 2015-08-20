/*
题目描述
实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
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

class Balance {
public:
    bool  mid(int &num,TreeNode* root){
        if(!root) {num=0;return true;}
        int num_left=0,num_right=0;
        if(mid(num_left,root->left)&&mid(num_right,root->right))  {
        			num=num_left>num_right?(num_left+1):(num_right+1);
        			if(num_left-num_right>1||num_left-num_right<-1)  return false;
        			else return true;
        }
        else
            return false;

    } 
    bool isBalance(TreeNode* root) {
        // write code here
        int num=0;
        return mid(num,root);
    }
};
