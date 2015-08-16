/*
利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
给定一个string iniString为待压缩的串(长度小于等于3000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
测试样例
"aabcccccaaa"
返回："a2b1c5a3"
"welcometonowcoderrrrr"
返回："welcometonowcoderrrrr"
*/

class Zipper {
public:
    string zipString(string iniString) {
        // write code here
    int i=0;
	int len=(int)iniString.length();
	string result="";
	if(0==len||1==len) return result;
	while (i<len)
	{
		char std=iniString[i];
		unsigned long long j=0;
		while((i+j<len)&&std==iniString[i+j])j++;
		i=i+j;
		result=result+std+to_string(j);
	}
	if(result.size()<len) return result;
	else
		return iniString;
    }
};
