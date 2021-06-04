class Solution {
    boolean isRobotBounded(String instructions) {
        String currentDirection = "north";
        int yChange = 0;
        int xChange = 0;
        for (int i = 0; i < instructions.length(); i++) {
            if (instructions.charAt(i) == 'G') {
                if (currentDirection.equals("north")) {
                    yChange++;
                } else if (currentDirection.equals("east")) {
                    xChange++;
                } else if (currentDirection.equals("west")) {
                    xChange--;
                } else if (currentDirection.equals("south")) {
                    yChange--;
                }
            } else if (instructions.charAt(i) == 'L') {
                if (currentDirection.equals("north")) {
                    currentDirection = "west";
                } else if (currentDirection.equals("east")) {
                    currentDirection = "north";
                } else if (currentDirection.equals("west")) {
                    currentDirection = "south";
                } else if (currentDirection.equals("south")) {
                    currentDirection = "east";
                }
            } else if (instructions.charAt(i) == 'R') {
                if (currentDirection.equals("north")) {
                    currentDirection = "east";
                } else if (currentDirection.equals("east")) {
                    currentDirection = "south";
                } else if (currentDirection.equals("west")) {
                    currentDirection = "north";
                } else if (currentDirection.equals("south")) {
                    currentDirection = "west";
                }
            }
        }
        if (xChange == 0 && yChange == 0) {
            return true;
        }

        if (currentDirection != "north") {
            return true;
        }
        return false;
    }
}