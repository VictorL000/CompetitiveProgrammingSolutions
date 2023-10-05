import java.util.*;
public class Dimethylbenzene {
	static HashMap<Integer, LinkedList<Integer>> mp = new HashMap<>();

	static Boolean[] visited;
	public static boolean dfs(int cur, int src, int dist) {
		if(dist > 6) {
			System.out.println("f");
			return false;

		}
		if(cur == src && dist == 6) {
			return true;
		}
//		if(visited[cur])return false;
//		System.out.print(cur+" ");			System.out.println(mp.get(cur));
		for(int i : mp.get(cur)) {

			if(!visited[i]) {
//				System.out.println(i);
				visited[i] = true;
				if(dfs(i, src, dist+1))return true;
			}
			visited[i] = false;
		}
		return false;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int nodes = sc.nextInt();
		int edges = sc.nextInt();
		visited = new Boolean[nodes+1];
		for(int i = 0; i < nodes; i++)visited[i] = false;
		for(int i = 0; i <= nodes; i++) {
			LinkedList<Integer> temp = new LinkedList<>();
			mp.put(i, temp);
		}
		for(int i = 0 ; i < edges; i++) {
			
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			mp.get(a).add(b);
			
		}
		
//		System.out.println(mp);
		for(int i = 0; i < nodes; i++) {
//			visited[i] = true;
			if( dfs(i,i, 0)) {
				System.out.println("YES");
				System.exit(0);
			}
		}
		
		System.out.print("NO");
		
	}
}