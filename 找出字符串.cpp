/*
题目描述

有一个排过序的字符串数组，但是其中有插入了一些空字符串，请设计一个算法，找出给定字符串的位置。算法的查找部分的复杂度应该为log级别。
给定一个string数组str,同时给定数组大小n和需要查找的string x，请返回该串的位置(位置从零开始)。
测试样例：
["a","b","","c","","d"],6,"c"
返回：3
*/

class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        // write code here
        int len=n-1;
        int start=0;
        int end=len;
        while(start<=end){
            int m=(start+end)/2;
            int mid_left=m;
            int mid_right=m;
            while(mid_left<=end&&str[mid_left]==""){
                mid_left++;
            } 
            if(str[mid_left]==""){
                while(mid_right>=start&&str[mid_right]==""){
                	mid_right--;
            	} 
                if(str[mid_right]=="") return -1;
                else
                   mid_left=mid_right; 
            }
            if(str[mid_left].compare(x)==0) return mid_left;
            else if(str[mid_left].compare(x)<0) start=mid_left+1;
            else   end=mid_left-1;    
        }
        return -1;
    }
};
