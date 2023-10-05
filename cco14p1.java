import java.util.*;
public class p1 {
	static int n;
	static int in[][];
	static int dp[][];
	public static int f(int r, int c) {
		if(in[r-1][c-1] == n )return 0;
		
//		int underSum = Math.min(Math.min(f(r+1, c+1), f(r+1, c)), f(r+1, c-1));
		int underSum = Math.min(Math.min(dp[r+1][c+1], dp[r+1][c]), dp[r+1][c-1] );
		
		if(underSum != 0) {
//			System.out.println(underSum);
			dp[r][c] += underSum;		
			return dp[r][c];
		}else return 1;
	}
	
	public static void main(String[] args) {
		int ans = 0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		in = new int[n][n];
		dp = new int[n+2][n+2];
		String eatnewline = sc.nextLine();
		for(int i = 0; i < n; i++) {
			String st = sc.nextLine();
			for(int j = 0; j < n; j++) {
//				System.out.println(st+" fff");
				if(st.charAt(j) == '#') {
					in[i][j] = 1;
					dp[i+1][j+1] = 1;
				}
			}
	
		}
		for(int i = n; i > 0; i--) {
			for(int j = 1; j <= n; j++) {
				if(in[i-1][j-1] != 0)
					ans += f(i,j);
			}
	
		}
		for(int i = 1; i <= n; i++) {

			for(int j = 1; j <= n; j++) {
//				System.out.print(dp[i][j]);
			}
//			System.out.println();
		}
		System.out.println(ans);
	}
}