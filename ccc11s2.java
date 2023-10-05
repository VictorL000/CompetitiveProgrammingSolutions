import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		int score = 0;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] input = new char[n*2];
		
		for(int i = 0; i < n*2; i++){
			input[i] = sc.next().charAt(0);
		}
		for(int i = 0; i < n; i++){
			if(input[i] == input[i+n])score++;
		}
		System.out.println(score);
	}
	
}