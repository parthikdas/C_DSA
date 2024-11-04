/*
 * Leetcode 65 valid number
 * Given a string s, return whether s is a valid number.
Run
く
For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-. 9"
, "Ze10", "-903", "3е+7", "+6е-1", "53.593", "-123.456e789", while the following are not valid numbers: "abc", "la", "le", "e3", "992.5", "
"95a54e53"
6", "-+3",
Formally, a valid number is defined using one of the following definitions:
1.⁠ ⁠An integer number followed by an optional exponent.
2.⁠ ⁠A decimal number followed by an optional exponent.
An integer number is defined with an optional sign *- or '+' followed by digits.
A decimal number is defined with an optional sighs or '+' followed by one of the
following definitions:
1.⁠ ⁠Digits followed by a dot '.'
2.⁠ ⁠Digits followed by a dot '. ' followed by digits.
3.⁠ ⁠A dot '•' followed by digits
An exponent is defined with an exponent notation 'e' or 'E' followed by an integer nimhar
the digts are defined as one or more digits.

input : "0" => true , "e" => false , "." => false
 */
package specifics.String;
public class validNumber {
    // slow only beats 8% people
        public boolean isNumber (String s) {
        // Maybe + or -
        // After the sign we have 3 conditons: 1. Dot followed by no
        //                                      2. ⁠No followed by dot
        //                                      3.⁠ ⁠No then dot then no
        // Maybe e followed by maybe sign and no return
        return s.matches("[+-]? ((\\d+(\\.\\d*)?) | (|\\.|\\d+)) ([eE][+-]?\\d+)?");
        }
}
