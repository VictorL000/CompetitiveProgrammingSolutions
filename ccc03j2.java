import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int ab = sc.nextInt();
			int fac = 0;
			if(ab == 0)System.exit(0);
			
			for(int i = 1; i <= Math.sqrt(ab); i++) {
				if(ab%i == 0)
					fac = i;
				
			}
			System.out.println("Minimum perimeter is " + 2*(fac + ab/fac) + " with dimensions "+fac+" x " + ab/fac);
		}
	}
}