import java.util.*;
import java.io.*;

public class Ship {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st; static int k = 0, way = 0;
    public static void main(String[] args) throws IOException{
        boolean[][] played=new boolean[5][5];
        k = readInt(); int p = readInt(),score[] = new int[5];
        for (int i = 0; i < p; i++) {
            int a=readInt(),b = readInt(), as = readInt(), bs = readInt();
            if(as>bs){
                score[a]+=3;
            }
            if(bs > as){
                score[b]+=3;
            }
            if(as==bs){
                score[a]++;
                score[b]++;
            }
            played[a][b]=true;
            played[b][a]=true;
        }
        dfs(played, score, p);
        System.out.println(way);
    }
    public static void dfs(boolean[][] played, int[]score, int p){
        if(p == 6){
            boolean greater = true;
            for(int i=1;i<5;i++){
                if(i!=k && score[i] >= score[k]){
                    greater = false;
                }
            }
            if(greater)way++;
            return;
        }
        boolean vis = false;
        for(int i=1; i<=3; i++){  
            for(int j=i+1; j<=4; j++){
                if(!played[i][j] && !vis){                
                    vis = true;
                    played[i][j]=true;                 
                    score[i]+=3;           
                    dfs(played,score,p+1);
                    score[i]-=3;
                    score[i]+=1; score[j]+=1;
                    dfs(played,score,p+1);
                    score[i]-=1; score[j]-=1;
                    score[j]+=3;
                    dfs(played,score,p+1);
                    score[j]-=3;
                    played[i][j]=false;
                }
            }
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
    static String readLine () throws IOException {
      return br.readLine().trim();
    }
}
