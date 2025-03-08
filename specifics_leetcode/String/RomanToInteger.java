/*
 * 13. Roman to Integer
Solved
Easy

Topics
Companies

Hint
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */
/* MY APPROACH but bad solution only beats 8%
class Solution {
    public int romanToInt(String s) {
        Map<String, Integer> map = new HashMap<>(){{
            put("M", 1000);put("CM", 900);
            put("D", 500);put("CD", 400);
            put("C", 100);put("XC", 90);
            put("L", 50);put("XL", 40);
            put("X", 10);put("IX", 9);
            put("V", 5);put("IV", 4);put("I", 1); 
        }};
        int ans = 0,i=0;
        while(i<s.length()) {
            if(i<s.length()-1 && map.containsKey(""+s.charAt(i) + s.charAt(i+1))) {
                ans += map.get(""+s.charAt(i) + s.charAt(i+1));
                i+=2;
            } else if(map.containsKey(""+s.charAt(i))) {
                ans += map.get(""+s.charAt(i));
                i+=1;
            }
        }
        return ans;
    }
}
*/
// CHATGPT SOLUTION
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('M', 1000);
        map.put('D', 500);
        map.put('C', 100);
        map.put('L', 50);
        map.put('X', 10);
        map.put('V', 5);
        map.put('I', 1);
        
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int value = map.get(s.charAt(i));
            // Check if the current value should be subtracted
            if (i < n - 1 && value < map.get(s.charAt(i + 1))) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        
        return ans;
    }
}