import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int limit = sc.nextInt();
		int input = sc.nextInt();
		
		if(input <= limit){
			System.out.print("Congratulations, you are within the speed limit!");
		}else if(limit+21 >= input){
			System.out.print("You are speeding and your fine is $100.");
		}else if(limit+31 >= input){
			System.out.print("You are speeding and your fine is $270.");
		}else{
			System.out.print("You are speeding and your fine is $500.");
		}
		
	}
}