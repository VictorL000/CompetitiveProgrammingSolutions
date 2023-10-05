import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
public class MinimumXor2 {
	public static class Node{
		Node[] child;
		int idx;
		public Node(){
			child = new Node[2];
			idx = Integer.MAX_VALUE;
		}
	}
	
	public static void ins(int in, int idx, Node u, int point) {		
		if(point == -1) {
			u.idx = Math.min(u.idx, idx);
			return;
		}
		
		int bit = (in & (1 << point)) == 0? 0 : 1 ;
		if(u.child[bit]  == null)u.child[bit] = new Node();
		ins(in, idx, u.child[bit], point - 1);
	}
	
	public static int qry(int in, Node u, int point) {
		if(point == -1)return u.idx;
		int bit = (in & (1 << point)) == 0? 0 : 1 ;		
		if(u.child[bit] != null) {
			return qry(in, u.child[bit], point-1);
		}
		if(u.child[Math.abs(bit-1)] != null) {
			return qry(in, u.child[Math.abs(bit-1)], point-1);
		}
		else {
			System.out.println("INTERNAL ERROR");
			return -69696;
		}
		
	}
	public static void main(String[] args) throws IOException {
		Node root = new Node();
		PrintWriter writer = new PrintWriter(System.out);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int q = 0;
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			int bin = (Integer.parseInt(st.nextToken()));
			ins(bin, i, root, 30);		
		}
		for(int i = 0; i < k; i++) {
			q ^= Integer.parseInt(br.readLine());
			writer.println(qry((q), root, 30));			
		}
	writer.flush();
	writer.close();
	}
}