/*
题目描述

编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
给定两个整数int A，int B。请返回需要改变的数位个数。
测试样例：
10,5
返回：4
*/
class Transform {
public:
    int calcCost(int A, int B) {
        // write code here
        int c=A^B;
        int i=0;
        int f=1;
        while(f){
            if(f&c) i++;
           	f=f<<1;
        }
        return i;
    }
};
//更佳的解题方式
class Transform {
public:
    int calcCost(int A, int B) {
        // write code here
        int count = 0;
        int c;
        for (c=A^B;c!=0;c=c&(c-1)){
            count ++;
        }
        return count;
    }
};
