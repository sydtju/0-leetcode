

/*
题目描述

在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。给定一个升序数组，元素值各不相同，编写一个方法，判断在数组A中是否存在魔术索引。请思考一种复杂度优于o(n)的方法。
给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
测试样例：
[1,2,3,4,5]
返回：false
*/
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        // write code here
        if(n<=0) return false;
        if(A[0]<=0&&A[n-1]>=n){
        	int start=0;
            int end=n-1;
            int mid=0;
            while(start<end){
                mid=(start+end)/2;
                if(A[mid]==mid) return true;
                else if(A[mid]<mid) start=mid+1;
                else if(A[mid]>mid) end=mid-1;
				else ;
            }
        }
        else
            return false;
    }
};
