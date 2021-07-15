class Solution {
    public String customSortString(String order, String str) {
        HashMap<String, Integer> map = new HashMap<>();
        String returnString = "";
        for (int i = 0; i < str.length(); i++) {
            map.put(Character.toString(str.charAt(i)), map.getOrDefault(Character.toString(str.charAt(i)), 0) + 1);
        }
        for (int i = 0; i < order.length(); i++) {
            if (map.containsKey(Character.toString(order.charAt(i)))) {
                for (int j = 0; j < map.get(Character.toString(order.charAt(i))); j++) {
                    returnString += order.charAt(i);
                }

            }
        }
        for (int i = 0; i < str.length(); i++) {
            if (order.indexOf(Character.toString(str.charAt(i))) == -1) {
                returnString += str.charAt(i);
            }
        }
        return returnString;
    }
}