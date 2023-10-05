import java.util.*;
public class TotalAnnihilation {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int[] nums = new int[n + m];
		int mid = (n+m)/2;
		int[] a1 = new int [mid];
		int[] a2 = new int [n+m - mid];

		long ans = 0;
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			nums[i] = a;
		}
		for(int i = n; i < m+n; i++) {
			int a = sc.nextInt();
			nums[i] = 0 - a;
		}
		
		for(int i = 0; i < mid; i++) {
			a1[i] = nums[i];
		}
		for(int i = 0; i < n+m - mid ;i++) {
			a2[i] = nums[i+mid];
		}
		
//		System.out.println(Arrays.toString(a1) + " " + Arrays.toString(a2));
		HashMap<Long, Long> fqSum = new HashMap<Long, Long>();
		
		for(int i = 0; i < (1 << a1.length); i++) { //loops for 2^mid 
			long sum = 0;
			for(int j = 0; j < a1.length; j++) {
				if((i & (1 << j)) > 0) //if jth bit of i is on
					sum += a1[j];
			}
			if(fqSum.containsKey(sum)) {
				fqSum.put(sum, fqSum.get(sum) + 1);
			}else {
				fqSum.put(sum,  (long) 1);
			}
		}
		for(int i = 0; i < (1 << a2.length); i++) { //loops for 2^mid 
			long sum = 0;
			for(int j = 0; j < a2.length; j++) {
				if((i & (1 << j)) > 0) //if jth bit of i is on
					sum += a2[j];
			}
			if(fqSum.containsKey((long) 0-sum))
				ans += fqSum.get((long) 0-sum);
			
		}
//		System.out.println(fqSum);
		System.out.println(ans-1);
	}
}