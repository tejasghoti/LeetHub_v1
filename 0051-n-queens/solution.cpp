class Solution {
public:
    vector<vector<string>> result;
    int size;
    
    void backtrack(int row, vector<string>& board, 
                   unordered_set<int>& cols,
                   unordered_set<int>& diag1,    // row - col
                   unordered_set<int>& diag2) {  // row + col
        
        // Base case: all queens placed successfully
        if (row == size) {
            result.push_back(board);
            return;
        }
        
        // Try placing queen in each column of current row
        for (int col = 0; col < size; col++) {
            // Check if this position is under attack
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;  // Skip invalid positions
            }
            
            // Place the queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            // Recurse to next row
            backtrack(row + 1, board, cols, diag1, diag2);
            
            // Backtrack: remove the queen
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<string> board(n, string(n, '.'));  // Initialize empty board
        unordered_set<int> cols, diag1, diag2;
        
        backtrack(0, board, cols, diag1, diag2);
        
        return result;
    }
};
