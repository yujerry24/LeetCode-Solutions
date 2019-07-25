/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/* One of my longest leetcode solutions. Beats 100% of all memory usage for C++ solutions.
* Runtime varies between 8ms to 12ms which is between 75% to 10% faster than all C++ solutions.
* July 24, 2019
* 
*/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        unordered_map<int,int>  storage;
        storage.clear();
        
        int middle = findPeak (mountainArr,0,mountainArr.length()-1, storage);
        
        int leftIndex = binarySearch(mountainArr, 0,middle, target, storage);
        if(leftIndex!=-1) {
        	return leftIndex;
        }
        int rightIndex = rbinarySearch(mountainArr, middle+1, mountainArr.length()-1,target, storage);
        if(rightIndex!=-1) {
        	return rightIndex;
        }
        
        return -1;
    }
    int binarySearch(MountainArray &mountainArr, int l, int r, int x,unordered_map <int,int> storage) { 
	    if (r >= l) { 
	        int mid = l + (r - l) / 2; 
	        int middle = mid;
	        int left = mid-1;
	        int right = mid+1;
	        

	        if(storage.find(middle)!=storage.end()) {
	        	middle=storage.at(middle);
	        } else {
	        	storage.insert({middle, mountainArr.get(middle)});
	        	middle=storage.at(middle);
	        }

	      
	        // If the element is present at the middle 
	        // itself 
	        if (middle == x) 
	            return l + (r - l) / 2; 
	  
	        // If element is smaller than mid, then 
	        // it can only be present in left subarray 
	        if (middle > x) 
	            return binarySearch(mountainArr, l, mid - 1, x, storage); 
	  
	        // Else the element can only be present 
	        // in right subarray 
	        return binarySearch(mountainArr, mid + 1, r, x, storage); 
	    } 
	  
	    // We reach here when element is not 
	    // present in array 
	    return -1; 
	} 
    int rbinarySearch(MountainArray &mountainArr, int l, int r, int x,unordered_map <int,int> storage) { 
	    if (r >= l) { 
	        int mid = l + (r - l) / 2; 
	        int middle = mid;
	        int left = mid-1;
	        int right = mid+1;
	        

	        if(storage.find(middle)!=storage.end()) {
	        	middle=storage.at(middle);
	        } else {
	        	storage.insert({middle, mountainArr.get(middle)});
	        	middle=storage.at(middle);
	        }

	      
	        // If the element is present at the middle 
	        // itself 
	        if (middle == x) 
	            return l + (r - l) / 2; 
	  
	        // If element is smaller than mid, then 
	        // it can only be present in left subarray 
	        if (middle > x) 
	            return binarySearch(mountainArr, mid+1, r, x, storage); 
	  
	        // Else the element can only be present 
	        // in right subarray 
	        return binarySearch(mountainArr, l, mid-1, x, storage); 
	    } 
	  
	    // We reach here when element is not 
	    // present in array 
	    return -1; 
	} 
    int findPeak(MountainArray &mountainArr, int l, int r, unordered_map <int,int>& storage) {
        
        int middle = l+(r-l)/2;

        if(middle == 0) {
            middle =middle+1;
        }else if(middle == mountainArr.length()-1) {
            middle = middle -1;
        }
        int left=middle-1;
        int right=middle+1;
        
        int leftValue;
        int rightValue;
        int middleValue;
        
        if(storage.find(middle)!=storage.end()) {
            middleValue=storage.at(middle);
        } else {
            storage.insert({middle,mountainArr.get(middle)});
            middleValue=storage.at(middle);
        }
   
        if(storage.find(left)!=storage.end()) {
            leftValue=storage.at(left);
        } else {
            storage.insert({left,mountainArr.get(left)});
            leftValue=storage.at(left);
        }
         if(storage.find(right)!=storage.end()) {
            rightValue=storage.at(right);
        } else {
            storage.insert({right,mountainArr.get(right)});
            rightValue=storage.at(right);
        } 
        if(middleValue>leftValue && middleValue<rightValue) {
            return(findPeak(mountainArr,middle+1,r,storage));
            
        }
        else if(middleValue>leftValue && middleValue>rightValue) {
            return middle;
        }
        else {
            return(findPeak(mountainArr,l,middle-1,storage));
        }
        
    
    }
};