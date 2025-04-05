package CP_Patterns.bitmask;
import java.util.*;
/*
 A subarray is a contiguous portion of an array. This means the elements in the subarray are consecutive in the original array.
 A subset is any selection of elements from the original array, without needing to be contiguous.

 Subset:
 ✅ If n ≤ 20:
    Use Bitmasking
        Why? There are 2ⁿ subsets. Bitmasking runs in O(2ⁿ × n), which is fast enough for n ≤ 20.
        Usage: Subset sums, XORs, DP, etc.
        
 🚫 If n > 20:
        Avoid generating all subsets explicitly unless needed.
        Instead, use one of the following:
    1. Backtracking with Pruning
        Useful when you don’t need all subsets, just some with certain properties (e.g., target sum, k subsets).
        You stop early when the condition fails.
        Use Case: Leetcode 698 (Partition to K Equal Sum Subsets)
    2. Meet-in-the-Middle (For 20 < n ≤ 40)
        Split array into two halves.
        Generate all subset sums of both halves (2¹⁰ ~ 2²⁰ each).
        Combine smartly using binary search or hashmaps.
        Use Case: Subset sum equals target, max weight, etc.
        Example Problem: Leetcode 1755 - Closest Subsequence Sum
    3. Greedy / DP Approaches
        If problem only asks for "is possible" or "count", use DP with compression instead of full subsets.
        Ex: dp[mask] or dp[i][mask] to store optimal values.
        Avoid materializing all subsets.

 🧠 Summary Table
    Size of n	    Best Method	            Why
    n ≤ 20	        Bitmasking	            Fastest, clean
    20 < n ≤ 40	    Meet-in-the-middle	    Avoids full 2ⁿ
    n > 40	        DP/Greedy/Heuristics	Subsets are too big
*/
public class subArray_subSet {
    // subarray
    public static List<List<Integer>> getAllSubarrays(int[] arr) { // O(n^2)
        List<List<Integer>> subarrays = new ArrayList<>();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            List<Integer> subarray = new ArrayList<>();
            for (int j = i; j < n; j++) {
                subarray.add(arr[j]);
                subarrays.add(new ArrayList<>(subarray)); // Adding every state of the list
            }
        }
        return subarrays;
    }

    public static List<List<Integer>> generateSubsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;

        for (int mask = 0; mask < (1 << n); mask++) {
            List<Integer> subset = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    subset.add(nums[i]);
                }
            }
            result.add(subset);
        }

        return result;
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        List<List<Integer>> result = getAllSubarrays(arr);
        for (List<Integer> sub : result) {
            System.out.println(sub);
        }
    }
}
