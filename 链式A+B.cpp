/*
有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
测试样例：
{1,2,3},{3,2,1}
返回：{4,4,4}
*/


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        if(!a&&!b) return NULL;
        if(!a)return b;
        if(!b) return a;
        int mid=0;
        ListNode *tempa=a;
        ListNode *tempb=b;
        ListNode *head=new ListNode(-1);
		ListNode *p=head;
        while(tempa!=NULL||tempb!=NULL){
            int bit_temp=0;
            if(!tempa)
             {
            	bit_temp=(mid+tempb->val)%10;
                mid=(mid+tempb->val)/10;
                p->next=new ListNode(bit_temp);
                tempb=tempb->next;
            }
            else if(!tempb){
                bit_temp=(mid+tempa->val)%10;
                mid=(mid+tempa->val)/10;
                p->next=new ListNode(bit_temp);
                tempa=tempa->next;
            }
            else{
                bit_temp=(mid+tempb->val+tempa->val)%10;
                mid=(mid+tempb->val+tempa->val)/10;
                p->next=new ListNode(bit_temp);
                tempa=tempa->next;
                tempb=tempb->next;
            }
            p=p->next;
        }
        if(mid!=0)p->next=new ListNode(mid);
        ListNode *result=head->next;
        delete head;
        return result;
    }
};
