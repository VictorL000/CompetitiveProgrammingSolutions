import java.util.Scanner;
public class Main {
	public static void main(String args[]){
		int sum;
		int a;
		int b;
		int c;
		sum = 9*1+7*3+8*1+0*3+9*1+2*3+1*1+4*3+1*1+8*3;
		Scanner sc = new Scanner(System.in);
		

		a = sc.nextInt();

		b = sc.nextInt();

		c = sc.nextInt();
		System.out.println( "The 1-3-sum is "+(a+b*3+c+sum));
	}
}