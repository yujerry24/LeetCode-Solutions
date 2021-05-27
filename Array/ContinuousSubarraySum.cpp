//Finished Solution
//Date of Completion: June 5th, 2019

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sumArray;
        vector<int> tempArray;
        
            
            for(int i=0; i<nums.size()-1; i++) {
                if(nums.at(i)==nums.at(i+1) && nums.at(i)==0) {
                    return true;
                }
            }
            
            
        if(k==0) {
            return false;
        }
        if(k==1) {
            if(nums.size()>=2) {
                return true;
            }
            return false;
        }
        int sum=0;
        int tempSum=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums.at(i);
            tempSum+=nums.at(i);
            sum=sum%k;
            if(sum==0 && i!=0) {
                return true;
            }
            sumArray.push_back(sum);
            tempArray.push_back(tempSum);
           
            
        }
        
        for(int i=0; i<sumArray.size(); i++) {
            for(int j=i+1; j<sumArray.size(); j++) {
                if(sumArray.at(i)==sumArray.at(j) && tempArray.at(i)!=tempArray.at(j)) {
                    if(i+1==j) {
                        if((nums.at(i)%k==0 && nums.at(j) %k==0) || (nums.at(i)%k!=0 && nums.at(j)%k!=0)) {
                            return true;
                        }
                        
                    }
                    else {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};