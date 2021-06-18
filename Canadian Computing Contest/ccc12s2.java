import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static long N,K,M;
    public static void main(String[] args) throws IOException {
        String str = next();
        int prer = 100000, pre = 0, sum = 0;
        for(int i = 0; i < str.length(); i+=2){
            int a = Character.getNumericValue(str.charAt(i));
            int r = 0;
            if(str.charAt(i+1) == 'I')r = 1;
            if(str.charAt(i+1) == 'V')r = 5;
            if(str.charAt(i+1) == 'X')r = 10;
            if(str.charAt(i+1) == 'L')r = 50;
            if(str.charAt(i+1) == 'C')r = 100;
            if(str.charAt(i+1) == 'D')r = 500;
            if(str.charAt(i+1) == 'M')r = 1000;
            sum += a*r;
            if(r > prer)sum -= pre*2;
            prer = r; pre = a*r;
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}
