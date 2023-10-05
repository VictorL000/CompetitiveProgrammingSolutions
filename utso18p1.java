import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long m = sc.nextLong();
		
		System.out.println(Math.max(n + m, Math.max(m*n, Math.abs(n-m))));
	}
}