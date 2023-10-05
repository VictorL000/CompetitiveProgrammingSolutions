import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner inputA = new Scanner(System.in);

		int tmA = 3;
		int tmE = 2;
		int vsA = 6;
		int vsE = 2;
		int gmA = 2;
		int gmE = 3;

		int inA = inputA.nextInt();
		int inE = inputA.nextInt();
		//check for TroyMartian
		if(inA>=3 && inE <= 4){
			System.out.println("TroyMartian");
		}
		//check for VladSaturnian
		if(inA<=6 && inE >= 2){
			System.out.println("VladSaturnian");			
		}
		//check for GraemeMercurian
		if(inA<=2 && inE <= 3){
			System.out.println("GraemeMercurian");
		}
	}
}