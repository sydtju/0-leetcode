/*
题目描述

请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
给定一个int[] numbers(C++中为vector<int>)，其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
测试样例：
[1,2,3,4,5]
返回：[5,4,3,2,1]
*/

class TwoStacks {
public:
vector<int> twoStacksSort(vector<int> numbers) {
	// write code here
	//使用插入排序
	vector<int>::iterator  it;
	vector<int> res;
	vector<int>  temp;
	it=numbers.begin();
	while(it!=numbers.end()){
		if(res.size()==0) {res.push_back(*it);++it;				
		while(temp.size())
		{
			res.push_back(temp.back());
			temp.pop_back();
		}
		}
		else
		{
			if(*it<res.back()){
				temp.push_back(res.back());
				res.pop_back();
			}
			else
			{
				res.push_back(*it);
				++it;
				while(temp.size())
				{
					res.push_back(temp.back());
					temp.pop_back();
				}
			}
		}

	}
	while (res.size())
	{
		temp.push_back(res.back());
		res.pop_back();
	}
	return temp;
}
};
