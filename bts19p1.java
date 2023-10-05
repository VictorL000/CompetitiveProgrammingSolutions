import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] ar = new String[n];
		for(int i = 0; i < n; i++) {
			ar[i] = sc.next();
		}
		String rep = sc.next();
		
		int len = 1000;
		int ind = -1;
		for(int i = 0; i < n; i++) {

			if(Math.abs(ar[i].length() - rep.length()) < len && ar[i].length() <= rep.length()) {
				len = Math.abs(rep.length() - ar[i].length());
				ind = i;
			}
			
		}
		
		System.out.println(ar[ind]);
	}
}