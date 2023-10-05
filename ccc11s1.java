import java.util.Scanner;
public class Main {
	public static Scanner sc = new Scanner(System.in);
	public static int n = sc.nextInt();
	public static int ts = 0;
	public static int ss = 0;
	public static String lang(String input){
		if(input.length() == 0)return input;
		
		if(input.charAt(0) == 't' || input.charAt(0) == 'T'){
			ts++;
//			System.out.println(input.charAt(0));
		}
		if(input.charAt(0) == 's' || input.charAt(0) == 'S'){
			ss++;
//			System.out.println(input.charAt(0));
		}
		return lang(input.substring(1));
	}
	
	public static void main(String[] args){
		sc.nextLine();

		String[] in = new String[n];
		
		for(int i = 0; i < n; i++){
			in[i] = sc.nextLine();
			lang(in[i]);

		}
		if(ts>ss)System.out.println("English");
		else if(ss>=ts)System.out.println("French");

	}
}