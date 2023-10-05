import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c;
		int d = b;
		if(a % b == 0)System.out.println(a/b);
		else{
			c = a%b;
			for(int i = a; i != 0; i--){
				if(a % i == b%i && a % i == 0){
					c/=i;
					d/=i;
					if(a/b != 0)System.out.println(a/b +" "+ c+"/"+d);
					else System.out.println(c+"/"+d);
					System.exit(0);
				}
			}
			
			

		}
	}
}