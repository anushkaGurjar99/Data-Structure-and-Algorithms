/*
 * Author : Anushka Gurjar
 * Date   : June 2020
 * flags  : -std=c++14
*/

// Problem Statement: https://leetcode.com/problems/game-of-life/

class Solution{
public:
    void gameOfLife(vector<vector<int>>& board){
        
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> dir = {{1, 1}, {-1, -1}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {-1, 1}};
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                int neighborsCount = 0;
                for(auto itr: dir){
                    if(isValid(board, r + itr[0], c + itr[1]))
                        neighborsCount++;
                    if(neighborsCount > 3)
                        break;
                }
                
                if(board[r][c] == 1 && (neighborsCount < 2 || neighborsCount > 3))
                    board[r][c] = -1;
                else if(board[r][c] == 0 && (neighborsCount == 3))
                    board[r][c] = 2;
            }
        }
        
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(board[r][c] == -1)
                    board[r][c] = 0;
                else if(board[r][c] == 2)
                    board[r][c] = 1;
            }
        }
    }
    
    bool isValid(vector<vector<int>>& board, int row, int col){
        if(row < 0 || row >= board.size())
            return 0;
        
        if(col < 0 || col >= board[0].size())
            return 0;
        
        if(abs(board[row][col]) == 1)
            return true;
        
        return false;
    }
};


/*
Since we can't create the new array so we use a trick
    Pass1: Encode the cell value if needed (-1 or 2)
    Pass2: Decode and restore the encoded value
    
Encoding:-
    If cell value is 1 and it is invalid
        replace it with -1
    If cell value is 0 and it is invalid
        replace it with 2
        
Note: 
Invalid is calculated by number of neighbors
Neighbor cell can have 1 or -1 cell-value.
*/
