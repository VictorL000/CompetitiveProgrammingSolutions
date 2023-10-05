import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static int n = sc.nextInt();
	static int[][] table = new int[n][n];
	static boolean check(int varRow, int varCol) {
	
				for(int t = 0;  t< n; t++) {
					
					if(!checkRow(t, varRow))return false;
				}
				for(int t = 0;  t< n; t++) {
					if(!checkCol(t, varCol))return false;
				}

		return true;
	}
	static boolean checkRow(int row, int var) { //var is varience; 0 is right, 1 is left
		int max = 0;
		int min = Integer.MAX_VALUE;
		if(var == 0) {
			for(int i = 0; i < n; i++) {
				if(table[row][i] > max) {
					max = table[row][i];

				}
				else return false;
			}
			return true;
		}
		else {
			for(int i = 0; i < n; i++) {
				if(table[row][i] < min) {
					min = table[row][i];
				}
				else return false;
			}
			return true;
		}
	}
	static boolean checkCol(int col, int var) { //var is variance; 0 is down, 1 is up
		int max = 0;
		if(var == 0) {
			for(int i = 0; i < n; i++) {
				if(table[i][col] > max) {
					max = table[i][col];
				}
				else return false;
			}
			return true;
		}
		else{
			int min = Integer.MAX_VALUE;
			for(int i = 0; i < n; i++) {

				if(table[i][col] < min) {
					min = table[i][col];
				}
				else return false;
			}
			return true;
		}
	}
	public static void main(String[] args) {
		for(int i = 0; i < n; i++) {
			for(int j =0 ; j< n; j++) {
				table[i][j] = sc.nextInt();
			}
		}

		if(check(0, 0)) {		//ccw 90
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					System.out.print(table[i][j]+" ");
				}
				System.out.println();
			}
		}
		if(check(0, 1)){		//cw 90

			for(int i = 0; i < n; i++) {
				for(int j = n-1; j >= 0; j--) {
					System.out.print(table[j][i]+" ");
				}
				System.out.println();
			}
		}
		if(check(1, 0))	{		
//ccw
			for(int i = n-1; i >= 0; i--) {
				for(int j = 0; j < n; j++) {
					System.out.print(table[j][i]+" ");
				}
				System.out.println();
			}
		} 
		if(check(1, 1)){ //180
			for(int i = n-1; i >= 0; i--) {
				for(int j = n-1; j >= 0; j--) {
					System.out.print(table[i][j]+" ");
				}
				System.out.println();
			}
		} //180
	}
}