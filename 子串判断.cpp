
/*
题目描述

现有一个小写英文字母组成的字符串s和一个包含较短小写英文字符串的数组p，请设计一个高效算法，对于p中的每一个较短字符串，判断其是否为s的子串。
给定一个string数组p和它的大小n，同时给定string s，为母串，请返回一个bool数组，每个元素代表p中的对应字符串是否为s的子串。保证p中的串长度小于等于8，且p中的串的个数小于等于500，同时保证s的长度小于等于1000。
测试样例：
["a","b","c","d"],4,"abc"
返回：[true,true,true,false]
*/
class Substr {
public:
    vector<int>  getnext(string str){
	int i=0;
	vector<int> next;
	int k=-1;
	int len=str.length();
	if(len<=0) return next;
	next.push_back(k);
	while (i<len)
	{
		if(k==-1||str[k]==str[i]){
			i++;
			k++;
			next.push_back(k);
		}
		else{
			k=next[k];
		}
	}
	return next;
}
int  kmp(string str_f,string str_son){
	int len_f=str_f.length();
	int len_s=str_son.length();
	if(len_f==0||len_s==0||len_f<len_s) return -1;
	vector<int> next=getnext(str_son);
	int i=0;
	int j=0;
	while(i<len_f&&j<len_s){
		if (j==-1||str_f[i]==str_son[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
	if (j>=len_s)
	{
		return i-j;
	}
	else
		return -1;
}
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        // write code here
        int i=0;
        vector<bool> res;
        if(n==0)  return res; 
        while(i<n){
            int r=kmp(s,p[i]);
            if(r==-1) res.push_back(false);
            else
                res.push_back(true);
            i++;
        }
        return res;
    }
};
