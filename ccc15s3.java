import java.io.*;
import java.util.*;
public class Main {
	static BufferedReader br;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int G = sc.nextInt();
		int P = sc.nextInt();
		int max;
		TreeSet<Integer> tset = new TreeSet<Integer>();
		for(int i = 1; i <= G; i++) {
			tset.add(i);
		}
		
		int ans = 0;
		for(int i = 0; i < P; i++) {
			max = sc.nextInt();
			if(tset.floor(max) == null){
                System.out.println(ans);
                return;
			}
			tset.remove(tset.floor(max));
			ans++;
		}
		System.out.println(ans);
	}
	
}