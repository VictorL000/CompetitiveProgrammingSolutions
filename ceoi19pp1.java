import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
public class ceoi19pp1 {
	public static void main(String[] args) {
		int vn, hn;
		Scanner sc = new Scanner(System.in);
		
		HashMap<Integer, Integer> mp = new HashMap<>();

		hn = sc.nextInt();
		vn = sc.nextInt();
		int v[] = new int[vn];	
		int h[] = new int[hn];			
		
		int ans = 0;
		

		for(int i = 0; i < hn; i++)
			h[i] = sc.nextInt();
		for(int i = 0; i < vn; i++)
			v[i] = sc.nextInt();
		
		for(int i = 0; i < hn; i++){
			for(int j = i + 1; j < hn; j++){
				if(mp.containsKey(h[j]-h[i]))
					mp.put(h[j]-h[i], mp.get(h[j]-h[i])+1);					
				else
					mp.put(h[j]-h[i], 1);

			}
		}

		for(int i = 0; i < vn; i++){
			for(int j = i + 1; j < vn; j++){
				if(mp.containsKey(v[j]-v[i]))
					ans += mp.get(v[j]-v[i]);
			}
		}
		
//		System.out.println(mp);
		System.out.println(ans);
	}	
}