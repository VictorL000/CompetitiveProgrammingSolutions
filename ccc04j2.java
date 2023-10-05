import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		for(int i = 0; i <= (y-x)/60; i++){
			System.out.println("All positions change in year "+(i*60+x));
		}
	}
}