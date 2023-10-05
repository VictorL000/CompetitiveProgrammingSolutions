import java.util.*;
public class Main {
	public static Boolean checkDist(int x1, int y1, int x2, int y2, int d) {
		if(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) <= d*d) {
			return true;
		}
		else return false;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
//		int a = sc.nextInt();
//		int b = sc.nextInt();
//		int c = sc.nextInt();
//		int d = sc.nextInt();
//		int f = sc.nextInt();
//		System.out.println(checkDist(a,b,c,d,f));
		
		int n = sc.nextInt();
		int di = sc.nextInt();
		int p[][] = new int[n+1][2];
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			p[i][0] = a;
			p[i][1] = b;
		
		}
//		for(int i = 0; i < n; i++) {
//			System.out.print(p[i][0]);
//			System.out.println(p[i][1]);
//		}
		int ans = 1;
		int cur = 1;
		for(int i = 0; i < n-1; i++) {
			if(checkDist(p[i][0], p[i][1], p[i+1][0], p[i+1][1], di)) {
				cur++;
				ans = Math.max(cur, ans);
			}
			else {
				cur = 0;
			}
			
		}
		System.out.println(ans);
	}
}