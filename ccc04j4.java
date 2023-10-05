import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String key = sc.nextLine();
		String input = sc.nextLine();
		int length = key.length();
		int count = 0;
		input = input.replaceAll("\\W", "");
		int tempoff = ((int)key.charAt(0)-65);
		char[][] encode = new char[1+ (input.length() / length)][length];
		for(int i = 0; i < 1+ (input.length() / length); i++){
			for(int j = 0; j < length; j++){
				if(count < input.length()){
					encode[i][j] = input.charAt(count);
					count++;
			
				}
			}
		}
		count = 0;
		for(int j = 0; j < length; j++){
			for(int i = 0; i < 1+ (input.length() / length); i++){	
				tempoff = ((int)key.charAt(j)-65);
				encode[i][j] = (char)(((int)encode[i][j])+tempoff);
				if((int)encode[i][j] > 90) encode[i][j] = (char)(((int)encode[i][j])-26);
			}
		}
		for(int i = 0; i < 1+ (input.length() / length); i++){
			for(int j = 0; j < length; j++){
				if((int)encode[i][j] > 63 && (int)encode[i][j] < 91 )
					System.out.print(encode[i][j]);
			}
		}

		
		
	}
}