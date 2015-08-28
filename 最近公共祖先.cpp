/*

题目描述

有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。

给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
测试样例：

2，3

返回：1


*/
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        if(a<=0||b<=0) return -1;
		while(a!=b){
            if(a>b) a=a/2;
            else
                b=b/2;
        }
        return a;
    }
};
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        if(a<=0||b<=0) return -1;
        int at=a;
        int bt=b;
        int btlay=1,atlay=1;
        while(bt!=1)
            {bt=bt/2;++btlay;}
        while(at!=1)
            {at=at/2;++atlay;}
        int count=(btlay-atlay)>=0?(btlay-atlay):(atlay-btlay);
        at=a;bt=b;
        if(count>0){ 
        	if(a>b) while(count--) at=at/2;
			if(b>a) while(count--) bt=bt/2;
        }
        while(at!=bt){
            at=at/2;
            bt=bt/2;
        }
        return at;
    }
};
