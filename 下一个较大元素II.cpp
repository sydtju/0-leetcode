/*
题目描述

现在有一个数组，请找出数组中每个元素的后面比它大的最小的元素，若不存在则为-1。
给定一个int数组A及数组的大小n，请返回每个元素所求的值组成的数组。保证A中元素为正整数，且n小于等于1000。
测试样例：
[11,13,10,5,12,21,3],7
[12,21,12,12,21,-1,-1]
*/

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        set<int> s;
		vector<int> res(n,0);
        if(n<=0) {res.clear();return res;}
		for(int i=n-1;i>=0;--i){
			set<int>::iterator it=s.upper_bound(A[i]);
			if(it==s.end()) res[i]=-1;
			else
				res[i]=*it;
			s.insert(A[i]);
		}
		return res;
    }
};
