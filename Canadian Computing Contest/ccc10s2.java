import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        ArrayList<String> a = new ArrayList<>();
        ArrayList<String> b = new ArrayList<>();
        for(int i = 0; i < n; i++){
            a.add(next());
            b.add(next());
        }
        String c = next();
        ArrayList<String> ans = new ArrayList<>();
        while(c.length() > 0){
            for(int i = 0; i < n; i++){
                if(c.substring(0,b.get(i).length()).equals(b.get(i))){
                    c = c.substring(b.get(i).length(),c.length());
                    ans.add(a.get(i));
                    break;
                }
            }
            
        }
        for(int i = 0; i < ans.size(); i++)System.out.print(ans.get(i));
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
