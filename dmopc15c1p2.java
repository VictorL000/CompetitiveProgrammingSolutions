import java.util.*;
public class main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int leaders = sc.nextInt();
		int rank = sc.nextInt();
		int power = 0;
		Integer[] soldier = new Integer[n];
		for(int i = 0; i < n; i++) 
			soldier[i] = sc.nextInt();
	    Arrays.sort(soldier, Collections.reverseOrder());
		for(int i = 0; i < (n/leaders) + 1; i++) {
			if (((rank + i*leaders) - 1) >= n)break;
//			System.out.println(soldier[(rank + i*leaders) - 1]);
			power += soldier[(rank + i*leaders) - 1];
		}
		System.out.println(power);
	}
}