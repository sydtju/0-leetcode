/*

题目描述

请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。

给定两个int A和B。请返回A＋B的值
测试样例：

1,2

返回：3


*/

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int temp=1;
        int  res=0;
        while(temp){
           res=A^B;
           temp=(A&B)<<1;
           A=res;
           B=temp;
        }
        return res;
    }
};
