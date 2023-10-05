import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int many = sc.nextInt();
		int tsum = 1;
		int[] array = new int[many]; 
		for(int i = 0; i < many; i++){
			array[i] = sc.nextInt();
			for(int j = 2; j < array[i] / 2 + 2; j++){
				if(array[i]%j == 0)tsum+= j;
			}
			if(array[i] == 2)System.out.println("2 is a deficient number.");
			else{
				if(tsum < array[i])System.out.print(array[i]+ " is a deficient number.");
				else if(tsum > array[i])System.out.print(array[i]+ " is an abundant number.");
				else if(tsum == array[i])System.out.print(array[i] + " is a perfect number.");
				if(i != many-1)System.out.println(" ");
			}
			tsum = 1;
		}
		sc.close();
	}
	
}