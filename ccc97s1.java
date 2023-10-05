import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a;
		int b;
		int c;
		for(int foo = 0; foo < n; foo++){
			
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			
			sc.nextLine();
			String[] subjects = new String[a];
			String[] verbs = new String[b];
			String[] objects = new String[c];
			for(int i = 0; i < a; i ++){
				subjects[i] = sc.nextLine();
			}
			for(int i = 0; i < b; i ++){
				verbs[i] = sc.nextLine();
			}
			for(int i = 0; i < c; i ++){
				objects[i] = sc.nextLine();
			}
			for(int i = 0; i < a; i++){
				for(int o = 0; o < b; o++){
					for(int p = 0; p < c; p++){
						System.out.println(subjects[i] +" "+verbs[o]+" "+objects[p]+".");
					}
				}
			}
		}
	}
}