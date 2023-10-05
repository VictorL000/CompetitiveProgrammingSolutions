import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int maxx = sc.nextInt();
		int maxy = sc.nextInt();
		int x = 0;
		int y = 0;
		while(true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a == 0 && b == 0)System.exit(0);
			
			x += a;
			y += b;
			
			if(x > maxx)x = maxx;
			if(x < 0)x = 0;
			if(y > maxy)y = maxy;
			if(y < 0)y = 0;
			System.out.println(x+" "+y);
			
		}
	}

}