import java.util.Scanner;

public class BinaryCrash {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String n = sc.next();
		int nlen = n.length();
		char lastBit = n.charAt(0);
		int z = 0;
		int o = 0;
		for(int i = 0; i < nlen; i++) {
			if(n.charAt(i) == '0')z++;
			else o++;
		}
		System.out.println(2*Math.min(z, o));
	}
}