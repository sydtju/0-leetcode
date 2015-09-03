/*
题目描述

对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true

*/

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        if(board[1][1]==1){
            if((board[0][0]==1&&board[2][2]==1)||(board[0][2]==1&&board[2][0]==1)||(board[0][1]==1&&board[2][1]==1)||(board[1][0]==1&&board[1][2]==1))
                return true;
            else
                return false;
        }
        else{
         	if((board[0][0]==1&&board[0][1]==1&&board[0][2]==1)) return true;
            else if((board[2][0]==1&&board[2][1]==1&&board[2][2]==1))  return true;
            else  if((board[0][0]==1&&board[1][0]==1&&board[2][0]==1))  return true;
            else  if((board[0][2]==1&&board[1][2]==1&&board[2][2]==1))  return true;
            else  return false;
        }
    }
};
