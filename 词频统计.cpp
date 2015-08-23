/*
题目描述

请设计一个高效的方法，找出任意指定单词在一篇文章中的出现频数。
给定一个string数组article和数组大小n及一个待统计单词word，请返回该单词在文章中的出现频数。保证文章的词数小于等于1000。
*/

class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        // write code here
        int count=0;
        for(int i=0;i<n;++i){
            if(0==article[i].compare(word))  count++;
        }
        return count;
    }
};
