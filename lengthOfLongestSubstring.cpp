//cpp实现   运行时间20ms  将字符串中的字符 按种类存储 其上一次出现时的位置   设两个指针分别指向子字符串的头和尾部
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	 int dat[128]={-1};
	 int start=-1;
	 int end=-1;
	 int max=0;
	 for(int j=0;j<128;j++) dat[j]=-1;
	 for (int i=0;i<s.length();i++)
	 {
		 int temp=0;
		 temp=dat[(int)(s[i])];
		 if (temp>end)
		 {
			 end=temp;
		 }
		 start=i;
		 if ((start-end)>max)
		 {
			 max=start-end;
		 }
		 dat[(int)(s[i])]=i;
	 }
	 	if ((start-end)>max)
		 {
			 max=start-end;
		 }
	 return max;
    }
};
