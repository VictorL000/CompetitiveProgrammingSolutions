import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int a = 0;
		int b = 0;
		String[][] rps = new String[num][2];
		for(int j = 0; j < 2; j++){
			for(int i = 0; i < num; i++){
				rps[i][j] = sc.next();
			}	
		}
		for(int i = 0; i < num; i++){
			if(rps[i][1].equals("rock") && rps[i][0].equals("paper"))a++;
			if(rps[i][1].equals("paper") && rps[i][0].equals("scissors"))a++;
			if(rps[i][1].equals("scissors") && rps[i][0].equals("rock"))a++;
			if(rps[i][0].equals("rock") && rps[i][1].equals("paper"))b++;
			if(rps[i][0].equals("paper") && rps[i][1].equals("scissors"))b++;
			if(rps[i][0].equals("scissors") && rps[i][1].equals("rock"))b++;
		}
		System.out.println(a + " " + b);
	}
}