import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args)throws IOException {
        int n = readInt();
        int c = 0;
        while(n != 1){
            int maxf = 0;
            for(int i = 2; i <= Math.sqrt(n); i++){
                if(n%i == 0)maxf = Math.max(maxf,n/i);
            }
            if(maxf == 0)maxf = 1;
            n -= maxf;
            c += n/maxf;
        }
        System.out.println(c);
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
