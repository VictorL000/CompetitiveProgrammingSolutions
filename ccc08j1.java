import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		double weight = sc.nextDouble();
		double height = sc.nextDouble();
		
		System.out.println(weight/(height*height) > 25 ? "Overweight" : weight/(height*height) > 18 ? "Normal weight" : "Underweight");
	}
}