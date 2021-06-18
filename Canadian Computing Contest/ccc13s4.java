import java.util.*;
import java.io.*;
public class Cc3hw3 {
    public static boolean bfs(int x, int y, ArrayList<Integer>[]adj){
        Queue<Integer> q = new LinkedList<Integer>();
        boolean visited [] = new boolean [1000009];
        q.add(x); visited[x] = true;
        while(!q.isEmpty()){
            int cur = q.remove();
            for(int nxt: adj[cur]){
                if(!visited[nxt]){
                    q.add(nxt);
                    visited[nxt] = true;
                }
            }
            if(visited[y] == true)return true;
        }
        return false;
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st; static int n, m;
    public static void main(String[] args)throws IOException {
        n = readInt(); m = readInt(); 
        ArrayList<Integer>[] adj = new ArrayList[1000009];
        for(int i = 0; i < 1000009; i++){
            if(adj[i] == null)adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < m; i++){
            int x = readInt(), y = readInt();
            adj[x].add(y);
        }
        int a = readInt(), b = readInt();
        if(bfs(a,b,adj)){
            System.out.println("yes");
        }
        else if(bfs(b,a,adj)){
            System.out.println("no");
        }
        else System.out.println("unknown");
    }
    static String next () throws IOException {
      while (st == null || !st.hasMoreTokens())
        st = new StringTokenizer(br.readLine().trim());
      return st.nextToken();
    }
    static long readLong () throws IOException {
      return Long.parseLong(next());
    }
    static int readInt () throws IOException {
      return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
      return Double.parseDouble(next());
    }
    static String readLine () throws IOException {
      return br.readLine().trim();
    }
}
