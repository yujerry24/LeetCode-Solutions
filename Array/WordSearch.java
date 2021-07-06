class Solution {
public:
    void clearBoard(vector<vector<bool>> & visited) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                visited[i][j] = false;
            }
        }
    }
    bool backtrack(int row, int col, string word, vector<vector<char>>& board, vector<vector<bool>> & visited) {
        if (word == "") {
            return true;
        }
        if (row < 0 || row >= board.size()) {
            return false;
        }
        if (col < 0 || col >= board[0].size()) {
            return false;
        }
        if (visited[row][col]) {
            return false;
        }
        if (board[row][col] != word[0]) {
            return false;
        }
        visited[row][col] = true;
        if (backtrack(row+1, col, word.substr(1, word.size()), board, visited)) {
            return true;
        }
        if (backtrack(row-1, col, word.substr(1, word.size()), board, visited)) {
            return true;
        }
        if (backtrack(row, col+1, word.substr(1, word.size()), board, visited)) {
            return true;
        }
        if (backtrack(row, col-1, word.substr(1, word.size()), board, visited)) {
            return true;
        }
         visited[row][col] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool> > visited(board.size(),vector<bool>(board.at(0).size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                 if (backtrack(i,j, word, board, visited)) {
                     return true;
                 } else {
                     clearBoard(visited);
                 }
            }
        }
        return false;
    }
};