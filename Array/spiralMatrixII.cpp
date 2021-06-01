class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> visited(n, vector<int>(n));
        string currentDirection = "right";
        int row = 0; 
        int column = 0;
        int counter = 1;
        while(row >= 0 && row < visited.size() && column >= 0 && column < visited[0].size() && visited[row][column] == 0) {
            visited[row][column] = counter;
            counter++;
            if (currentDirection == "right") {
                if (column + 1 < visited[0].size() && visited[row][column+1] == 0) {
                    column++;
                } else {
                    currentDirection = "bottom";
                    row++;
                }
            } else if (currentDirection == "bottom") {
                if (row + 1 < visited.size() && visited[row+1][column] == 0) {
                    row++;
                } else {
                    currentDirection = "left";
                    column--;
                }
            } else if (currentDirection == "left") {
                if (column - 1 >= 0 && visited[row][column-1] == 0) {
                    column--;
                } else {
                    currentDirection = "up";
                    row--;
                }
            } else if (currentDirection == "up") {
                if (row - 1 >= 0 && visited[row-1][column] == 0) {
                    row--;
                } else {
                    currentDirection = "right";
                    column++;
                }
            }
        }
        return visited;
    }
};