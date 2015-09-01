/*
编写一个方法，确定某字符串的所有排列组合。
给定一个string A和一个int n,代表字符串和其长度，请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，排列中的字符串按字典序从大到小排序。(不合并重复字符串)
测试样例：
"ABC"
返回：["CBA","CAB","BCA","BAC","ACB","ABC"]
*/
class Permutation {
public:
    bool comp(char a,char b){
        return a>b;
    }
    vector<string> getPermutation(string A) {
        // write code here
        int len=(int)A.size();
     	vector<string> res;
        if(!len) return res;
        sort(A.begin(),A.end(),comp);
        do{
            res.push_back(A);
        }
        while(prev_permutation(A.begin(),A.end()));//只是针对的是不重复的情况  而且重复的元素会被合并
        return res;
    }
};
