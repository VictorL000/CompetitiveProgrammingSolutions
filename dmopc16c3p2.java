import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Contest3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long actions = Integer.parseInt(st.nextToken());
		long jacks = Integer.parseInt(st.nextToken());
		long threshold = Integer.parseInt(st.nextToken());
		
		Stack<LinkedList<Long>> dq = new Stack<>();
		Stack<Long> ans = new Stack<>();
		for(long bg = 0; bg < actions; bg++) {
			st = new StringTokenizer(br.readLine());
			
			if(st.nextToken().equals("T")) {
				LinkedList<Long> temp = new LinkedList<>();
				temp.add((long) 0);
				temp.add((long) 1);
				dq.add(temp);
			}else {
				long b = Integer.parseInt(st.nextToken());
				LinkedList<Long> temp = new LinkedList<>();
				temp.add((long) 1);
				temp.add((long) b);
				dq.add(temp);
			}
			
		}
//		System.out.prlongln(dq);
		long x = 1;
		for(long i = 0; i < actions; i++) {
			if(dq.peek().get(0) == 0)ans.add((long) (dq.pop().get(1)*x));
			else x*=dq.pop().get(1);
			
		}
		long size = ans.size();
		for(long i = 0; i < size; i++) {
			if(ans.peek() > threshold || ans.peek() <= 0) {
				System.out.println("dust");
				ans.pop();
			}
			else System.out.println(ans.pop());
		}
		
//		System.out.prlongln(dq);
	}
}