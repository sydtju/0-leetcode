/*
题目描述

有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
测试样例：
0.625
返回：0.101
*/

class BinDecimal {
public:
    string printBin(double num) {
        // write code here
	string res="0.";
	if(num<0||num>1) return res;
	double base=0.5;
	while(num>0){
		if(num>=base){res=res+"1";num=num-base;}
		else
			res=res+"0";
		base=base/2;
		if((int)res.length()>32) return "Error";
	}
	return res;
    }
};
