/*
题目描述

有一个类似结点的数据结构TreeNode，包含了val属性和指向其它结点的指针。其可以用来表示二叉查找树(其中left指针表示左儿子，right指针表示右儿子)。请编写一个方法，将二叉查找树转换为一个链表，其中二叉查找树的数据结构用TreeNode实现，链表的数据结构用ListNode实现。
给定二叉查找树的根结点指针root，请返回转换成的链表的头指针。
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
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Converter {
public:
	void midfind(TreeNode* root,ListNode* &res){
		if(root){
			midfind(root->left,res);
			res->next=new ListNode(root->val);
			res=res->next;
			midfind(root->right,res);
		}
	}
	ListNode* treeToList(TreeNode* root) {
		// write code here
		ListNode* res=new ListNode(-1);
		ListNode* result=res;
		if(!root) return NULL;
		else
			midfind(root,res);
			res=result->next;
		delete result;
		return res;
	}
};
