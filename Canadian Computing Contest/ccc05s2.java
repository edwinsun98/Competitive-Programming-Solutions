import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int r = readInt(), c = readInt(), X = 0, Y = 0;
        while(true){
            int x = readInt(), y = readInt();
            if(x == 0 && y == 0)break;
            X += x; Y += y;
            if(X > r)X = r;
            if(Y > c)Y = c;
            if(X < 0)X = 0;
            if(Y < 0)Y = 0;
            System.out.println(X+" "+Y);
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
