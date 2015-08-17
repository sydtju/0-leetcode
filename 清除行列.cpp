/*
清除行列
请编写一个算法，若MxN矩阵中某个元素为0，则将其所在的行与列清零。
给定一个MxN的int[][]矩阵(C++中为vector>)mat和矩阵的阶数n，请返回完成操作后的int[][]矩阵(C++中为vector>)，保证n小于等于300，矩阵中的元素为int范围内。
测试样例：
[[1,2,3],[0,1,2],[0,0,1]]
返回：[[0,0,3],[0,0,0],[0,0,0]]
*/
class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        // write code here
        vector<int> flag;
        if(n<=1) return mat;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    flag.push_back(i);
                    flag.push_back(j);
                }
            }
        }
        for(int i=0;i<(int)flag.size();){
            int x=flag[i++];
            for(int j=0;j<n;++j)
                mat[x][j]=0;
            int y=flag[i++];
			for(int j=0;j<n;++j)
                mat[j][y]=0;	
        }
        return mat;
    }
};
