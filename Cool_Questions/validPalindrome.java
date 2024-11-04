/*
 * Leetcode 125 valid palindrome
 * Input : " A man, a plan, a canal: Panama" output true
 * 
 * public boolean isPali(String s) {
 *  String newString = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
 * int i=0, j=newStirng.length()-1;
 * while(j>i) {
 *  if(newString.chat(i++) != newString.charAt(j--)) return false;
 * }
 * return true;
 */