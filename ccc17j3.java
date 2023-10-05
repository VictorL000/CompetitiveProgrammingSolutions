import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		int t = sc.nextInt();
		int ac = Math.abs(a-c);
		int bd = Math.abs(b-d);
		int dist = ac+bd;
		if(dist-t>0){
			System.out.println("N");
			System.exit(0);
		}
		if((t-dist)%2==0){
			System.out.println("Y");
		}else{
			System.out.println("N");
		}
	}
}