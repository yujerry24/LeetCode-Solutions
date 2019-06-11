class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> returnValue;
        int searchIndex=0;
        for(int i=0; i<nums.size(); i++) {
            if(i>0 && nums[i]!=nums[i-1]) {
                if(returnValue.size()==0) {
                    searchIndex=0;
                }
                else {
                    searchIndex=returnValue.size()-1;
                }
            }
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int beginIndex=i+1;
            int endIndex=nums.size()-1;
            while(beginIndex<endIndex) {
                if(nums[i]+nums[beginIndex]+nums[endIndex]==0) {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[beginIndex]);
                    temp.push_back(nums[endIndex]);
                    
                    if(returnValue.size()==0) {
                        returnValue.push_back(temp);
                        
                    }
                    for(int a=searchIndex; a<returnValue.size(); a++) {
                        if(temp==returnValue.at(a)) {
                            break;
                        }
                        if(a==returnValue.size()-1) {
                            returnValue.push_back(temp);
                        }
                    }
                    beginIndex++;
                    endIndex--;
                }
                else if(nums[i]+nums[beginIndex]+nums[endIndex]>0) {
                    endIndex--;
                }
                else {
                    beginIndex++;
                }
            }
           
        }
        return returnValue;
    }
};