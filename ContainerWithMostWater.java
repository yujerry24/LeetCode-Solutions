import java.lang.Math;

class Solution {
    public int maxArea(int[] height) {
        int maxArea=0;
        int currentArea=0;
        for(int i=0; i<height.length-1; i++) {
            for(int j=i+1; j<height.length; j++) {
                currentArea=Math.min(height[i],height[j])*Math.abs(j-i);
                if(currentArea>maxArea) {
                    maxArea=currentArea;
                }
            }
        }
        return maxArea;
        
    }
}