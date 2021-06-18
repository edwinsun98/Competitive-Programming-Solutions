import java.util.*;
import java.io.*;

public class q1 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args)throws IOException {
        int n = readInt();
        int freq[] = new int [1001];
        for(int i = 0; i < n; i++){
            int t = readInt();
            freq[t]++;
        }
        ArrayList<Integer> high = new ArrayList<Integer>();
        ArrayList<Integer> sec = new ArrayList<Integer>();
        int max = Integer.MIN_VALUE, smax = Integer.MIN_VALUE;
        for(int i = 1; i <= 1000; i++){
            max = Math.max(max, freq[i]);
        }
        for(int i = 1; i <= 1000; i++){
            if(freq[i] == max)high.add(i);
        }
        for(int i = 1; i <= 1000; i++){
            if(freq[i] != max){
                smax = Math.max(smax, freq[i]);
            }
        }
        for(int i = 1; i <= 1000; i++){
            if(freq[i] == smax)sec.add(i);
        }
        Collections.sort(high); Collections.sort(sec);
        
        if(high.size() == 2) System.out.println(Math.abs(high.get(0)-high.get(1)));
        else if(high.size() > 2) System.out.println(Math.abs(high.get(high.size()-1) - high.get(0)));
        else if(high.size() == 1 ){
            System.out.println(Math.max(Math.abs(high.get(high.size()-1) - sec.get(0)), Math.abs(high.get(0) - sec.get(sec.size()-1))));
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
