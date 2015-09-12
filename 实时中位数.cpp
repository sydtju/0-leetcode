/*
题目描述

现有一些随机生成的数字要将其依次传入，请设计一个高效算法，对于每次传入一个数字后，算出当前所有传入数字的中位数。(若传入了偶数个数字则令中位数为第n/2小的数字，n为已传入数字个数)。
给定一个int数组A，为传入的数字序列，同时给定序列大小n，请返回一个int数组，代表每次传入后的中位数。保证n小于等于1000。
测试样例：
[1,2,3,4,5,6],6
返回：[1,1,2,2,3,3]
*/
class Middle {
private:
	vector<int> max;
	vector<int> min;
public:
	void swap(int &a,int &b){
		int temp=a;
		a=b;
		b=temp;
	}
	void adjustheapmax(vector<int> &dat,int loc,int length){
		int len=length;
		int child=0;
		for(int i=loc;2*i+1<len;i=child){
			child=2*i+1;
			if((child+1<len)&&dat[child]<dat[child+1]) ++child;
			if(dat[i]<dat[child]) swap(dat[i],dat[child]);
		}
	}
	void adjustheapmin(vector<int> &dat,int loc,int length){
		int len=length;
		int child=0;
		for(int i=loc;2*i+1<len;i=child){
			child=2*i+1;
			if((child+1<len)&&dat[child]>dat[child+1]) ++child;
			if(dat[i]>dat[child]) swap(dat[i],dat[child]);
		}
	}
	void buildmaxheap(vector<int> &dat){
		int len=(int)dat.size();
		for(int i=(len-1)/2;i>=0;--i){
			adjustheapmax(dat,i,len);
		}
	}

	void buildminheap(vector<int> &dat){
		int len=(int)dat.size();
		for(int i=(len-1)/2;i>=0;--i){
			adjustheapmin(dat,i,len);
		}	
	}
	vector<int> getMiddle(vector<int> A, int n) {
		// write code here
		int len=(int)A.size();
		vector<int> res;
		int i=1;
		min.push_back(A[0]);
		res.push_back(min[0]);
		for(;i<len;++i){
			if(i%2){
				if(A[i]<min[0]) {max.push_back(A[i]);buildmaxheap(max);}
				else{
					swap(A[i],min[0]);
					max.push_back(A[i]);
					buildmaxheap(max);
					adjustheapmin(min,0,min.size());
				}
				res.push_back(max[0]);
			}
			else{
				if(A[i]>max[0]) {min.push_back(A[i]);buildminheap(min);}
				else{
					swap(A[i],max[0]);
					min.push_back(A[i]);
					buildminheap(min);
					adjustheapmax(max,0,max.size());
				}
				res.push_back(min[0]);
			}
		}
		return res;
	}
};
