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
//上面的代码虽然 完成了功能  但是也破坏了链表的结构 下面是将链表结构比对完  再还原 
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
		ListNode *c_point=slow;
		slow=slow->next;
		c_point->next=NULL;
		while(slow){
			ListNode *temp=slow->next;
			slow->next=c_point;
			c_point=slow;
			slow=temp;
		}
		bool result=true;
		ListNode * new_head=c_point;
		while(c_point!=pHead&&pHead){
			if(c_point->val!=pHead->val) { result=false;break;} 
			c_point=c_point->next;
			pHead=pHead->next;
		}
		ListNode * temp_head=NULL;
		while (new_head!=mid)
		{
			ListNode *temp=new_head->next;
			new_head->next=temp_head;
			temp_head=new_head;
			new_head=temp;
		}
		mid->next=temp_head;
		return result;
	}
};
