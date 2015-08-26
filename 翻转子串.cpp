/*
题目描述

假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
测试样例：
"Hello world","worldhello "
返回：false
"waterbottle","erbottlewat"
返回：true
*/
class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
        int len1=s1.length();
        int len2=s2.length();
		if(len1!=len2) return false;
        if(len1<=0||len2<=0) return false;
        s1=s1+s1;
        if(s1.find(s2)==-1)return false;
        else
            return true;
    }
};
/*
//类似与字符串移位包含的问题。
以s1=ABCD为例，先分析对s1进行循环移位之后的结果，如下所示：
ABCD->BCDA->CDAB->DABC->ABCD....
假设我们把前面移走的数据进行保留，会发现如下的规律： 
ABCD->ABCDA-> ABCDAB->ABCDABC->ABCDABCD,因此可以看出s1的循环移位所得到的字符串将是字符串s1s1的子字符串，如果s2由s1循环移位得到，则说明s2一定在s1s1上。
*/
