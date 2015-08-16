/*
请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
测试样例：
"aeiou"
返回：True
"BarackObama"
返回：False
*/
//O（nlogn）复杂度解法
class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
    if(iniString.size()<=1) return true;
	sort(iniString.begin(),iniString.end());
	for(int i=0;i+1<iniString.size();++i){
		if(iniString[i]==iniString[i+1]) return false;
	}
	return true;
    }
};
//O(n^2)复杂度解法
class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
	int len=iniString.length();
	for(int i=0;i<len-1;++i)
		for(int j=i+1;j<len;++j){
			if(iniString[i]==iniString[j])
				return false; 
		}
	return true;
    }
};
