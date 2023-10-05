import java.util.Scanner;
public class Main {
	public static void main(String[] args){

		int w = 0;
		Scanner sc = new Scanner(System.in);
		Character[] ratio = new Character[6];
		for(int i = 0; i < 6; i++){
			ratio[i] = sc.next().charAt(0);
			if(ratio[i].equals('W')) w++;
		}
		if(w >= 5) System.out.println("1");
		else if(w == 3|| w == 4) System.out.println("2");
		else if(w == 1|| w == 2) System.out.println("3");
		else if(w == 0)System.out.println("-1");
	}
}