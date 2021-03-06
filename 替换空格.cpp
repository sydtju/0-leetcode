/*
请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的字符，并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
测试样例：
"Mr John Smith”,13
返回："Mr%20John%20Smith"
”Hello  World”,12
返回：”Hello%20%20World”


*/
class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
    string result="";
	for(int i=0;i<length;++i){
		if(iniString[i]==' '){
			result=result+"%20";
		}
		else
			result=result+iniString[i];
	}
	return result;
    }
};
//这种方式  还不如上面的呢  因为对vector的插入时效率很低的
string replaceSpace(string iniString, int length) {
	// write code here
	int k = 0;
	while(k < length)
	{
		if( ' ' ==iniString[k])
		{
			iniString[k] = '0'; //先替换
			iniString.insert(k, 1, '2');
			iniString.insert(k, 1, '%');
			length += 2;
		}
		k++;
	}
	return iniString;
	}
