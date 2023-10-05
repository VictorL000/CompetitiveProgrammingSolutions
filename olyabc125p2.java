import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class MaxProfit {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] v = new int[n];
		int[] c = new int[n];
		int x = 0;
		int y = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			v[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			c[i] =  Integer.parseInt(st.nextToken());
		}
		for(int i = 0; i < n; i++) {
			if(v[i] > c[i]) {
				x+= v[i];
				y += c[i];
			}
		}
		System.out.println(x-y);
	}
}