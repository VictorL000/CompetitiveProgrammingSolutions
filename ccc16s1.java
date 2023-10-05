import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String A = sc.nextLine();
		String B = sc.nextLine();
		int ask = 0;
		for(int i = 0; i < B.length(); i++) {
			if(B.charAt(i) == '*')ask++;
		}
		
		int[] freqA = new int[26];
		int[] freqB = new int[26];
		int[] ans = new int[26];
		int sum = 0;
		
		if(A.length() != B.length()) {
			System.out.println("N");
			System.exit(0);
		}
		
		for(int i = 0 ; i < A.length(); i++) {
			freqA[(A.charAt(i) - 'a')]++;
			if(B.charAt(i) != '*')
				freqB[(B.charAt(i) - 'a')]++;
		}
		for(int i = 0 ; i < 26; i++) {
			ans[i] = freqA[i] - freqB[i];
//			System.out.println(ans[i] +" = "+ freqA[i] +" + ");
			if(ans[i] < 0) {
				System.out.println("N");
				System.exit(0);
			}
		}
//		System.out.println(Arrays.toString(ans));
//		System.out.println(ask);
		for(int i = 0; i < 26; i++) {
			sum += ans[i];
		}
		if(sum-ask == 0)System.out.println("A");
		
		
	}
}