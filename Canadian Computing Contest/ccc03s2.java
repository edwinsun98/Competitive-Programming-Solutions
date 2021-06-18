import java.io.*;
import java.util.*;

public class Main {
    public static String last (String str){
        String v = " AEIOUaeiou";
        String tp = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            if (v.indexOf(str.charAt(i)) >= 0)
                return (tp + str.charAt(i)).toLowerCase();
            tp = (tp + str.charAt(i)).toLowerCase();
        }
        return tp.toLowerCase();
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            String[]a = new String [4];
            for(int j = 0; j < 4; j++){
                a[j] = last(br.readLine());
            }
            if(a[0].equals(a[1])&&a[1].equals(a[2])&&a[2].equals(a[3]))System.out.println("perfect");
            else if(a[0].equals(a[1])&&a[2].equals(a[3]))System.out.println("even");
            else if(a[0].equals(a[2])&&a[1].equals(a[3]))System.out.println("cross");
            else if(a[0].equals(a[3])&&a[1].equals(a[2]))System.out.println("shell");
            else System.out.println("free");
        }
        
    }
}
