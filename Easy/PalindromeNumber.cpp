class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        if(x<0) {
            return false;
        }
        int reversedValue=0;
        int counter=0;
        int copy=x;
        while(copy>0) {
            counter++;
            copy/=10;
        }
        counter--;
        while(x>0) {
            if(x%10>0) {
            reversedValue+=(x%10)*pow(10,counter);
            
            }
            counter--;
            x/=10;
          //  cout<<reversedValue<<endl;
        }
        if(reversedValue==original) {
            return true;
        }
        
        return false;
    }
};