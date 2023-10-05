import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int choose = sc.nextInt();
		int N = sc.nextInt();
		Integer[] dmoj = new Integer[N];
		Integer[] peg = new Integer[N];
		
		for(int i = 0; i < N ; i++) {
			dmoj[i] = sc.nextInt();
		}
		for(int i = 0; i < N ; i++) {
			peg[i] = sc.nextInt();
		}
		int ans = 0;
		Arrays.sort(dmoj);
		if(choose == 2) {
			Arrays.sort(peg, Collections.reverseOrder());

			for(int i = 0; i < N; i++) {
				ans += Math.max(dmoj[i], peg[i]);
			}
		}else {
			Arrays.sort(peg);
			for(int i = 0; i < N; i++) {
				ans += Math.max(dmoj[i], peg[i]);
			}
		}
///		System.out.println(Arrays.toString(dmoj));
//		System.out.println(Arrays.toString(peg));
		System.out.println(ans);
		
	}
}