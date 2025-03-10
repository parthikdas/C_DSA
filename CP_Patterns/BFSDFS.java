package CP_Patterns;
class GraphBFS {
    private int V; // Number of vertices
    private List<List<Integer>> adjList; // Adjacency list
    public GraphBFS(int vertices) {
        this.V = vertices;
        adjList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
    }
    // Add an edge between two nodes
    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u); // For undirected graph
    }
    // Function to perform BFS traversal
    public void BFS(int start) {
        boolean[] visited = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();
        visited[start] = true;
        queue.offer(start);
        System.out.print("BFS Traversal: ");
        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");
            for (int neighbor : adjList.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }
        System.out.println();
    }
    public static void main(String[] args) {
        GraphBFS g = new GraphBFS(6);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
        g.BFS(0);
    }
}
//------------------------------------------------------------------
import java.util.*;
class Graph {
    private int V; // Number of vertices
    private List<List<Integer>> adjList; // Adjacency list
    public Graph(int vertices) {
        this.V = vertices;
        adjList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
    }
    // Add an edge between two nodes
    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u); // For undirected graph
    }
    // DFS helper function
    private void dfsHelper(int node, boolean[] visited) {
        visited[node] = true;
        System.out.print(node + " ");

        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
    // Function to perform DFS traversal
    public void DFS(int start) {
        boolean[] visited = new boolean[V];
        System.out.print("DFS Traversal: ");
        dfsHelper(start, visited);
        System.out.println();
    }
    public static void main(String[] args) {
        Graph g = new Graph(6);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);

        g.DFS(0);
    }
}
//-----------------------------------------------------------
// Stack
public void DFS(int start) {
    boolean[] visited = new boolean[V];
    Stack<Integer> stack = new Stack<>();

    stack.push(start);
    System.out.print("DFS Traversal (Using Stack): ");

    while (!stack.isEmpty()) {
        int node = stack.pop();

        if (!visited[node]) {
            visited[node] = true;
            System.out.print(node + " ");

            // Push all adjacent nodes (in reverse order for correct order)
            List<Integer> neighbors = adjList.get(node);
            Collections.reverse(neighbors);
            for (int neighbor : neighbors) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
    System.out.println();
}
// Queue
public void BFS(int start) {
    boolean[] visited = new boolean[V];
    Queue<Integer> queue = new LinkedList<>();

    queue.offer(start);
    visited[start] = true;
    System.out.print("BFS Traversal (Using Queue): ");

    while (!queue.isEmpty()) {
        int node = queue.poll();
        System.out.print(node + " ");

        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.offer(neighbor);
            }
        }
    }
    System.out.println();
}
public class BFSDFS {
    
}
