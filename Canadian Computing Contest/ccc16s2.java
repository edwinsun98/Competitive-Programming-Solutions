import java.util.*;
import java.io.*;

public class four {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args)throws IOException {
        int t = readInt();
        int n = readInt();
        Integer d[] = new Integer [n];
        Integer p[] = new Integer [n];
        for(int i= 0; i < n; i++)d[i] = readInt();
        for(int i= 0; i < n; i++)p[i] = readInt();
        Arrays.sort(d);Arrays.sort(p);
        if(t == 2)Arrays.sort(d,Collections.reverseOrder());
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += Math.max(d[i],p[i]);
        }
        System.out.println(sum);
        

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
