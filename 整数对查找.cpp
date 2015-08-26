/*
题目描述

请设计一个高效算法，找出数组中两数之和为指定值的所有整数对。
给定一个int数组A和数组大小n以及需查找的和sum，请返回和为sum的整数对的个数。保证数组大小小于等于3000。
测试样例：
[1,2,3,4,5],5,6
返回：2
*/
class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        // write code here
	multiset<int> s;

	multiset<int>::iterator its;
	multiset<int>::iterator ite;

	int count=0;
	//it=s.begin();
	int len=n;
	for(int i=0;i<len;++i){
		s.insert(A[i]);
	}
	for(int i=0;i<len;++i){
		int temp=sum-A[i];
		its=s.lower_bound(temp);
		ite=s.upper_bound(temp);
		while (its!=ite)
		{
			count++;
			its++;
		}
        if(temp==A[i])count--;
		
	}
	return count/2;
    }
};
