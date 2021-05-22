class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix="";
        if(strs.length==1) {
            return strs[0];
        }
        if(strs.length==0) {
            return prefix;
        }
        for(int i=0; i<strs[0].length(); i++) {
            for(int j=1; j<strs.length; j++) {
                if(i+1>strs[j].length()) {
                    return prefix;
                }
                if(strs[0].charAt(i)!=strs[j].charAt(i)) {
                    return prefix;
                }
                if(strs[0].charAt(i)==strs[j].charAt(i) && j==strs.length-1) {
                    prefix+=strs[0].charAt(i);
                }
            }
        }
        return prefix;
    }
}