/*
题目描述

有一个正整数和负整数组成的NxN矩阵，请编写代码找出元素总和最大的子矩阵。请尝试使用一个高效算法。
给定一个int矩阵mat和矩阵的阶数n，请返回元素总和最大的子矩阵的元素之和。保证元素绝对值小于等于100000，且矩阵阶数小于等于200。
测试样例：
[[1,2,-3],[3,4,-5],[-5,-6,-7]],3
返回：10
时间复杂度O（n^3）
*/

class SubMatrix {
public:
int maxarray(vector<int> data){
	int len=(int)data.size();
	if(len<=0) return -1;
	int temp=data[0];
	int max=data[0];
	for(int i=1;i<len;++i){
		temp=temp+data[i];
		temp=temp>data[i]?temp:data[i];
		max=temp>max?temp:max;
	}
	return max;
}
void clear(vector<int> &temp){
	for(int i=0;i<temp.size();++i){
		temp[i]=0;
	}
}
int sumOfSubMatrix(vector<vector<int> > mat, int n) {
	// write code here
	if(n<=0) return -1;
	int max=INT_MIN;
	vector<int>  temp(n,0);
	for(int k=0;k<n;++k){
		for(int i=k;i<n;++i){
			for(int j=0;j<n;++j)
				temp[j]+=mat[i][j];
			int max_temp=maxarray(temp);
			if(max_temp>max) max=max_temp;
		}
		clear(temp);
	}
	return max;
}
};
