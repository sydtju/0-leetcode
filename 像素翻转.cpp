/*
有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]
*/

//使用缓存的方式
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        // write code here
        vector<vector<int> > result;
        if(n<=1) return result;
        for(int i=0;i<n;++i){
            vector<int> temp;
            for(int j=n-1;j>=0;--j)
            	temp.push_back(mat[j][i]);
            result.push_back(temp);
        }
        return result
    }
};
//直接在原矩阵上操作的方式   更优秀！！！
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        // write code here
	int low=0,high=n-1;
	while(low<high){
		for(int i=0;i<high-low;++i){
			int temp=mat[low][low+i];
			mat[low][low+i]=mat[high-i][low];
			mat[high-i][low]=mat[high][high-i];
			mat[high][high-i]=mat[low+i][high];
			mat[low+i][high]=temp;
		}
		low++;
		high--;
	}
	return mat;
    }
};
