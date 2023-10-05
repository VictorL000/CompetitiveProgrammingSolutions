import java.util.*;
public class Main {
	static Map<Integer, ArrayList<Integer>> al;
	static int[] sumPath;
	static int n;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		sumPath = new int[n+1];
		Arrays.fill(sumPath, 0);
		al = new HashMap<>();
		int ans = 0;
		for(int k = 0; k < n; k++) {
			al.put(k, new ArrayList<Integer>());
		}
		
		while(true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a == 0 && b == 0)break;
			al.get(a).add(b);
		}
		sumPath[1] = 1;
		for(int k = 1; k < n; k++) {
			for(int v : al.get(k))sumPath[v] += sumPath[k];
		}
	
		System.out.println(sumPath[n]);
	}	
}