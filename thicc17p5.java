import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class p5 {
	static int ans = 0;
	static int[] nums;
	static int K;
	static int N;
	
	public static void main(String[] args) throws IOException {
		HashMap<Integer, Integer> fq = new HashMap<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
	
		st = new StringTokenizer(br.readLine());
		nums = new int[N];
		for(int i = 0; i < N; i++)nums[i] = Integer.parseInt(st.nextToken());
		
		int l = 0;
		int r = 0;
		long ans = 0;
		int cnt = 0; //size of freq array
		int freq[] = new int[1000001];
		
		while(r < N) {
			freq[nums[r]]++;
			if(freq[nums[r]] == 1)cnt++;
			while(cnt >= K) {
				ans += N - r;
				freq[nums[l]]--;
				if(freq[nums[l]] == 0)cnt--;
				l++;
			}
			r++;
		}
		
		System.out.println(ans);
	}
}