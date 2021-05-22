class Solution {
    public String longestPalindrome(String s) {
        boolean [][] isPalindrome = new boolean [s.length()][s.length()];
        String longestPalindrome = s.substring(0,1);
        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
        }
        for (int j = 1; j < s.length(); j++) {
            for (int i = 0; i < s.length(); i++) {
                if (i+j < s.length()) {
                if (j==1) {
                    if (s.charAt(i) == s.charAt(i+j)) {
                        isPalindrome[i][i+j] = true;
                        if (j+1>longestPalindrome.length()) {
                            longestPalindrome = s.substring(i,i+j+1);
                        }
                    }
                } else {
                    if (isPalindrome[i+1][i+j-1] && s.charAt(i) == s.charAt(i+j)) {
                        isPalindrome[i][i+j] = true;
                        if (j+1>longestPalindrome.length()) {
                            longestPalindrome = s.substring(i,i+j+1);
                        }
                    } else {
                        isPalindrome[i][i+j] = false;
                    }
                }
                }
            }
        }
        return longestPalindrome;
    }
}