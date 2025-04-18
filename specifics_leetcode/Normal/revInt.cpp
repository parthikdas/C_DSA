package specifics_leetcode.Normal;
/*
 * 7. Reverse Integer
Solved
Medium

Topics
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
 */
    class Solution {
        public:
            int reverse(int x) {
                int sum = 0;
                while(x) {
                    if(sum>INT_MAX/10 || sum<INT_MIN/10) return 0;
                    sum = sum*10 + x%10;
                    x/=10;
                }
                return sum;
            }
        };
// used if(sum>INT_MAX/10 || sum<INT_MIN/10) return 0; 
// As we are doing math operations where we do *10 so to prevent the limit exceed of INT we do this.