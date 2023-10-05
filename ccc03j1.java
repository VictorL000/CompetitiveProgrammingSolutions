import java.util.Scanner;
public class Main {
	public static void main(String[] arsg){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int s = sc.nextInt();
		int h = sc.nextInt();
		int bar = 2*s+3;
		for(int i = 0; i < t; i++){
			
			System.out.print("*");
			for(int j = 0; j < s; j++){
				System.out.print(" ");
			}
			System.out.print("*");
			for(int j = 0; j < s; j++){
				System.out.print(" ");
			}
			System.out.println("*");

		}
		for(int i = 0; i < bar; i++){
			System.out.print("*");
		}
		System.out.println();
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < s+1; j++){
				System.out.print(" ");
			}
			System.out.println("*");
		}
	}
}