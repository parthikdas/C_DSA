package CP_Patterns;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class trying {
    // Brute Force approach of creating all possible combinations
    public void bruteString() {
        String s = "Helolk";
        for(int i =0;i<s.length();i++) {
            String l = "";
            for(int j = i; j <s.length();j++) {
                l += s.charAt(j);
                System.out.println(l);
            }
        }
    }
    public static void bruteArray() {
        int a[] = {1,2,3};
        for(int i = 0 ; i<a.length;i++) {
            for(int j=i;j<a.length;j++) {
                System.out.println(Arrays.toString(Arrays.copyOfRange(a, i,j+1)));
            }
        }

    }
    // Medium questions
    // 1. Longest Substring without reapeating chars - HashSet and sliding
    public static int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            while (set.contains(s.charAt(right))) {
                set.remove(s.charAt(left));
                left++;
            }
            set.add(s.charAt(right));
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
    // 2. Max Sum Subarray - Kadane
    public static int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            maxSum = Math.max(maxSum, currentSum);
            if (currentSum < 0) currentSum = 0;
        }
        return maxSum;
    }
    // Hard Questions

    
    public static void main(String[] args) {
        // bruteArray();
        int[] a=new int[2];
        PriorityQueue<Integer> aa = new PriorityQueue<>(Comparator.reverseOrder());
        aa.add(9);
        aa.add(2);
        aa.add(1);
        System.out.println(aa.poll());
    }
}
