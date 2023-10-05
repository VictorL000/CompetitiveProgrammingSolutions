import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int round = sc.nextInt();
		LinkedList<Integer> people = new LinkedList<>();
		LinkedList<Integer> people2 = new LinkedList<>();
		for(int i = 1; i <= n; i++)people.add(i);

		for(int i = 0; i < round; i++) {
			int inv = sc.nextInt();
			for(int j = 0; j <= people.size(); j++) {
				if(j%inv != 0) {
					people2.add(people.get(j-1));
//					System.out.println(j+" "+inv);
				}
			}

			people = people2;
//			System.out.println(people);
			people2 = new LinkedList<>();
		}
		
		for(int i = 0; i < people.size(); i++) {
			System.out.println(people.get(i));
		}
	}

}