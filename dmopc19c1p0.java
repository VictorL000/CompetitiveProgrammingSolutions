import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long min = 10000001;
		long max = -1000000000;
		for(int i = 0; i < n; i++) {
			int g = sc.nextInt();
			if(g < min)min = g;
			if(g > max)max = g;
		}
		System.out.println(max-min);
	}
}