import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String temp;
		String changed;
		char check = '0';
		for(;;){
			temp = sc.nextLine();
			changed = temp;
			if(temp.equals("quit!"))break;
			if(temp.length() > 4){
				if(temp.charAt(temp.length()-1) == 'r' && temp.charAt(temp.length()-2) == 'o'){
					check = temp.charAt(temp.length()-3);
					if(!(check == 'a' || check == 'e' || check == 'i' || check == 'o' || check == 'u' || check == 'y')){
						System.out.print(temp.substring(0,(temp.length()-2)));
						System.out.println("our");
					}else System.out.println(temp);
				}else System.out.println(temp);
			
			}else System.out.println(temp);
			
		}
	}
}