/*题目描述
现在我们有一个int数组，请你找出数组中每个元素的下一个比它大的元素。
给定一个int数组A及数组的大小n，请返回一个int数组，代表每个元素比他大的下一个元素,若不存在则为-1。保证数组中元素均为正整数。
测试样例：
[11,13,10,5,12,21,3],7返回：[13,21,12,12,21,-1,-1]
*/
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        stack<int> s;
        vector<int>  res;
        vector<int>  res_temp;
        if(n<=0) return res;
 		s.push(-1);
        for(int i=n-1;i>=0;--i){
            int top=s.top();
            while(top!=-1&&A[i]>=top){
                s.pop();
                top=s.top();
            }
            res_temp.push_back(top);
         	s.push(A[i]);   
        }
        int len=(int)res_temp.size();
        for(int i=len-1;i>=0;--i)
            res.push_back(res_temp[i]);
        res_temp.clear();
        return res;
    }
};
