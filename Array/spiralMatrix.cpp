class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        string currentDirection = "right";
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));
        vector<int> order;
        int row = 0; 
                            cout<<"hello"<<endl;

        int column = 0;
        while(row >= 0 && row < matrix.size() && column >= 0 && column < matrix[0].size() && visited[row][column] == false) {
            visited[row][column] = true;
            order.push_back(matrix[row][column]);
            if (currentDirection == "right") {
                if (column + 1 < matrix[0].size() && visited[row][column+1] == false) {
                    column++;
                } else {
                    currentDirection = "bottom";
                    cout<<"hello"<<endl;
                    row++;
                }
            } else if (currentDirection == "bottom") {
                if (row + 1 < matrix.size() && visited[row+1][column] == false) {
                    row++;
                } else {
                    currentDirection = "left";
                    column--;
                }
            } else if (currentDirection == "left") {
                if (column - 1 >= 0 && visited[row][column-1] == false) {
                    column--;
                } else {
                    currentDirection = "up";
                    row--;
                }
            } else if (currentDirection == "up") {
                if (row - 1 >= 0 && visited[row-1][column] == false) {
                    row--;
                } else {
                    currentDirection = "right";
                    column++;
                }
            }
        }
        return order;
    }
};