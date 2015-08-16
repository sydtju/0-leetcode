/*
给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
测试样例：
"This is nowcoder","is This nowcoder"
返回：true
"Here you are","Are you here"
返回：false
*/

class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        int lenA=(int)stringA.size();
        int lenB=(int)stringB.size();
        if(lenA!=lenB) return false;
        if(lenA==0) return true;
        sort(stringA.begin(),stringA.end());
        sort(stringB.begin(),stringB.end());
        for(int i=0;i<lenA;++i){
            if(stringA[i]!=stringB[i]) return false;
        }
        return true;
    }
};
