import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int magic = 0;
		int[][] array = new int[4][4];
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				array[i][j] = sc.nextInt();
				
			}
		}
		magic = array[0][0] + array[0][1] + array[0][2] + array[0][3];
		for(int i = 0; i < 4; i++){
			if(array[i][0] + array[i][1] + array[i][2] + array[i][3] != magic){
				System.out.println("not magic");
					System.exit(0);
			}
			if(array[0][i] + array[1][i] + array[2][i] + array[3][i] != magic){
				System.out.println("not magic");
					System.exit(0);
			}
			
		}
		System.out.println("magic");
	}
}