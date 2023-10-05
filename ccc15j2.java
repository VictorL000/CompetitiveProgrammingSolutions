import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = 0;
		int s = 0;
		String in = sc.nextLine();
		
		for(int i = 0; i < in.length(); i++){
			if(in.charAt(i) == ':' && in.charAt(i+1) == '-'){
				if(in.charAt(i+2) == ')')h++;
				if(in.charAt(i+2)== '(')s++;
			}
		}
		if(s > h)System.out.println("sad");
		if(s == h && s != 0)System.out.println("unsure");
		if(s < h)System.out.println("happy");
		if(s == 0 && h == 0)System.out.println("none");
	}
}