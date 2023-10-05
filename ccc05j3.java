import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int length = 0;
		char[] lr = new char[20];
		String[] where = new String[20];
		String temp;
		for(int i = 0; i < 6; i++){
			lr[i] = sc.nextLine().charAt(0);
			temp = sc.nextLine();
			
			if(temp.equals("SCHOOL")){
//				temp = "into your HOME.";
				break;
			}
			where[i+1] = "onto " + temp + " street.";
		}
		
		for(int i = 0; i < 6; i++){
			 if(where[i] != null)length++;
		}

		where[0] = "into your HOME.";
		for(int i = length; i >= 0; i--){
			if(lr[i] == 'R'){
				System.out.println("Turn LEFT "+where[i]);
			}
			else if(lr[i] == 'L'){
				System.out.println("Turn RIGHT "+where[i]);
			}
			
		}

	}
}