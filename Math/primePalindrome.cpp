class Solution {
public:
    int primePalindrome(int N) {
        int counter=N;
        if(N==1) {
            return 2;
        }
        while(true) {
            if(isPrime(counter) && counter==reverse(counter)) {
                return counter;
            }
            if(counter>=10000000 && counter<100000000) {
                counter=100000000;
            }
            counter++;
        }
    }
    bool isPrime(int N) {
        for(int i=2; i*i<=N; i++) {
            if(i==1) {
                continue;
            }
            if(N%i==0) {
                return false;
            }
        }
        return true;
    }
    int reverse(int N) {
        int ans=0;
        while(N>0) {
            ans=10*ans+(N%10);
            N/=10;
        }
        return ans;
    }
};