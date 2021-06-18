import java.util.*;
import java.io.*;

public class Ship {
   
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException{
        int t = readInt();
        for(int x = 0; x <t ;x++){
            int row = readInt(), col = readInt();
            String adj[][] = new String [row+1][col+1];
            for(int i = 1; i <= row; i++){
                String tp = next();
                for(int j = 1; j <= col; j++){
                    adj[i][j] = Character.toString(tp.charAt(j-1));
                }
            }
            Queue<Integer> xq = new LinkedList<Integer>();
            Queue<Integer> yq = new LinkedList<Integer>();
            boolean [][]vis =  new boolean [row+1][col+1];
            int[][]dis = new int [row+1][col+1];
            xq.add(1);yq.add(1); vis[1][1] = true; dis[1][1] = 1;
            while(!xq.isEmpty()){
                int xc = xq.poll(); int yc = yq.poll();
                if(adj[xc][yc].equals("|")){
                    if(xc-1 >= 1 && !vis[xc-1][yc] && !adj[xc-1][yc].equals("*")){
                        vis[xc-1][yc] =true;
                        dis[xc-1][yc] = dis[xc][yc]+1;
                        xq.add(xc-1); yq.add(yc);
                    }
                    if(xc+1 <= row && !vis[xc+1][yc] && !adj[xc+1][yc].equals("*")){
                        vis[xc+1][yc] =true;
                        dis[xc+1][yc] = dis[xc][yc]+1;
                        xq.add(xc+1); yq.add(yc);
                    }
                }
                if(adj[xc][yc].equals("-")){
                    if(yc-1 >= 1 && !vis[xc][yc-1] && !adj[xc][yc-1].equals("*")){
                        vis[xc][yc-1] =true;
                        dis[xc][yc-1] = dis[xc][yc]+1;
                        xq.add(xc); yq.add(yc-1);
                    }
                    if(yc+1 <= col && !vis[xc][yc+1] && !adj[xc][yc+1].equals("*")){
                        vis[xc][yc+1] =true;
                        dis[xc][yc+1] = dis[xc][yc]+1;
                        xq.add(xc); yq.add(yc+1);
                    }
                }
                if(adj[xc][yc].equals("+")){
                    if(yc-1 >= 1 && !vis[xc][yc-1] && !adj[xc][yc-1].equals("*")){
                        vis[xc][yc-1] =true;
                        dis[xc][yc-1] = dis[xc][yc]+1;
                        xq.add(xc); yq.add(yc-1);
                    }
                    if(yc+1 <= col && !vis[xc][yc+1] && !adj[xc][yc+1].equals("*")){
                        vis[xc][yc+1] =true;
                        dis[xc][yc+1] = dis[xc][yc]+1;
                        xq.add(xc); yq.add(yc+1);
                    }
                    if(xc-1 >= 1 && !vis[xc-1][yc] && !adj[xc-1][yc].equals("*")){
                        vis[xc-1][yc] =true;
                        dis[xc-1][yc] = dis[xc][yc]+1;
                        xq.add(xc-1); yq.add(yc);
                    }
                    if(xc+1 <= row && !vis[xc+1][yc] && !adj[xc+1][yc].equals("*")){
                        vis[xc+1][yc] =true;
                        dis[xc+1][yc] = dis[xc][yc]+1;
                        xq.add(xc+1); yq.add(yc);
                    }
                }
            }
            if(vis[row][col]){
                System.out.println(dis[row][col]);
            }
            else System.out.println(-1);
        }
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}
