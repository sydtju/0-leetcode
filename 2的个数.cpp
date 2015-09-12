/*
题目描述

请编写一个方法，输出0到n(包括n)中数字2出现了几次。
给定一个正整数n，请返回0到n的数字中2出现了几次。
测试样例：
10
返回：1
设N = abcde ,其中abcde分别为十进制中各位上的数字。

如果要计算百位上1出现的次数，它要受到3方面的影响：百位上的数字，百位一下（低位）上的数字，百位一上（高位）上的数字。

如果百位上数字为0，百位上可能出现1的次数由更高位决定。比如：12013，则可以知道百位出现1的情况可能是：100~199，1100~1199,2100~2199，，.........，11100~11199，一共1200个。可以看出是由更高位数字（12）决定，并且等于更高位数字（12）乘以 当前位数（100）。

如果百位上数字为1，百位上可能出现1的次数不仅受更高位影响还受低位影响。比如：12113，则可以知道百位受高位影响出现的情况是：100~199，1100~1199,2100~2199，，.........，11100~11199，一共1200个。和上面情况一样，并且等于更高位数字（12）乘以 当前位数（100）。但同时它还受低位影响，百位出现1的情况是：12100~12113,一共114个，等于低位数字（113）+1。

如果百位上数字大于1（2~9），则百位上出现1的情况仅由更高位决定，比如12213，则百位出现1的情况是：100~199,1100~1199，2100~2199，...........，11100~11199,12100~12199,一共有1300个，并且等于更高位数字+1（12+1）乘以当前位数（100）。

*/

class Count2 {
public:
    int countNumberOf2s(int n) {
        // write code here
	if(n<2)  return 0;
	int res=0;
	int num=n;
	int std=1;
	//int bit=0;
	while(num){
		int bit=num%10;
		if(bit<2)
			res+=(n/(std*10))*std;
		else if(bit==2)
			res+=n%std+1+(n/(std*10))*std;
		else  
			res+=(n/(std*10)+1)*std;
		num=num/10;
		std=std*10;
	}
	return res;
    }
};
