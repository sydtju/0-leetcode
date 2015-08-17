/*
题目描述

请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}
返回：false
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
   	bool isPalindrome(ListNode* pHead) {
		// write code here
		if(!pHead) return false;
		if(!pHead->next) return true;
		ListNode*  fast=pHead->next;
		ListNode*  slow=pHead;
		while(fast){
			if(fast->next) fast=fast->next->next;
			else
				break;
			slow=slow->next;
		}
		ListNode *mid=slow;
		fast=slow;
		slow=slow->next;
		fast->next=NULL;
		while(slow){
			ListNode *temp=slow->next;
			slow->next=fast;
			fast=slow;
			slow=temp;
		}
		while(fast!=pHead&&pHead){
			if(fast->val!=pHead->val) return false; 
			fast=fast->next;
			pHead=pHead->next;
		}
		return true;
	}

};
