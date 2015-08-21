/*
题目描述

在n个顶点的多边形上有n只蚂蚁，这些蚂蚁同时开始沿着多变形的边爬行，请求出这些蚂蚁相撞的概率。(这里的相撞是指存在任意两只蚂蚁会相撞)
给定一个int n(3<=n<=10000)，代表n变形和n只蚂蚁，请返回一个double，为相撞的概率。
测试样例：
3
返回：0.75
*/
class Ants {
public:
    double antsCollision(int n) {
        // write code here
        long long count=1;
        count=count<<n;
        return 1.0-(2.0/(double)count);
    }
};
