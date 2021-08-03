import java.util.*;
import java.io.*;
public class L {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static HashMap<Integer,String> map = new HashMap<Integer,String>();
    static HashMap<String,Integer> reverse = new HashMap<String,Integer>();
    static List<Integer>adj[];
    static ArrayList<Integer> list = new ArrayList<Integer>();
    public static void main(String[] args) throws IOException {
        String a[] = {"bessie","buttercup","belinda","beatrice","bella","blue","betsy","sue"};
        map.put(1,"Beatrice"); reverse.put("Beatrice", 1);
        map.put(2,"Belinda"); reverse.put("Belinda", 2);
        map.put(3,"Bella"); reverse.put("Bella", 3);
        map.put(4,"Bessie"); reverse.put("Bessie", 4);
        map.put(5,"Betsy"); reverse.put("Betsy", 5);
        map.put(6,"Blue"); reverse.put("Blue", 6);
        map.put(7,"Buttercup"); reverse.put("Buttercup", 7);
        map.put(8,"Sue"); reverse.put("Sue", 8);
 
        int N = readInt();
        adj = new ArrayList[9];
        for(int i = 1; i <= 8; i++)adj[i] = new ArrayList<Integer>();
        for(int i = 0; i < N; i++){
            String t = readLine();
            String x = t.substring(0,t.indexOf(" "));
            String y = t.substring(t.lastIndexOf(" ")+1,t.length());
            adj[reverse.get(x)].add(reverse.get(y));
        }
        permutation("12345678");
        Collections.sort(list);
        String first = Integer.toString(list.get(0));
        for(int i = 0; i < first.length(); i++){
            System.out.println(map.get(Character.getNumericValue(first.charAt(i))));
        }
    }
    public static void permutation(String str) { 
        permutation2("", str); 
    }

    private static void permutation2(String prefix, String str) {
        int n = str.length();
        if (n == 0){
            boolean flag = false;
            for(int i = 0; i < prefix.length(); i++){
                int a = Character.getNumericValue(prefix.charAt(i));  
                if(i == 0){
                    for(int x : adj[a]){
                        if(Character.getNumericValue(prefix.charAt(i+1)) != x){
                            flag = true;
                            break;
                        }
                    }
                }
                else if(i+1 == prefix.length()){
                    for(int x : adj[a]){
                        if(Character.getNumericValue(prefix.charAt(i-1)) != x){
                            flag = true;
                            break;
                        }
                    }
                }
                else{
                    for(int x : adj[a]){
                        if(Character.getNumericValue(prefix.charAt(i-1))
                                != x && Character.getNumericValue(prefix.charAt(i+1)) != x){
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag)break;
            }
            if(!flag){
                list.add(Integer.parseInt(prefix));
            }
        }
        else {
            for (int i = 0; i < n; i++)
                permutation2(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
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
