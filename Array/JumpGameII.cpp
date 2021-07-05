

class Solution {
public:
    int jump(vector<int>& nums) {
        int currentPosition = 0;
        int nextPosition = 0;
        int farthestPosition = 0;
        int jumps = 0;
        while (currentPosition < nums.size() -1 ) {
            for (int i = currentPosition+1; i <= currentPosition + nums.at(currentPosition); i++) {
                if (i >= nums.size()) {
                    continue;
                } else {
                    if (i == nums.size()-1) {
                        nextPosition = nums.size()-1;
                    }
                if (i + nums[i]> farthestPosition) {
                    farthestPosition = i + nums[i];
                    nextPosition = i;
                }
            
                }
            }
            currentPosition = nextPosition;
            farthestPosition = 0;
            jumps++;
        }
        return jumps;
    }
};