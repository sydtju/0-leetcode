
/*
题目描述

对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。
给定图中的两个结点的指针UndirectedGraphNode* a,UndirectedGraphNode* b(请不要在意数据类型，图是有向图),请返回一个bool，
代表两点之间是否存在一条路径(a到b或b到a)。
*/
/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
public:
    bool check_position(UndirectedGraphNode* a, UndirectedGraphNode* b){
		if(a==b) return true;
        int len=(int)(a->neighbors).size();
        for(int i=0;i<len;++i){
			return 	check_position((a->neighbors)[i],b);
        }
        return false;
    }
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if(a==NULL||b==NULL) return false;
		return check_position(a,b)||check_position(b,a);
    }
};
