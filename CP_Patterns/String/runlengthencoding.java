package CP_Patterns.String;

import java.util.HashMap;

public class runlengthencoding {
    public String usingLinear(String str) { //O(n^2) - time, O(1) - space as only stringbuilder
        String s = "aaabbbsbccc"; // 3a3b1s1b3c
        StringBuilder ss = new StringBuilder("");
        int i = 0;
        while(i<s.length()) {
            int j = 1;
            if(s.charAt(i) == s.charAt(i+1)) {
                int k = 0;
                while(k<s.length() && s.charAt(k) == s.charAt(k+1)) {j++;k++;}
            }
            ss.append(""+j+s.charAt(i));
            i+=j;
        }
        return ss.toString();
    }
    public String usingMap(String str) { // O(n) - time, O(n) as map used
        String s = "aaabbbsbccc"; // 3a3b1s1b3c
        HashMap<Character, Integer> map = new HashMap<>();
       StringBuilder ss = new StringBuilder("");
       for(int i = 0;i<s.length();i++) {
        char ch = s.charAt(i);
        if(!map.containsKey(ch) && i>0) {
            ss.append(""+map.get(s.charAt(i-1)) + s.charAt(i-1));
            map.remove(s.charAt(i-1));
        }
        map.put(ch, map.getOrDefault(ch, 0)+1);
       }
        return ss.toString();
    }
}
