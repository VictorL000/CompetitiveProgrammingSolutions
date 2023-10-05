import java.util.*;
public class NumberOfFactors07R52 {
	public static int pf(int n, int g, int num) {
		for(int i = g; i < n; i++) {
			if(n%i == 0)return pf(n/i, i, num+1);
		}
		return num;
	}
	public static void main(String[] args) {
		Scanner sc  = new Scanner(System.in);
		for(int i = 0; i < 5; i++) {
			int n = sc.nextInt();
			int g = (pf(n, 2, 1));
			System.out.println(g==1?"0":g);
		}
	}
}