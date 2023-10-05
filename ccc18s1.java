import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static int size = sc.nextInt();
	static double[] arr = new double[size];
	
	public static double getSize(int n) {
		if(n == 0|| n == size-1)return 2147483647;
		
		return (arr[n+1] - arr[n-1])/2;
	}
	public static void main(String[] args) {

		double minsize = 2147483647;
		for(int i = 0; i < size; i++) {
			arr[i] = sc.nextDouble();

		}
		Arrays.sort(arr);
		for(int i = 1; i < size-1; i++) {
			double temp = getSize(i);
			if(temp < minsize) {
				minsize = temp;
			}
		}
		System.out.printf("%.1f\n", minsize);
	}
}