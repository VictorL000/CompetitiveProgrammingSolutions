import java.util.*;
public class Main {
	static int log[];
	static int sum[];
	
	public static void query(int a, int b) {
		System.out.println(sum[b+1] - sum[a]);

	}
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sum = new int[n+1];
		log = new int[n+1];
		for(int i = 1; i <= n; i++) {
			log[i] = sc.nextInt();
		}
		sum[0] = log[0];
		for(int i = 1 ; i <= n; i++) {
			sum[i] = sum[i-1] + log[i];
		}
		
//		System.out.println(Arrays.toString(log));
		int q = sc.nextInt();
		for(int i = 0; i < q; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			query(a,b);
			
		}
		
	}
}