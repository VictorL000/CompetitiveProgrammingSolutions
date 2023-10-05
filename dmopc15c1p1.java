import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double maxrating = 0;
		String maxname = "";

		for(int i = 0; i < n; i++) {
			String name = sc.next();
		
			double rating = sc.nextDouble();
			
			if(rating > maxrating) {
				maxrating = rating;
				maxname = name;
			}
		}
		System.out.println(maxname);
	}
}