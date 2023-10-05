import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a1 = sc.nextInt();
		int a2 = sc.nextInt();
		int a3 = sc.nextInt();
		if(a1 + a2 + a3 != 180){
			System.out.println("Error");
			System.exit(0);
		}
		if((a1 == a2 && a1 != a3)||(a1 != a2 && a1 == a3)||(a2 == a3 && a1 != a2))System.out.println("Isosceles");
		else if (a1 != a2 && a1 != a3 && a2 != a3)System.out.println("Scalene");
		else if(a1 == a2 && a1 == a3 && a1 == 60)System.out.println("Equilateral");
	}
}