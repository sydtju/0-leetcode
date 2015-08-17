/*


对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。

给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。

*/


class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        // write code here
        int len=(int)vals.size();
        int num=1;
        int i=0;
        if(!len) return 0;
        while(1){
            if(num>len)	break;
            else{
                num=num<<1;
                i++;
            }
        }
        return i;
    }
};
