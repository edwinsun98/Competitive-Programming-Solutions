import java.util.*;
import java.io.*;

/**
 *
 * @author Edwin
 */
public class Ship {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st; 
    public static void main(String[] args) throws IOException{
        int l = readInt();
        for(int x = 0; x < l; x++) {
            int n = readInt();
            String[] b = new String[101];
            String[] t = new String[101];
            for(int i = 0; i < n; i++) {
                t[i] = next();
            }
            int pr = 0; int max = Integer.MIN_VALUE;
            b[0] = t[n-1];
            for(int i = 0; i < n; i++) {
                int turn = 0;
                while(turn <= pr && !t[i].equals(b[turn])) turn++;
                pr = turn;
                b[turn] = t[i];
                max = Math.max(max, pr);
            }
            System.out.println(n*10-max*2*10);
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
