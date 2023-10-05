import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BinaryIndexedTreeTest {
	static int[] ar;
	static long[] arSum;
	
	static Queue<Integer> freq;
	static long[] freqSum;
	
	static int N;
	
	public static int lsbit(int x) {
		return (x & (-x));
	}
	
	public static void update(int i, long val) {
		while(i <= 100001) {
			arSum[i]+= val;
			i += (lsbit(i));
		}
	}
	public static void updateF(int i, int val) {
		while(i <= 100002) {
			freqSum[i]+= val;
			i += (lsbit(i));
		}
	}
	public static long getSum(int i) {
		long sum = 0;
		while(i > 0) {
			sum+=arSum[i];
			i-=lsbit(i);
		}
		return sum;
	}
	
	public static long getSumF(int i) {
		long sum = 0;
		while(i > 0) {
			sum+=freqSum[i];
			i-=lsbit(i);
		}
		return sum;
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); 
		int M = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		
		arSum = new long[100002];
		ar = new int[100002];
		
		freqSum = new long[100002];
		freq = new LinkedList<>();
		
		for(int i = 1; i <= N; i++) {
			ar[i] = Integer.parseInt(st.nextToken());
			freq.add(ar[i]);
		}
		
		for(int i = 1; i <= N; i++) {
			update(i, ar[i]);
			updateF(freq.poll(), 1);

		}
		
		
		for(int j = 0; j < M; j++) {
			st = new StringTokenizer(br.readLine());			
			char c = st.nextToken().charAt(0);
			
			if(c == 'C') {
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				long diff = b-ar[a];
				
				update(a, diff);
				updateF(ar[a], -1);
				updateF(b, 1);
				ar[a] = b;
			}
			if(c == 'Q') {
				int a = Integer.parseInt(st.nextToken());
				System.out.println(getSumF(a));
			}
			if(c == 'S') {
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				System.out.println(getSum(b) - getSum(a-1));
			}	
		}
//		System.out.println(Arrays.toString(freqSum));
	}
}