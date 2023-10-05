import java.util.*;
public class Main {
	static void icon (int amp){

		int size = amp*3;
		int input = amp - 2;
		String block1new = "*";
		String block2new = "x";
		String block3new = " ";
//		String temp = null;
		block2new = block2new+"";
		block3new = block3new+"";
		
		for(int count = 0; count <= input; count ++){
			block1new = "*" + block1new;
			block2new = "x" + block2new;
			block3new = " " + block3new;


		}
		for(int i = 0; i < amp; i++) System.out.println(block1new+""+block2new+""+block1new);
		for(int i = 0; i < amp; i++) System.out.println(block3new+""+block2new+""+block2new);
		for(int i = 0; i < amp; i++) System.out.println(block1new+""+block3new+""+block1new);

		
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		if (input < 25){
		icon(input);
		}
		// [VARIABLES]

		
	}
}