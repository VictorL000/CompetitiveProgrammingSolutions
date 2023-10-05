import java.util.*;
public class Main {
	public static int getIndex(String[] arr, String in) {
		for(int i = 0; i < arr.length; i++) {
			if(arr[i].equals(in))return i;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] partners = new int[n];
		String[] fnames = new String[n];
		String[] snames = new String[n];
		for(int i = 0; i < n; i++) {
			String input = sc.next();
			fnames[i] = input;
			partners[i] = i;
		}
		
		for(int i = 0; i < n; i++) {
			String input = sc.next();
			snames[i] = input;
		}
		boolean good = true;
		for(int i = 0; i < n && good; i++) {
			int index = getIndex(fnames, snames[i]);
			if(!fnames[i].equals(snames[index]) || index == i)good = false;
		}
		if(good)System.out.println("good");
		else System.out.println("bad");
		
	}
}