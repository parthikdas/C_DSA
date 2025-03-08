package CP_Patterns.sumProblems;

import java.util.HashMap;
// 560 leetcode
public class subarraySumEqualK {
    public static int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1); // Base case (sum=0 occurs once)
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            if (map.containsKey(sum - k)) {
                count += map.get(sum - k);
            }
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}
