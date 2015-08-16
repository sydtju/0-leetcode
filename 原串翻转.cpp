/*
请实现一个算法，在不使用额外数据结构和储存空间的情况下，翻转一个给定的字符串(可以使用单个过程变量)。
给定一个string iniString，请返回一个string，为翻转后的字符串。保证字符串的长度小于等于5000。
测试样例：
"This is nowcoder"
返回："redocwon si sihT"
*/

class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
    int len=(int)iniString.size();
	if(len<=1) return iniString;
	int start=0;
	int end=len-1;
	while (start<end)
	{
		char temp=iniString[start];
		iniString[start]=iniString[end];
		iniString[end]=temp;
		start++;end--;
	}
	return iniString;
    }
};
