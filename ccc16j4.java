import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String time = sc.nextLine();
		int min = 60*(10* Character.getNumericValue(time.charAt(0)) + Character.getNumericValue(time.charAt(1))) + 10* Character.getNumericValue(time.charAt(3)) + Character.getNumericValue(time.charAt(4));
		for(int i = 240 ; i > 0; min++){
			if(min >= 420 && min < 600){
				i--;
				
			}
			else if(min >= 900 && min < 1140){
				i--;
			}
			else{
				i-=2;
				
				
			}
			

		}
		System.out.printf("%02d:%02d\n", min/60%24, min%60);
	}
}