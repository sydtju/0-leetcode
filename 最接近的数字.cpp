/*

题目描述

有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
测试样例：
2
返回：[1,4]
解题思路：找最接近的小的数字的时候 就是将从低字节位开始  找到第一个10位置   11‘10’0   然后互换10 变为01 再将01后面的数 
所有的1放在前面 0放在后面 组成01后面的最大的数字。
解题思路：找最接近的大的数字的时候 就是将从低字节位开始  找到第一个01位置   11‘01’0   然后互换01 变为10 再将10后面的数 
所有的0放在前面 1放在后面 组成10后面的最小的数字。
*/

class CloseNumber {
public:
int getMin(int x){
	int temp_c=1;
	int temp_l=1;
	int bit=1;
	int count=0;
	while(bit){
		temp_l=temp_c;
		temp_c=x&bit;
		if(temp_l==0&&temp_c!=0) {
			int res=(x&(~bit))|(bit>>1);
			bit=bit>>2;
			while (bit)
			{
				if(count!=0){count--;res=res|bit;}
				else
					res=res&(~bit);
				bit=bit>>1;
			}
			return res;
		}
		if(temp_c!=0) count++;
		bit=bit<<1;
	}
	return -1;
}
int getMax(int x){
	int temp_c=0;
	int temp_l=0;
	int bit=1;
	int count=0;
	while(bit){
		temp_l=temp_c;
		temp_c=x&bit;
		if(temp_l!=0&&temp_c==0) {
			int res=(x|bit)&(~(bit>>1));
			bit=bit>>2;
			while (bit)
			{
				if(count!=0){count--;res=res&(~bit);}
				else
					res=res|bit;
				bit=bit>>1;
			}
			return res;
		}
		if(temp_c==0) count++;
		bit=bit<<1;
	}
	return -1;
}
vector<int> getCloseNumber(int x) {
	// write code here
	vector<int> res;
	res.push_back(getMin(x));
	res.push_back(getMax(x));
	return res;
}
};
