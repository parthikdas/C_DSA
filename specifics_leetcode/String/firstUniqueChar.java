package specifics_leetcode.String;
/*
 * 387. First Unique Character in a String
Solved
Easy

Topics
Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
 */
public class firstUniqueChar {
    public int firstUniqChar(String s) {
        //     Map<Character, Integer> map = new LinkedHashMap<>();
        //     for(int i=0;i<s.length();i++) {
        //         map.put(ch, map.getOrDefault(s.charAt(i), 0) + 1);
        //     }
        //     for(Map.Entry<Character, Integer> e : map.entrySet()) {
        //         if(e.getValue() == 1) return s.indexOf(e.getKey());
        //     }
        //    return -1;
            int a[] = new int[26], n=s.length();
            for(int i=0;i<n;i++) a[s.charAt(i)-'a']++;
            for(int i=0;i<n;i++) if(a[s.charAt(i)-'a'] == 1) return i;
            return -1;
        }
    
}
