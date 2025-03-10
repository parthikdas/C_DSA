package CP_Patterns.stack;

import java.util.Stack;

public class next {
    public int[] nextGreaterElement(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, -1); // Default value if no greater element is found
        Stack<Integer> stack = new Stack<>(); // Stores indices

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
                result[stack.pop()] = nums[i];
            }
            stack.push(i);
        }
        return result;
    }
    public int[] nextSmallerElement(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);
        Stack<Integer> stack = new Stack<>(); 

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                result[stack.pop()] = nums[i];
            }
            stack.push(i);
        }
        return result;
    }

    public int largestRectangleArea(int[] heights) {// O(n),O(n)
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0, n = heights.length;
        for (int i = 0; i <= n; i++) {
            while (!stack.isEmpty() && (i == n || heights[i] < heights[stack.peek()])) {
                int h = heights[stack.pop()];
                int w = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, h * w);
            }
            stack.push(i);
        }
        return maxArea;
    }
    public int trap(int[] height) { // O(n),O(1)
        int l = 0, r = height.length - 1, leftMax = 0, rightMax = 0, res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                leftMax = Math.max(leftMax, height[l]);
                res += leftMax - height[l++];
            } else {
                rightMax = Math.max(rightMax, height[r]);
                res += rightMax - height[r--];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        MonotonicStack ms = new MonotonicStack();
        int[] nums = {2, 1, 2, 4, 3};
        System.out.println(Arrays.toString(ms.nextGreaterElement(nums))); // Output: [4, 2, 4, -1, -1]
    }
}