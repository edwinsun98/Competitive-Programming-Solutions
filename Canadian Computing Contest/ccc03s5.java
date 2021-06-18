import java.util.*;
import java.io.*;
public class Q3 {
    static class pair {
        int v, w;
        pair(int v0, int w0) { v = v0; w = w0; }
    }
    public static class PriorityComparator implements Comparator<pair> {
        public int compare(pair first, pair second) {
          return second.w - first.w;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int c, r, d, f = Integer.MAX_VALUE;
    static List<pair>adj[];
    public static void main(String[] args)throws IOException {
        c = readInt();
        r = readInt();
        d = readInt();
        adj = new ArrayList[c+1];
        for(int i = 1; i <= c; i++)adj[i] = new ArrayList<pair>();
        for(int i = 0; i < r; i++){
            int u = readInt(), v = readInt(), w = readInt();
            adj[u].add(new pair(v,w));
            adj[v].add(new pair(u,w));
        }
        PriorityComparator comp = new PriorityComparator();
        PriorityQueue<pair> q = new PriorityQueue<pair>(comp);
        boolean vis[] = new boolean [c+1];
        int dis[] = new int [c+1];
        vis[1] = true;
        dis[1] = 0;
        int edgeC = 0;
        int cur = 1;
        while(edgeC != r-1){
             edgeC++;
             boolean v = true;
             for(pair x : adj[cur]){
                 if(!vis[x.v]){
                     q.add(x);
                     v = false;
                 }
                 else if(!v){
                     q.add(x);
                 }
             }
             while(!q.isEmpty()){
                 if(vis[q.peek().v])q.poll();
                 else break;
             }
             if(q.isEmpty())break;
             pair temp = q.poll();
             cur = temp.v;
             dis[cur] = temp.w;
             vis[cur] = true;
        }
        for(int i = 0; i < d; i++){
            int a = readInt();
            f = Math.min(f,dis[a]);
        }
        System.out.println(f);
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
