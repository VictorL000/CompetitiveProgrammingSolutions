import java.util.Scanner;
public class j2_Fishin_Hole {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int inputTrout = sc.nextInt();
		int inputPike = sc.nextInt();
		int inputPickerel = sc.nextInt();
		int inputTotal = sc.nextInt();
		int count = 0;
		
		
		for(int t = 0; t <= inputTotal/inputTrout; t++){
			for(int p = 0; p <= inputTotal/inputPike; p++){
				for(int p2 = 0; p2 <= inputTotal/inputPickerel; p2++){
//					System.out.println(t + " " + p + " " + p2 + " ");
//					System.out.println(t * inputTrout + " " + p * inputPike +" " + p2*inputPickerel + " ");
			        if ((t > 0 || p > 0 || p2 > 0) && (t * inputTrout + p * inputPike + p2 * inputPickerel <= inputTotal)){
		            	count = count + 1;
		                System.out.println( t + " Brown Trout, "+ p +" Northern Pike, "+ p2 + " Yellow Pickerel");
		            }
				}
			}
		}
		System.out.println ("Number of ways to catch fish: "+ count);
	}
}