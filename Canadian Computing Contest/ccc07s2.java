import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int l[] = new int [n];
        int w[] = new int [n];
        int h[] = new int [n];
        for(int i = 0; i < n; i++){
            ArrayList<Integer> a = new ArrayList<>();
            a.add(readInt());a.add(readInt());a.add(readInt());
            Collections.sort(a);
            l[i] = a.get(0);
            w[i] = a.get(1);
            h[i] = a.get(2);
        }
        int m = readInt();
        for(int i = 0; i < m; i++){
            ArrayList<Integer> a = new ArrayList<>();
            a.add(readInt()); a.add(readInt());a.add(readInt());
            Collections.sort(a);
            int L = a.get(0), W = a.get(1), H = a.get(2), vol = Integer.MAX_VALUE;
            for(int j = 0; j < n; j++){
                if(L <= l[j] && W <= w[j] && H <= h[j]){
                    vol = Math.min(l[j]*w[j]*h[j],vol);
                }
            }
            if(vol == Integer.MAX_VALUE){
                System.out.println("Item does not fit.");
            }
            else System.out.println(vol);
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
