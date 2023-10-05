import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int maxn = 1000101;
	static boolean[] sieve = new boolean[1000101];

	public static boolean isPrime(int n) {
		for(int i = 2; i < Math.sqrt(n)+1; i++) {
			if(n%i == 0) {
				return false;
			}
		}
		return true;
	}
	
	public static void buildS() {
		int n = 2;
		for(int j = 0; j < maxn; j++) {
			for(int i = n+n; i < maxn; i+=n) {
				sieve[i] = false;
			}
			for(int i = n+1; i < maxn; i++) {
				if(sieve[i]) {
					n = i;
					break;
				}
			}
			
		}
		
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		Arrays.fill(sieve, true);
		sieve[0] = false;
		sieve[1] = false;
		buildS();
		
		for(int i = 0; i < cases; i++) {
			
			int n = Integer.parseInt(br.readLine());
			
			for(int j = 0; j < (maxn-1)/2; j++) {
//				if(n-j > 1 && sieve[n-j] && sieve[n+j])
				
				if(n - j > 1 && n + j < maxn) {
					if(sieve[n-j] && sieve[n+j] && (n-j + n+j)/2 == n) {
						System.out.println((n-j) +" "+ (n+j));
						break;
					}
				}
				
			}
			
		}
		
	}
}