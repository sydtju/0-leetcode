/*
题目描述
对于一个有正有负的整数数组，请找出总和最大的连续数列。
给定一个int数组A和数组大小n，请返回最大的连续数列的和。保证n的大小小于等于3000。
测试样例：
[1,2,3,-6,1]
返回：6
*/
class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        // write code here
        if(!n) return -1;
        int result=A[0];
        int temp=A[0];
        for(int i=1;i<n;++i){
            if(temp+A[i]>A[i]){
                temp=temp+A[i];   
            }
            else
                temp=A[i];
            if(temp>result) result=temp;
        }
        return result;
    }
};
