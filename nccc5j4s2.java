import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static int n = sc.nextInt();
	static int[] arr = new int[n];
	public static void swap(int a, int b) {
		int c = arr[a];
		arr[a] = arr[b];
		arr[b] = c;
	}
	public static void main(String[] args) {
		int count = 0;
		for(int i = 0 ; i < n; i++) arr[i] = sc.nextInt();
		Boolean swap = false;
		do {
			swap = false;
			for(int i = 0; i < n-1; i++) {
				if(arr[i] < arr[i+1]) {
					swap(i, i+1);
					swap = true;
					count++;
				}
			}

		}while (swap);

		System.out.println(count);
	}
}