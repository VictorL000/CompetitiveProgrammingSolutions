import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		String eatnewl = sc.nextLine();
		int[] parser = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
		for(int i = 0; i < n; i++) {
			String inp = sc.nextLine();
			String out = "";
			for(int j = 0; j < inp.length(); j++) {
				if(inp.charAt(j) != '-')out = (out + "" + inp.charAt(j));
			}
//			System.out.println(out);
			
			for(int j = 0; j <= 9; j++) {
				if(j == 3 || j == 6)System.out.print("-");
				if(out.charAt(j) - 'A' < 0)System.out.print(out.charAt(j));
				else System.out.print(parser[out.charAt(j) - 'A']);
			}
			System.out.println();
		}
		
	}
}