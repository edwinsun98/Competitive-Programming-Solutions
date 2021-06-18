import java.util.*;
import java.io.*;

public class Cc3hw5 {
    static int house[][];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args)throws IOException {
        // TODO code application logic here
        int n = readInt(), r = readInt(), c = readInt();
        house = new int [r][c];
        for(int i = 0; i < r; i++){
            String t = readLine();
            for(int j = 0; j < c; j++){
                if(t.charAt(j) == '.')house[i][j] = 0;
                else house[i][j] = -1;
            }
        }
        ArrayList<Integer> calc = new ArrayList<Integer>();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(house[i][j] == 0){
                    int area = 1;
                    Queue<Integer> xq = new LinkedList<Integer>();
                    Queue<Integer> yq = new LinkedList<Integer>();
                    boolean vis[][] = new boolean [r][c];
                    xq.add(i); yq.add(j); vis[i][j] = true;
                    while(!xq.isEmpty()){
                        int x = xq.poll(), y = yq.poll();
                        house[x][y] = -1;
                        if(x-1 >= 0 && !vis[x-1][y] && house[x-1][y] != -1){
                            xq.add(x-1);yq.add(y); vis[x-1][y] = true; area++;
                        }
                        if(x+1 < r && !vis[x+1][y] && house[x+1][y] != -1){
                            xq.add(x+1);yq.add(y); vis[x+1][y] = true; area++;
                        }
                        if(y-1 >= 0 && !vis[x][y-1] && house[x][y-1] != -1){
                            xq.add(x);yq.add(y-1); vis[x][y-1] = true; area++;
                        }
                        if(y+1 < c && !vis[x][y+1] && house[x][y+1] != -1){
                            xq.add(x);yq.add(y+1); vis[x][y+1] = true; area++;
                        }
                    }
                    calc.add(area);
                }
            }
        }
        int rcount = 0;
        Collections.sort(calc);
        for(int i = calc.size()-1; i >= 0; i--){
            if(n - calc.get(i) >= 0){
                n -= calc.get(i); rcount++;
            }
            else break;
        }
        if(rcount == 1)System.out.println(rcount+" room, "+n+" square metre(s) left over");
        else System.out.println(rcount+" rooms, "+n+" square metre(s) left over");
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
