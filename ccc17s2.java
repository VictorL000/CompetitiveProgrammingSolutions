import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		PriorityQueue<Integer> hightides = new PriorityQueue<Integer>();
		PriorityQueue<Integer> lowtides = new PriorityQueue<Integer>(n/2 + 1, Collections.reverseOrder());
		for(int i = 0; i < n; i++) 
			hightides.add(sc.nextInt());
		for(int i = 0; i < (n+1)/2 ; i++) {
			lowtides.add(hightides.poll());
		}
		
		for(int i = 0; i < n/2+1; i++) {
			if(lowtides.peek() != null)System.out.print(lowtides.poll()+ " ");
			if(hightides.peek() != null)System.out.print(hightides.poll()+ " ");
		}
	}
}