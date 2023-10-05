import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int g = 0; g < 5; g++){
        	int m = sc.nextInt()+1;
        	int n = sc.nextInt();
        	int[] coins = new int[n];
        	int[] dp = new int[m];
        	for(int i = 0; i < n; i++){
        		coins[i] = sc.nextInt();
        		dp[coins[i]] = 1;
        	}
        	
        	for(int i = 0; i < m; i++){
        		int ans = 999994;
        		for(int j = 0; j < n; j++){
        			int coin = coins[j];
        			if(i - coin >= 0 && dp[i-coin] != 0){
        				ans = Math.min(dp[i-coin]+1,  ans);
        			}
        			if(ans != 999994){
        				dp[i] = ans;
 //       				System.out.println(i + " "+ j);
        			}
        		}
        	}
        	System.out.println(dp[m-1]);
        }
    }
}