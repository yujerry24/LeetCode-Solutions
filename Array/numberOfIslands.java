class Solution {
    public void deleteIsland(char[][] grid, int row, int column) {
        if (row >= 0 && row < grid.length && column >= 0 && column < grid[0].length) {
            if (grid[row][column] == '0') {
                return;
            } else {
                grid[row][column] = '0';
                deleteIsland(grid, row + 1, column);
                deleteIsland(grid, row - 1, column);
                deleteIsland(grid, row, column + 1);
                deleteIsland(grid, row, column - 1);
            }
        }
        return;
    }

    public int numIslands(char[][] grid) {
        int numberOfIslands = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    numberOfIslands++;
                    deleteIsland(grid, i, j);
                }
            }
        }
        return numberOfIslands;
    }
}