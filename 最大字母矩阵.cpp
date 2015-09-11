/*
题目描述

有一个单词清单，请设计一个高效算法，计算由清单中单词组成的最大子矩阵，要求矩阵中的行和列都是清单中的单词。
给定一个string数组dic，代表单词清单，同时给定清单的大小n，请返回最大子矩阵的面积。保证单词清单的大小小于等于50，且某一长度的串的数量小于等于12。
测试样例：
["aaa","aaa","aaa","bb","bb"]
返回：9
*/
class AlphaMatrix {
public:
    int findAlphaMatrix(vector<string> dic, int n) {
        // write code here
	int row=0;
	int line=0;
	bool flag_row=true;
	bool flag_line=true;
	while(1){
		int j=0;
		while(flag_row&&j<=line){
			if(row<dic[j].size()) ++j;
			else
				flag_row=false;
		}
		if(flag_row) ++row;
		if(flag_line&&(dic[line].size()>row-1)) {++line;}
		else
			flag_line=false;
		if((!flag_line)&&(!flag_row))  break;
	}
	return row*line;
    }
};
