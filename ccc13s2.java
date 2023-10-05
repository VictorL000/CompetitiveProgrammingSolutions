import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int weight = sc.nextInt();
		int n = sc.nextInt();
		int[] cars = new int[n+8];
		
		for(int i = 3; i < n+3; i++) {
			cars[i] = sc.nextInt();
		}
		int ans = 0;
//		System.out.println(Arrays.toString(cars));
		for(int i = 3; i < n+8; i++) {
//			System.out.println((cars[i-3] + cars[i-2] + cars[i-1] + cars[i]));
			if(cars[i-3] + cars[i-2] + cars[i-1] + cars[i] <= weight) {
				ans++;

			}
			else {
				System.out.println(ans);
				System.exit(0);
				
			}
		}
		System.out.println(n);
	}
}