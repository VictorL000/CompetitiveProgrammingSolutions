import java.util.*;
public class Main {
	static Map<Integer, LinkedList<Integer>> adjList;
	static Map<Integer, Integer> level;
	static Set<Integer> visited;
	public static void dfs(int u) {
		LinkedList<Integer> temp = adjList.get(u);
		if(temp==null)return;

		for(Integer it: temp) {
			if(!visited.contains(it)) {
				visited.add(it);
				level.put(it, level.get(u)+1); 
				dfs(it);
				level.put(it, -1);
			}
			else {
				if(level.get(it) != -1) {
					int res = level.get(u)-level.get(it)+ 1;
					System.out.println(res);
					break;
				}
			}
		}

		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for(int k = 0; k < 5; k++) {
			int n = sc.nextInt();
			level = new HashMap<>();
			adjList = new HashMap<>();
			visited = new HashSet<>();
			int start = 0;
			for(int i = 0; i < n; i++) {
				int f = sc.nextInt();
				int e = sc.nextInt();
				if(i == 0) start = f;
				if(adjList.get(f)!= null) {
					adjList.get(f).add(e);
				}else {
					adjList.put(f, new LinkedList<Integer>());
					adjList.get(f).add(e);
				}
				
			}
			level.put(start, 1);
			visited.add(start);
			dfs(start);
			
		}
	}
}