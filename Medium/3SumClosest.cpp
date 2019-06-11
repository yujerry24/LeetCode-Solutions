class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            cout<<nums[i]<<endl;
        }
        int sum=nums[0]+nums[1]+nums[2];
        if(sum==target) {
            return sum;
        }
        for(int i=0; i<nums.size()-2; i++) {
            int beginIndex=i+1;
            int endIndex= nums.size()-1;
           
            while(beginIndex<endIndex) {
                if(abs(nums[i]+nums[beginIndex]+nums[endIndex]-target)<abs(sum-target)) {
                    sum=nums[i]+nums[beginIndex]+nums[endIndex];
                    if(sum==target) {
                        return sum;
                    }
                    
                }
                if((nums[i]+nums[beginIndex]+nums[endIndex]<target)) {
                    beginIndex++;
                }
                else {
                    endIndex--;
                }
            }
        }
        return sum;
    }
};
