import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int count = 0;
		int in = sc.nextInt();
		for (int q = 1; q <= in; q++) {
			for (int w = q + 1; w <= in; w++) {
				for (int e = w + 1; e <= in; e++) {
					if (q < in && w < in && e < in){
						count++;
					}
				}
			}
		}
		System.out.println(count);
	}
}