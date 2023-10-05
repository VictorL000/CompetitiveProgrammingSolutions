import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a, b;
		a = 0;
		b = 0;
		int n = sc.nextInt();
		sc.nextLine();
		String in = sc.nextLine();
		for(int i = 0; i < n; i++){
			if(in.charAt(i) == 'A'){
				a++;
			}else b++;
		}
		if(b>a)System.out.println("B");
		else if(a>b)System.out.println("A");
		else System.out.println("Tie");
	}
}