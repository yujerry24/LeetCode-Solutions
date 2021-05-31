class Solution {
    public void rotateInFour(int[][] matrix, int row, int column) {
        int length = matrix.length - 1;
        int temp = matrix[row][column];
        int temp2 = matrix[column][length - row];
        int temp3 = matrix[length - row][length - column];
        int temp4 = matrix[length - column][row];
        matrix[column][length - row] = temp;
        matrix[length - row][length - column] = temp2;
        matrix[length - column][row] = temp3;
        matrix[row][column] = temp4;
    }

    public void rotate(int[][] matrix) {
        for (int i = 0; i < (matrix.length + 1) / 2; i++) {
            for (int j = 0; j < matrix[0].length / 2; j++) {
                rotateInFour(matrix, i, j);
            }
        }

    }
}