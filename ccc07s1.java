import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a, b, c;
		
		int n = sc.nextInt();
		for(int i = 0; i < n; i++){
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			
			if(a < 1989)System.out.println("Yes");
			else if(a > 1989)System.out.println("No");
			else{
				if(b < 2)System.out.println("Yes");
				else if(b > 2)System.out.println("No");
				else{
					if(c <= 27)System.out.println("Yes");
					else if(c > 27)System.out.println("No");
				}
			}
		}
	}
}