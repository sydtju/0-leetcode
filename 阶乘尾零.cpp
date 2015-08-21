/*

题目描述

请设计一个算法，计算n的阶乘有多少个尾随零。

给定一个int n，请返回n的阶乘的尾零个数。保证n为正整数。
测试样例：

5

返回：1


Z = N/5 + N /(5*5) + N/(5*5*5).....知道N/(5的K次方)等于0

公式中 N/5表示不大于N的数中能被5整除的数贡献一个5，N/(5*5)表示不大于N的数中能被25整除的数再共享一个5.......
*/
class Factor {
public:
    int getFactorSuffixZero(int n) {
        // write code here
     	int count=0;
        while(n){
         n=n/5;
         count=count+n;
        }
        return count;
    }
};
