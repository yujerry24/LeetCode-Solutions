class Solution {
    int[] dpArray;

    public int helperDecodeWays(int index, String s) {
        if (index < s.length() && dpArray[index] != -1) {
            return dpArray[index];
        }
        if (index == s.length()) {
            return 1;
        }

        if (s.charAt(index) == '0') {
            return 0;
        }

        if (index == s.length() - 1) {
            return 1;
        }

        dpArray[index] = helperDecodeWays(index + 1, s);
        if (Integer.parseInt(s.substring(index, index + 2)) <= 26) {
            dpArray[index] += helperDecodeWays(index + 2, s);
        }
        return dpArray[index];
    }

    public int numDecodings(String s) {
        dpArray = new int[s.length()];
        for (int i = 0; i < dpArray.length; i++) {
            dpArray[i] = -1;
        }
        dpArray[0] = helperDecodeWays(0, s);
        return dpArray[0];
    }
}