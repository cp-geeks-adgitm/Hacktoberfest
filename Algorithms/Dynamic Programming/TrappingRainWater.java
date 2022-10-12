// Java program to find the amount of water trapped
// Trapping Rain Water Problem
class TrappingRainWater {
    public static int trap(int[] bars) {
        int b = bars.length;
        // base case
        if (b <= 2) {
            return 0;
        }
        int water = 0;
        int[] left = new int[b - 1]; // stores left maximum height
        left[0] = Integer.MIN_VALUE;
        // process bars from left to right
        for (int i = 1; i < b - 1; i++) {
            left[i] = Integer.max(left[i - 1], bars[i - 1]);
        }

        int right = Integer.MIN_VALUE; // stores right maximum height
        // process bars from right to left
        for (int i = b - 2; i >= 1; i--) {
            right = Integer.max(right, bars[i + 1]);
            if (Integer.min(left[i], right) > bars[i]) {
                // check if it is possible to store water in the current bar
                water += Integer.min(left[i], right) - bars[i];
            }
        }
        return water;
    }

    // Driver method
    public static void main(String args[]) {
        int[] heights = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        // print the amount of water trapped
        System.out.println("The maximum amount of water that can be trapped is " +
                trap(heights));
    }
}