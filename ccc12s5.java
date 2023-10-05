import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int r = sc.nextInt();
		int c = sc.nextInt();
		int[][] dp = new int[r+1][c+1];
		
		int k = sc.nextInt();
		
		for(int i = 0 ; i  < k; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			dp[a][b] = -1;
		}
				
		for(int i = 1; i <= r; i++) {
			for(int j = 1; j <= c; j++) {
				if((i == 1 || j == 1) && dp[i][j] != -1) {
					dp[i][j] = 1;
					if(dp[i-1][j] == -1|| dp[i][j-1] == -1)dp[i][j] = -1;
				}
				else {

					if(dp[i][j] == -1) {
						continue;
					}
					if(dp[i-1][j] == -1 && dp[i][j-1] == -1)dp[i][j] = 0;
					
					else if(dp[i-1][j] == -1)dp[i][j] = dp[i][j-1];
					
					
					else if(dp[i][j-1] == -1)dp[i][j] = dp[i-1][j];
					
					
					else dp[i][j] = dp[i-1][j] + dp[i][j-1];

				}
			}
		}
		
//		for(int i = 0; i <= r; i++) {
//			for(int j = 0; j <= c; j++) {
//				System.out.print(dp[i][j]+ " ");
//			}
//			System.out.println();
//		}
		System.out.println(dp[r][c]);
	}
}