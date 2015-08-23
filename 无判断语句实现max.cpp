题目描述

请编写一个方法，找出两个数字中最大的那个。条件是不得使用if-else等比较和判断运算符。
给定两个int a和b，请返回较大的一个数。若两数相同则返回任意一个。
测试样例：
1，2
返回：2

class Max {
public:
    int getMax(int a, int b) {
        // write code here
        return (a+b+abs(a-b))/2;
    }
};
//
class Max {
public:
    int getMax(int a, int b) {
        // write code here
        int c=a-b;
        c=c>>31;
        switch(c&1){
            case 1:return b;
            case 0:return a;
        }
        return -1;
    }
};
class Max {
public:
    int getMax(int a, int b) {
        // write code here
        int c;
        c = a - b;
        int temp = c >> 31;
        switch(temp){
            case 1: return b;
            case 0: return a;
        }
    }
};
