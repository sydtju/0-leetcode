/*
题目描述

请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
给定两个正整数int a,int b,同时给定一个int type代表运算的类型，1为求a ＊ b，0为求a ／ b，-1为求a － b。请返回计算的结果，保证数据合法且结果一定在int范围内。
测试样例：
1,2,1
返回：2
*/
class AddSubstitution {
public:
    int re(int a){//取反的操作其实可以 使用*2的方式进行  这样的话比较快
        int res=0;
        if(a==0) return 0;
        int foot=a>0?-1:1;
        while(a!=0){
            a=a+foot;
            res=res+foot;
        }
        return res;
    }
    int a_b(int a,int b ){
        return a+re(b);
    }
    int amulb(int a,int b){
        if(a==0) return 0;
        int temp=a>0?a:re(a);
        int res=0;
        while(temp!=0){
            res=res+b;
            temp=temp+(-1);
        }
        return a>0?res:re(res);
    }
    int adb(int a,int b){
        if(a==0) return 0;
        if(b==0) return -1;
        int tempa=a>0?a:re(a);
        int tempb=b>0?b:re(b);
        int res=0;
        int r=0;
        while(res+tempb<tempa){
            res=res+tempb;
            r++;
        }
        if((a>0&&b>0)||(a<0&&b<0)) return r;
        else return re(r);
    }
    int calc(int a, int b, int type) {
        // write code here
        switch(type){
            case 1: return amulb(a,b);
            case 0: return adb(a,b);
            case -1:return a_b(a,b);
            default: return -1;
        }
    }
};
