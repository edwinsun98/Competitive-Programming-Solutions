import java.util.*;
import java.io.*;
public class Cc3hw6 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args)throws IOException {
        while(true){
            int r = readInt(), c = 5;
            if(r == 0)break;
            for(int i = 1; i < r; i++){
                int y = (int)Math.sqrt(r*r-i*i);
                if(y*y == r*r-i*i)c+=4;
            }
            int quarter = 0;
            for(int i = 1; i < r; i++){
                for(int j = r-1; j > 0; j--){
                    if(i*i+j*j < r*r){
                        quarter += j;
                        break;
                    }
                }
            }
            quarter *= 4;
            System.out.println(quarter+c+4*(r-1));
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
