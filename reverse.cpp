//本程序在leetcode上执行时间是15ms  高于C语言的程序运行时间
class Solution {
public:
    int reverse(int x) {
        long long result=0;//为了防止溢出   
        //int temp=0;
        int flag=(x>0)?1:-1;
        int result_int;
        if(x==-2147483648) return 0;//由于INT_MIN在与-1相乘的时候 还是等于-1  
                                    //而且  翻转的时候 也会出现溢出的情况 直接返回0
        x=flag*x;
        while(x){
            int temp=x%10;
            result=result*10+temp;
            x=x/10;
        }
        if(1==flag&&result>2147483647)//边界判断  正数不大于上线
            return 0;
        if (-1==flag&&result>2147483648)//边界判断  负数不大于下线的绝对值
            return 0;
        result_int=(int)result;
        return result*flag;
    }
};
