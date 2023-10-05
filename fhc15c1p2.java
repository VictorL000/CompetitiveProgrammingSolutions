import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
public class FacebookHackerCup2015Autocomplete {
	public static class Node{
		int freq;
		Node[] children;
		public Node() {
			freq = 0;
			children = new Node[26];
		}
		
		public static void insert(String ins, Node cur) {
			if(ins.length() == 0)return;
			int letter = ins.charAt(0)-'a';
			if(cur.children[letter] == null)
				cur.children[letter] = new Node();
			
			cur.children[letter].freq++;
			insert(ins.substring(1), cur.children[letter]);
		}
		
		public static int query(String qu, Node cur, int in) {
			if(cur.freq == 1 || qu.length() == 0)return in;
			
			int letter = qu.charAt(0)-'a';
			if(cur.children[letter] == null)System.out.println("unable to find " + letter);
			
			return query(qu.substring(1), cur.children[letter], in+1);
		}
		public static int quersert(String ins, Node cur, int in, boolean set, int index) {
			if(index == ins.length())return in;
			int letter = ins.charAt(index)-'a';
			if(cur.children[letter] == null) {
				cur.children[letter] = new Node();
				if(!set)in++;
				set = true;
			}
			cur.children[letter].freq++;			
			if(set)
				return quersert(ins, cur.children[letter], in, set, index+1);
			else
				return quersert(ins, cur.children[letter], in+1, set, index+1);
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);		
		int t = Integer.parseInt(br.readLine());
		for(int g = 0; g < t; g++) {
			Node root = new Node();
			int words = Integer.parseInt(br.readLine());
			int ans = 0;
			for(int i = 0; i < words; i++) {
				String inp = br.readLine();
				ans+=(Node.quersert(inp, root, 0, false, 0));		
			}
			out.println("Case #"+(g+1)+": "+ans);
		}
		out.flush();
	}
}