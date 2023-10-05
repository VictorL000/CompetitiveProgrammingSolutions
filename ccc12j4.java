import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int offset = sc.nextInt();
		sc.nextLine();
		String input = sc.nextLine();

		char[] charin = new char[input.length()];
		for(int i = 0; i < input.length(); i++){
			charin[i] = input.charAt(i);
		}
		for(int i = 0; i < input.length(); i++){
			if((int)charin[i] == 32)break;
			if(((int)charin[i])-offset-(3*(i+1)) < 65)System.out.print((char)(((int)charin[i])+26-offset-(3*(i+1))));
			else System.out.print((char)(((int)charin[i])-offset-(3*(i+1))));
			
		}
	}
}