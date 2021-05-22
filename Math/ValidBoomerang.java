class Solution {
    public boolean isBoomerang(int[][] points) {                                                                            if(points[0][0]==points[1][0] && points[0][1]==points[1][1]) {
            return false;
        }
        if(points[0][0]==points[2][0] && points[0][1]==points[2][1]) {
            return false;
        }
        if(points[1][0]==points[2][0] && points[1][1]==points[2][1]) {
            return false;
        }
        double slope1=(points[1][1]-points[0][1])/1.0/(points[1][0]-points[0][0]);
        double slope2=(points[2][1]-points[1][1])/1.0/(points[2][0]-points[1][0]);
        if(slope1==slope2) {
            return false;
        }
        return true;
    }
}