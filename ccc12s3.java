import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s3 {
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int freq[] = new int[1001];
		for(int i = 0; i < N; i++) {
			freq[Integer.parseInt(br.readLine())]++;
			
		}
//		System.out.println(Arrays.toString(freq));
		int max = -1;
		int temp = -1;
		int smax = -1;
		for(int i = 0; i < 1001; i++) {
			if(freq[i] > max) {
				max = freq[i];
				temp = i;
			}
		}
		
		for(int i = 0; i < 1001; i++) {
			if(freq[i] > smax && i != temp) {
				smax = freq[i];
			}
		}
		int bigmax = 0;
		int smallmax = 2000000000;
		int bigsmax = 0;
		int smallsmax = 2000000000;

		for(int i = 0; i < 1001; i++) {
			if(i > bigmax && freq[i] == max)bigmax = i;
			if(i > bigsmax && freq[i] == smax)bigsmax = i;
		}
		for(int i = 0; i < 1001; i++) {
			if(i < smallmax && freq[i] == max)smallmax = i;			
			if(i < smallsmax && freq[i] == smax)smallsmax = i;			
			
		}
//		System.out.println(max +" "+smax);
//		System.out.println(bigmax+" "+smallmax);
//		System.out.println(bigsmax+" "+smallsmax);
		System.out.println(Math.max(Math.abs(bigmax-smallsmax), Math.abs(bigsmax-smallmax)));
	}
}