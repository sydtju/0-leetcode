/*
题目描述

有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。请设计一个高效的算法，计算给定数组中的逆序对个数。
给定一个int数组A和它的大小n，请返回A中的逆序对个数。保证n小于等于5000。
测试样例：
[1,2,3,4,5,6,7,0],8
返回：7
*/
class AntiOrder {
public:
    void merge(vector<int> &dat,int start,int mid,int end,int &count){
	vector<int> temp;
	int i=start;
	int j=mid+1;
	while (i<=mid&&j<=end)
	{
		if(dat[i]<=dat[j]) temp.push_back(dat[i++]);
		else{
			temp.push_back(dat[j++]);
			count=count+mid-i+1;
		}
	}
	if(i>mid){while(j<=end) temp.push_back(dat[j++]);}
	if(j>end){while(i<=mid) temp.push_back(dat[i++]);}
	int len=(int)temp.size();
	for(i=0;i<len;++i)
		dat[i+start]=temp[i];
}
void mergesort(vector<int> &dat,int start,int end,int &count){
	if(start<end){
		mergesort(dat,start,(start+end)/2,count);
		mergesort(dat,(start+end)/2+1,end,count);
		merge(dat,start,(start+end)/2,end,count);
	}
}
    int count(vector<int> A, int n) {
        // write code here
        int count=0;
        mergesort(A,0,n-1,count);
        return count;
    }
};
