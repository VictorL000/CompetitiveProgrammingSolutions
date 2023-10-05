import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int in1 = sc.nextInt();
		int in2 = sc.nextInt();
		int rsa = 0;
		int count = 0;
		for(int i = in1; i <= in2; i++){
			for(int j = 1; j <= i; j++){
				if(i%j == 0)count++;

			}
			if(count == 4)rsa++;
			count = 0;
		}
		System.out.println("The number of RSA numbers between "+in1+" and "+in2+" is "+rsa);
	}
}