/*
题目描述

编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。

*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code hereif
        if(!pHead) return pHead;
        ListNode* small=new ListNode(0);
        ListNode* big=new ListNode(0);
        ListNode* temps=small;
        ListNode* tempb=big;
		while(pHead){
            if(pHead->val<x) {
                temps->next=pHead;
                temps=temps->next;
            }
            else{
                tempb->next=pHead;
                tempb=tempb->next;
            }
            pHead=pHead->next;
        }
        tempb->next=NULL;//这里很奇怪！！ 如果删掉 肯定就循环输出  调试居然是循环的！！是因为最后一个指向的还是前面的 所以这里要断一下
		temps->next=big->next;
        ListNode* result=NULL;
            if(!small->next) result=big->next;
        	else result=small->next;
        delete small;
        delete big;
        return result;
    }
};
