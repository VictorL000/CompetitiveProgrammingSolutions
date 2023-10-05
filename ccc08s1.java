import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int min = 201;
		int num = 0;
		String[] cities = new String[10000];
		int[] temp = new int[10000];
		
		for(int i = 0; i < 10000; i++){
			cities[i] = sc.next();
			temp[i] = sc.nextInt();
			if(temp[i] < min){
				min = temp[i];
				num = i;
			}
			
			if(cities[i].equals("Waterloo")){
				System.out.println(cities[num]);
				System.exit(0);
			}
		}
	}
}