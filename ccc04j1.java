import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		System.out.printf("The largest square has side length %.0f.",(Math.floor(Math.sqrt(input))));
	}
}