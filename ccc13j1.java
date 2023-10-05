import java.util.*;
public class Main {
	public static void main(String args[]){
	Scanner sc = new Scanner(System.in);
	int youngest = sc.nextInt();
		if (youngest <= 50){
		int middle = sc.nextInt();
			if(middle >= youngest){
				int oldest = middle - youngest + middle;
				System.out.print(oldest);
			}
		}
	}
}