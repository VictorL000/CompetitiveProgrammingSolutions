import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			int[] nums = new int[2002];
			int[] sums = new int[4004];
			for(int i = 1; i <= N; i++) {
				nums[Integer.parseInt(st.nextToken())]++;
			}
//			System.out.println(Arrays.toString(nums));
			for(int i = 1 ; i < 2002; i++) {
				if(nums[i] > 0) {
					for(int j = i; j < 2002; j++) {
						int key = i+j;
						if(i == j) {
							sums[key] += nums[i]/2;
						}else if(nums[j] > 0){
							sums[key] += Math.min(nums[i], nums[j]);
						}
					}
				}
//				System.out.println(Arrays.toString(sums));
			}

			int max = -1;
			for(int i : sums) {
				if(i > max)max = i;
			}
			System.out.print(max);
			int ans = 0;
			for(int i : sums) {
				if(i == max)ans++;
			}
			System.out.print(" "+ans);
	}
}