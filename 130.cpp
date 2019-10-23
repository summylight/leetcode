#include<iostream>
#include <vector>
using namespace std;

void infect(vector<vector<char>>& board,int row, int column){
    board[row][column]='Y';
    int size = board.size();
    if(row-1>=0){
        if(board[row-1][column]=='O')
            infect(board,row-1,column);
    }
    if(row+1<size){
        if(board[row+1][column]=='O')
            infect(board,row+1,column);
    }
    if(column-1>=0){
        if(board[row][column-1]=='O')
            infect(board,row,column-1);
    }
    if(column+1<size){
        if(board[row][column+1]=='O')
            infect(board,row,column+1);
    }

}
void solve(vector<vector<char>>& board) {
    int size = board.size();
    for(int i=0;i!=size;++i){
        if(board[i][0]=='O') infect(board,i,0);
        if(board[i][size-1]=='O') infect(board,i,size-1);
    }

    for(int i=0;i!=size;++i){
        if(board[0][i]=='O') infect(board,0,i);
        if(board[size-1][i]=='O') infect(board,size-1,i);
    }

    for(int i=0;i!=size;++i){
        for(int j=0;j!=size;++j){
            if(board[i][j]=='Y') board[i][j]='O';
            else if(board[i][j]=='O') board[i][j]='X';
        }
    }
}

int main(){
    vector<vector<char>> board;
    board.push_back({'O'});
    solve(board);
}