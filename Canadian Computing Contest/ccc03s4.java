import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static HashSet<String> set;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        for(int x = 0; x < n; x++){
            String str = next();
            ArrayList<String> suf = new ArrayList<>();
            for(int i = 0; i < str.length(); i++){
                suf.add(str.substring(i,str.length()));
            }
            Collections.sort(suf);
            int c = suf.get(0).length()+1;
            for(int i = 1; i < str.length(); i++){
                int t = LCP(suf.get(i),suf.get(i-1));
                c = c+ suf.get(i).length() - t;
            }
            System.out.println(c);      
        }
    }
    static int LCP(String s, String t){
        int n = Math.min(s.length(), t.length());
        for(int i = 0; i < n; i++)if (!s.substring(i,i+1).equals(t.substring(i,i+1)))return i;
        return n;
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
