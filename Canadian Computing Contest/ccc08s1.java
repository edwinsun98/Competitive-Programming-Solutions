import java.util.*;
import java.io.*;
public class Cc3hw6 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args)throws IOException {
        HashMap<Integer,String> map = new HashMap<Integer,String>();
        ArrayList<Integer> list = new ArrayList<Integer>();
        while(true){
            String str = next();
            int temp = readInt();
            list.add(temp);
            map.put(temp,str);
            if(str.equals("Waterloo"))break;
        }
        Collections.sort(list);
        System.out.println(map.get(list.get(0)));
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
