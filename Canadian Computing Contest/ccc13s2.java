import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        ArrayList<Integer> l = new ArrayList<Integer>();
        int w = readInt(), n = readInt(), i = 3, c = 0;
        l.add(0);l.add(0);l.add(0);
        for(int j = 0; j < n; j++)l.add(readInt());
        int s = l.get(i)+l.get(i-1)+l.get(i-2)+l.get(i-3);
        while(s <= w){
            i++; c++;
            if(i > n+2)break;
            s = l.get(i)+l.get(i-1)+l.get(i-2)+l.get(i-3);
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}
