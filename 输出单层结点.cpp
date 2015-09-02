/*
题目描述

对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，代表该深度上所有结点的值，
请按树上从左往右的顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。
*/
//思路就是先序遍历 层数为dep的时候就向vector里面装数 然后做成链表
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
private:
    vector<int>  syd;
public:
    
    void lookup(TreeNode* root,int temp,const int dep){
        if(root==NULL) return;
        if(temp==dep) {syd.push_back(root->val);return ;}//找到之后就没有必要像下遍历了！！
        lookup(root->left,temp+1,dep);
        lookup(root->right,temp+1,dep);
    }
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        if(root==NULL) return NULL;
        lookup(root,1,dep);
        int len=(int)syd.size();
        int i=0;
        ListNode *head=new ListNode(-1);
        ListNode *h=head;
        while(i<len){
            h->next=new ListNode(syd[i]);
            h=h->next;
            i++;
        }
        delete head;
        syd.clear();
        h=head->next;
        return h;
    }
};
