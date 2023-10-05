import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int spaces = 2*h-2;
		int print = 1;
		int desc = 1;
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < print; j++){
				System.out.print("*");
			}
			for(int j = 0; j < spaces; j++){
				System.out.print(" ");
			}
			for(int j = 0; j < print; j++){
				System.out.print("*");
			}
			

			if(spaces > 0 && desc == 1){
				print+=2;
				spaces-=4;
			}else{
				desc = 0;
				print-=2;
				spaces+=4;
			}
			if(i != h-1)
			System.out.println();
		}
	}
}