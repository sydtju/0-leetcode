/*
题目描述

有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
给定一个数int k，请返回第k个数。保证k小于等于100。
测试样例：
3
返回：7

*/

class KthNumber {
public:
    int min(int a,int b,int c){
	int min_temp=a>b?b:a;
	return  min_temp>c?c:min_temp;
}
    
int findKth(int k){
    int index=k;
	int index_std=0,index2=0,index3=0,index5=0;
	if (index<=0) return 0;
	int value=1;
	int *array=new int[index+1];
	array[0]=1;
	while (index_std<index)
	{
		value=min(array[index2]*3,array[index3]*5,array[index5]*7);
		if (array[index2]*3==value) index2++;
		if (array[index3]*5==value) index3++;
		if (array[index5]*7==value) index5++;
		array[++index_std]=value;
	}
	int result=array[index_std];
	delete[] array;
	return result;
}   
};
