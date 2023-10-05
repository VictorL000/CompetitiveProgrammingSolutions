import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] burger = new int[]{461,431,420,0};
		int[] side = new int[]{100,57,70,0};
		int[] drink = new int[]{130,160,118,0};
		int[] dessert = new int[]{167,266,75,0};
		int in1 = sc.nextInt()-1;
		int in2 = sc.nextInt()-1;
		int in3 = sc.nextInt()-1;
		int in4 = sc.nextInt()-1;	
		System.out.println("Your total Calorie count is "+ (burger[in1] + side[in2] + drink[in3] + dessert[in4]) +".");
	}
}