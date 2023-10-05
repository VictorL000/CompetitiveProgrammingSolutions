import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
public class Main {
	static BigInteger choose(int N, int K) {
		
	    BigInteger ret = BigInteger.ONE;
	    for (int k = 0; k < K; k++) {
	        ret = ret.multiply(BigInteger.valueOf(N-k))
	                 .divide(BigInteger.valueOf(k+1));
	    }
	    return ret;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int ans = 0;
		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int MB = Integer.parseInt(st.nextToken());
		int[] freq = new int[(int) Math.pow(2, 2*n-1)];
		
		
		for(int d =0; d < MB; d++) {
			
			Boolean[][] grid = new Boolean[n+1][n+1];
			
			for(int i = 0; i < n; i++) {
				Arrays.fill(grid[i], false);
			}

			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				String str = st.nextToken();
				for(int j = 0; j < n; j++) {
					if(str.charAt(j) == 'R')grid[i][j] = true;
				}
			}
	
			for(int i = 0; i < n-1; i++) {
				for(int j = 0; j < n-1; j++) {
					if(grid[i][j]) {
	//					System.out.println(i +"  "+ j);
						grid[i][j] = !grid[i][j];
						grid[i][j+1] = !grid[i][j+1];
						grid[i+1][j+1] = !grid[i+1][j+1];
						grid[i+1][j] = !grid[i+1][j];
					}
				}
			}
			
			String bin = "";
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(i == n-1 || j == n-1)
					if(grid[i][j]) {
						bin = bin+""+1;
//						System.out.print(1+" ");
					}
					else {
//						System.out.print(0+" ");
						bin = bin+""+0;
					}
				}
//				System.out.println();
			}
			
//			System.out.println(Integer.parseInt(bin, 2));
			freq[Integer.parseInt(bin, 2)]++;
		}
		
		for(int i = 0; i < freq.length; i++) {
			if(freq[i] > 0) {
//				System.out.println(i +" | "+ freq[i]);
				ans += (choose(freq[i], 2)).intValue();
			}
		}
		System.out.println(ans);
	}
}