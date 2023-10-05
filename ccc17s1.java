import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0 ;i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ;i < n; i++) {
			b[i] = Integer.parseInt(st.nextToken());
		}
		int ansa = 0;
		int ansb = 0;
		int highest = 0;
		for(int i = 0; i < n; i++) {
			ansa += a[i];
			ansb += b[i];
			
			if(ansa == ansb)highest = i+1;
		}
		System.out.println(highest);
	}
}