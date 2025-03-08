package specifics_leetcode.String;
/*
 * 345. Reverse Vowels of a String
Solved
Easy

Topics
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
 */
public class revVowelString {
    public String reverseVowels(String s) {
        int i = 0, j = s.length() - 1;
        String vowels = "aeiouAEIOU";
        char[] chars = s.toCharArray();

        while (j > i) {
            if (vowels.indexOf(chars[i]) != -1 && vowels.indexOf(chars[j]) != -1) {
                char temp = chars[i];
                chars[i] = chars[j];
                chars[j] = temp;
                i++;
                j--;
            } 
            if (vowels.indexOf(chars[i]) == -1) {
                i++;
            } if (vowels.indexOf(chars[j]) == -1) {
                j--;
            }
        }

        return new String(chars);
    }

}
