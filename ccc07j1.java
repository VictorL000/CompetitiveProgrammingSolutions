import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
	
		int median = Math.max(Math.min(a,b), Math.min(Math.max(a,b),c));
		
		System.out.println(median);
	}
}