/*
题目描述

有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
测试样例：
2,2
返回：2
*/
class Robot {
public:
    int countWays(int x, int y) {
        // write code here
        int dong_x=x;
        int dong_y=y;

        if(dong_x==1||dong_y==1)
            return 1;
        else
            return countWays(dong_x-1,dong_y)+countWays(dong_x,dong_y-1);
    }
};
