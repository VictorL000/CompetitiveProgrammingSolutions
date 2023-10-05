import java.util.*;
public class CommonDivisor {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long k = sc.nextLong();
		long g = 0;
		
		LinkedList<Long> ad = new LinkedList<>();
		
		for(int i = 1; i <= Math.sqrt(a)+1; i++) {
			if(a % i == 0) {
				ad.add((long) i);
				ad.add(a/i);
			}
		}
		
		Collections.sort(ad, Collections.reverseOrder());
		
		for(long i : ad) {
			if(b%i == 0) {
				g++;
				if(g == k) {
					System.out.println(i);
					System.exit(0);
				}
			}
			
		}
		System.out.println(-1);
	}
}