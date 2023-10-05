import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		int a;

		int c;
		
		a = sc.nextInt();
		c = sc.nextInt();
		
		sc.nextLine();
		String[] subjects = new String[a];
		String[] objects = new String[c];
		for(int i = 0; i < a; i ++){
			subjects[i] = sc.nextLine();
		}

		for(int i = 0; i < c; i ++){
			objects[i] = sc.nextLine();
		}
		for(int i = 0; i < a; i++){

			for(int p = 0; p < c; p++){
				System.out.println(subjects[i] +" as "+objects[p]);
			}
			
		}
		
	}
}