import java.util.*;
public class Main {
	public static long countZero(long num) {
		long ans = 0;
		while(num > 1) {
			ans += num/5;
			num = num/5;
		}
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
//		System.out.println(countZero(a));
		long low = 1;
		long high = (long) 1e15;
		long ans = 0;
		long mid;
		
		while(low <= high) {
			mid = (low+high)/2;
			
			if(countZero(mid) >= a) {
				high = mid - 1;
				ans = mid;
			}else {
				low = mid+1;
			}
		}
		
		low = 1;
		high = (long) 1e15;
		long ansb = 0;
		mid = 0;
		while(low <= high) {
			mid = (low+high)/2;
			
			if(countZero(mid) <= b) {
				low = mid+1;
				ansb = mid;
			}else {
				high = mid - 1;
			}
		}

		System.out.println(ansb - ans + 1);
	}
}