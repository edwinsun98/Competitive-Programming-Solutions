import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    public static void main(String[] args)throws IOException {
        HashSet<Character> a = new HashSet<Character>();
        String m = next(), d = next();
        ArrayList<Character> M = new ArrayList<>();
        ArrayList<Character> D = new ArrayList<>();
        for(int i = 0; i < m.length(); i++)M.add(m.charAt(i));
        for(int i = 0; i < d.length(); i++)D.add(d.charAt(i));
        if(M.contains('A') || D.contains('A'))a.add('A');
        if(M.contains('a') && D.contains('a'))a.add('a');
        if(M.contains('B') || D.contains('B'))a.add('B');
        if(M.contains('b') && D.contains('b'))a.add('b');
        if(M.contains('C') || D.contains('C'))a.add('C');
        if(M.contains('c') && D.contains('c'))a.add('c');
        if(M.contains('D') || D.contains('D'))a.add('D');
        if(M.contains('d') && D.contains('d'))a.add('d');
        if(M.contains('E') || D.contains('E'))a.add('E');
        if(M.contains('e') && D.contains('e'))a.add('e');

        int n = readInt();
        for(int i = 0; i < n; i++){
            String s = next();
            boolean valid = true;
            for(int j = 0; j < s.length(); j++){
                if(!a.contains(s.charAt(j)))valid = false;
            }
            System.out.println(valid ? "Possible baby." : "Not their baby!");
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
