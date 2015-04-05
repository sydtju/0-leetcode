//解决两个数之和等于目标值 并且返回所有满足条件的下标组合（小标是基-1的）  使用map 时间复杂度是nlog(n)
//author：sydtju
//date:2015.04.05
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> maptest;
        vector<int> temp;
        vector<int>::iterator it;
        map<int,int>::iterator it_temp;
        int i=0;
        maptest.insert(pair<int,int>(numbers[0],0));
        for(it=numbers.begin()+1,i=1;it!=numbers.end();i++,it++){
            it_temp=maptest.find(target-(*it));
            if(it_temp!=maptest.end()){
                temp.push_back(it_temp->second+1);
                temp.push_back(i+1);
            }
            else{
                maptest.insert(pair<int,int>(numbers[i],i));
            }
        }
        return temp;
    }
};
