class Solution {
    public int binarySearch(int left, int right, int[] nums) {
        System.out.println(left);
        System.out.println(right);
        int leftValue = nums[left];
        int rightValue = nums[right];
        int middle = (right - left) / 2 + left;
        int middleValue = nums[middle];
        if (middle - 1 >= 0 && middleValue > nums[middle - 1] || middle - 1 < 0) {
            if (middle + 1 <= nums.length - 1 && middleValue > nums[middle + 1] || middle + 1 >= nums.length) {
                return middle;
            }
        }
        if (left == right || middle == left || middle == right) {
            return -1;
        }
        if (middleValue <= rightValue) {
            return binarySearch(middle, right, nums);
        } else if (middleValue <= leftValue) {
            return binarySearch(left, middle, nums);
        } else {
            int one = binarySearch(left, middle, nums);
            int two = binarySearch(middle, right, nums);
            if (one != -1) {
                return one;
            }
            return two;
        }
    }

    public int findPeakElement(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[nums.length - 1] > nums[nums.length - 2]) {
            return nums.length - 1;
        }
        return binarySearch(0, nums.length - 1, nums);

    }
}