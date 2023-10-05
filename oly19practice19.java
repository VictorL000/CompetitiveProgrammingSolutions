import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class MultipleOfK {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] rem = new int[n];
		Arrays.fill(rem, -1);
		rem[0] = 0;
		int ans = 0;
		int sum = 0;
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) {
			sum = (sum + Integer.parseInt(st.nextToken()))%k;
			if(rem[sum%k] == -1)rem[sum%k] = i;
			else {
				ans = Math.max(ans, i - rem[sum%k]);
			}
		}
		System.out.println(ans);
	}
}