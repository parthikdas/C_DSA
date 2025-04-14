package CP_Patterns.Backtrack;

import java.util.ArrayList;
import java.util.List;
/*
 Question : U have a matrix and u need to go from start(0,0) to destination(n,n) and print all the possible paths
 Cases covered below : 1. Normal all path 00 to nn
                       2. Matrix having obstacle
                       3. Min cost path : show path and cost
                       4. Custom destination
 */
public class allPath {
    // When we dont have any obstacles, remove later visited we dont need it here
    private static void recur(int[][] a, boolean[][] visited, List<String> ways, int i, int j, String s) {
        if(i<0 || i>=a.length || j<0 || j>=a.length || visited[i][j]) return;
        // Check if we reached the bottom-right corner
        if(i == a.length-1 && j == a.length-1) {
            ways.add(s);
            return;
        }
        // Mark the cell as visited
        visited[i][j] = true;
        // Explore all four directions
        if(i+1<a.length) recur(a, visited, ways, i+1, j, s+'D');
        if(i-1>=0) recur(a, visited, ways, i-1, j, s+'U');
        if(j+1<a.length) recur(a, visited, ways, i, j+1, s+'R');
        if(j-1>=0) recur(a, visited, ways, i, j-1, s+'L');
        // Backtrack: unmark the cell as visited
        visited[i][j] = false; // unmarking the cell after exploring all possible paths from that cell. 
    }

    // -------------------------------------------------------------------------------

    // When we have obstacles
    private static void recur(int[][] a, List<String> ways, int i, int j, String s) {
        if(i<0 || i>=a.length || j<0 || j>=a.length || a[i][j] == 1 || a[i][j] == -1) return;
        // Check if we reached the bottom-right corner
        if(i == a.length-1 && j == a.length-1) {
            ways.add(s);
            return;
        }
        // Mark the cell as visited
        a[i][j] = 1;
        // Explore all four directions
        if(i+1<a.length) recur(a, ways, i+1, j, s+'D');
        if(i-1>=0) recur(a, ways, i-1, j, s+'U');
        if(j+1<a.length) recur(a, ways, i, j+1, s+'R');
        if(j-1>=0) recur(a, ways, i, j-1, s+'L');
        // Backtrack: unmark the cell as visited
        a[i][j] = 0; // unmarking the cell after exploring all possible paths from that cell. 
    }

    // -------------------------------------------------------------------------------

    // Get the min cost of traveling to location and we may have obstacles
    static int min = Integer.MAX_VALUE;
    static String path = "";
    private static void recur1(int[][] a, boolean[][] visited, int i, int j, String s, int cost) {
        if(i<0 || i>=a.length || j<0 || j>=a.length || visited[i][j] || a[i][j] == -1) return;
        // Check if we reached the bottom-right corner
        if(i == a.length-1 && j == a.length-1) {
            if(cost < min) {
                min = cost;
                path = s;
            }
            return;
        }
        // Mark the cell as visited
        visited[i][j] = true;
        cost += a[i][j];
        // Explore all four directions
        if(i+1<a.length) recur1(a, visited, i+1, j, s+'D', cost);
        if(i-1>=0) recur1(a, visited, i-1, j, s+'U', cost);
        if(j+1<a.length) recur1(a, visited, i, j+1, s+'R', cost);
        if(j-1>=0) recur1(a, visited, i, j-1, s+'L', cost);
        // Backtrack: unmark the cell as visited
        visited[i][j] = false; // unmarking the cell after exploring all possible paths from that cell. 
    }

    // -------------------------------------------------------------------------------

    // When we have custom destination
    private static void recur2(int[][] a, List<String> ways, String s, int i, int j, int x, int y) {
        if(i < 0 || i >= a.length || j < 0 || j >= a.length || a[i][j] == 1 || a[i][j] == -1) return;
        if(i == x && j == y) {
            ways.add(s);
            return;
        }
        a[i][j] = 1;
        if(i+1<a.length) recur2(a, ways, s+'D', i+1, j, x, y);
        if(i-1>=0) recur2(a, ways, s+'U', i-1, j, x, y);
        if(j+1<a.length) recur2(a, ways, s+'R', i, j+1, x, y);
        if(j-1>=0) recur2(a, ways, s+'L', i, j-1, x, y);
        a[i][j] = 0;
    }





    public static void main(String[] args) {
        int n = 3 ;
        // no obs
        int a[][] = new int[n][n];
        boolean[][] visited = new boolean[n][n]; // To track visited cells
        List<String> ways = new ArrayList<>();
        // recur(a,visited,ways,0,0,"");
        ways.forEach(System.out::println);
// -------------------------------------------------------------------------------
        // with obs
        int b[][] = {
            {0, 0, -1},
            {0, 0, -1},
            {0, 0, 0}
        };
        // recur(b,ways,0,0,"");
        ways.forEach(System.out::println);
// -------------------------------------------------------------------------------
        // with obs and value: get min cost
        int c[][] = {
            {1, 3, 1},
            {-1, 5, 1},
            {4, -2, 1}
        };
        // recur1(c,visited,0,0,"",0);
        // System.out.println(min == Integer.MAX_VALUE ? "No path found" : "Min cost path : " + path + " with cost : " + min);
// -------------------------------------------------------------------------------
        // with custom destination not last index of i, j
        int d[][] = new int[n][n]; // trying with normal
        int e[][] = { // trying with obstacle
            {0, 0, -1},
            {0, 0, -1},
            {0, 0, 0}
        };
        int x = 0, y = 1;
        recur2(e, ways, "", 0, 0, x, y);
        ways.forEach(System.out::println);
    }
}