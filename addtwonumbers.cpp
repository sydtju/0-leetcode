//将两个倒序的数进行相加  结果也是倒序的   （1）注意进位标志的处理   （2）注意两个链表的 其中一个比另一个短的情况 
//（3）两个链表都结束之后 一定要判断进位标志
//author：sydtju
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *head=new ListNode(0);
	head->val=0;
	head->next=NULL;
	ListNode *sum=head;
	ListNode *l1_temp=l1;
	ListNode *l2_temp=l2;
	int dint=0;
	int last_int=0;
	while(NULL!=l1_temp&&NULL!=l2_temp){
		dint=(l1_temp->val+l2_temp->val+last_int>9)?1:0;
		if(dint){
			sum->next=new ListNode(l1_temp->val+l2_temp->val+last_int-10);
		}
		else{
			sum->next=new ListNode(l1_temp->val+l2_temp->val+last_int);
		}
		last_int=dint;   
		l1_temp=l1_temp->next;
		l2_temp=l2_temp->next;
		sum=sum->next;
	}

	if(NULL==l1_temp){
		while(l2_temp){
			dint=(l2_temp->val+last_int>9)?1:0;
			if(dint){
				sum->next=new ListNode(l2_temp->val+last_int-10);
			}
			else{
				sum->next=new ListNode(l2_temp->val+last_int);
			}
			last_int=dint;
			l2_temp=l2_temp->next;
			sum=sum->next;
		}
		sum->next=NULL;
	}
	if(NULL==l2_temp){
		while(l1_temp){
			dint=(l1_temp->val+last_int>9)?1:0;
			if(dint){
				sum->next=new ListNode(l1_temp->val+last_int-10);
			}
			else{
				sum->next=new ListNode(l1_temp->val+last_int);
			}
			last_int=dint;
			l1_temp=l1_temp->next;
			sum=sum->next;
		}
		sum->next=NULL;
	} 
	if(NULL==l1_temp&&NULL==l2_temp){
		if (last_int){
			sum->next=new ListNode(last_int);
			sum=sum->next;
		}
	}
	ListNode *sum_temp=head->next;
	delete head;
	return sum_temp;
    }
};
