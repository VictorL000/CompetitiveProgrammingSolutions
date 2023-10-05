import java.util.Scanner;

public class FBulbo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int low = x;
		int high = x;
		long cost = 0;
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			if(a > high) {
				cost += a-high;
				low = high;
				high = a;
			}
			else if(b < low) {
				cost += low-b;
				high = low;
				low = b;
			}
			else {
				low =  Math.max(low,  a);
				high = Math.min(high, b);
			}
			
		}
		System.out.println(cost);
	}
}