import java.util.Scanner;
import java.util.Arrays;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int time = sc.nextInt();
		int t = 0;
		int p = 0;
		int n = sc.nextInt();
		int[] chores = new int[n];
		for(int i = 0; i < n; i++){
			chores[i] = sc.nextInt();
		}
		Arrays.sort(chores);

		
		for(int i = 0; i < n; i++){
			t += chores[i];
			if(t > time){
				System.out.println(p);
				System.exit(0);
			}
			else p++;
		}
	}
}