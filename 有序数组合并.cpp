
/*
题目描述

有两个从小到大排序以后的数组A和B，其中A的末端有足够的缓冲空容纳B。请编写一个方法，将B合并入A并排序。
给定两个有序int数组A和B，A中的缓冲空用0填充，同时给定A和B的真实大小int n和int m，请返回合并后的数组。
*/
class Merge {
public:
    vector<int> mergeAB(vector<int> A, vector<int> B, int n, int m) {
        // write code here
        vector<int> res;
        int i=0,j=0;
        while(i<n&&j<m){
            if(A[i]<B[j]){
                res.push_back(A[i]);
                i++;
            }
            else{
                res.push_back(B[j]);
                j++;
            }
        }
        if(i==n){
            while(j<m){
                res.push_back(B[j]);
                j++;
            }
        }
        if(j==m){
             while(i<n){
                res.push_back(A[i]);
                i++;
            }
        }
        return res;
    }
};
