import java.util.*;
public class Main {
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		int[][] loc = new int[402][201];
		char input;
		int length;
		int xnow = 200;
		int ynow = 5;
		int trt = 0;
		loc[201][1] = 1;
		loc[201][2] = 1;
		loc[201][3] = 1;
		loc[202][3] = 1;
		loc[203][3] = 1;
		loc[204][3] = 1;
		loc[204][4] = 1;
		loc[204][5] = 1;
		loc[205][5] = 1;
		loc[206][5] = 1;
		loc[206][4] = 1;
		loc[206][3] = 1;
		loc[207][3] = 1;
		loc[208][3] = 1;
		loc[208][4] = 1;
		loc[208][5] = 1;
		loc[208][6] = 1;
		loc[208][7] = 1;
		loc[207][7] = 1;
		loc[206][7] = 1;
		loc[205][7] = 1;
		loc[204][7] = 1;
		loc[203][7] = 1;
		loc[202][7] = 1;
		loc[200][7] = 1;
		loc[200][6] = 1;
		loc[200][5] = 1;


		while(true){
			input = sc.next().charAt(0);
			length = sc.nextInt();
			if(input == 'q')System.exit(0);
			if(input == 'd' ||input == 'u' ||input == 'r' ||input == 'l'){
				for(int i = 0; i < length; i++){
					if(input == 'l')xnow--;
					if(input == 'r')xnow++;
					if(input == 'u')ynow--;
					if(input == 'd')ynow++;

					if(loc[xnow][ynow] == 1){
						trt = 1;
					}

					loc[xnow][ynow] = 1;

				}
				System.out.print((xnow - 201)+" -"+ynow);
				if(trt == 1){
					System.out.println(" DANGER");
					System.exit(0);
				}
				System.out.println(" safe");
			}
			
		}
		
	}
	
}