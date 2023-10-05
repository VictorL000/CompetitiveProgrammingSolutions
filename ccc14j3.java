import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a ,d, temp, temp2;
		a = 100;
		d = 100;
		
		int n = sc.nextInt();
		for(int i = 0; i < n; i++){
			temp = sc.nextInt();
			temp2 = sc.nextInt();
			
			if(temp > temp2)a-= temp;
			if(temp2 > temp)d-= temp2;

		}
		System.out.println(d);
		System.out.println(a);
	}
}