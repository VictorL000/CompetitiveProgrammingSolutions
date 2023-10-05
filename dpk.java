import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Stones2 {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int stones = Integer.parseInt(st.nextToken());
		int[] piles = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			piles[i] = Integer.parseInt(st.nextToken());
		}
		boolean[] dp = new boolean[stones+1];
		
		for(int i = 0; i <= stones; i++) {
			for(int j : piles) {
				if(i-j >= 0 && dp[i-j] == false) {
					dp[i] = true;
				}
			}
		}
		System.out.println(dp[stones]? "First" : "Second");
	}
}