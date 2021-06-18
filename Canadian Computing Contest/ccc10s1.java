import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner input = new Scanner(System.in);
	    HashMap<String,Integer> map = new HashMap<String,Integer>();
	    int max = Integer.MIN_VALUE;
	    int smax = Integer.MIN_VALUE;
	    int n = input.nextInt();
	    ArrayList<String> f = new ArrayList<String>();
	    ArrayList<String> s = new ArrayList<String>();
	    for(int i = 0; i < n; i++){
	        String na = input.next();
	        int r = input.nextInt(), se = input.nextInt(), d = input.nextInt();
	        int sum = 2*r+3*se+d;
	        if(sum > max){
	            smax = max;
	            max = sum;
	            
	        }
	        else if(sum > smax)smax = sum;
	        map.put(na,sum);
	    }
	    for (Map.Entry<String, Integer> entry : map.entrySet()) {
		    if((int)entry.getValue() == max){
		        f.add(entry.getKey().toString());
		    }
		    else if((int)entry.getValue() == smax){
		        s.add(entry.getKey().toString());
		    }
		}
		if(f.size() == 0)return;
		if(s.size()==0){
		    Collections.sort(f); 
		    for(int i = 0; i < f.size(); i++){
		        if(i == 2)break;
		        System.out.println(f.get(i));
		    }
		    return;
		}
        if(f.size()==1)System.out.println(f.get(0));
        else{
            Collections.sort(f); System.out.println(f.get(0));
        }
        if(s.size()==1)System.out.println(s.get(0));
        else{
            Collections.sort(s); System.out.println(s.get(0));
        }
	}
}
