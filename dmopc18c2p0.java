import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int gridsize = sc.nextInt();
		int cost = sc.nextInt();
		int wallet = sc.nextInt();
		
		int f = wallet/cost;
		if(f >= gridsize)System.out.println(gridsize);
		else System.out.println(f);
	}
}