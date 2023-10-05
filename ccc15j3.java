import java.util.Scanner;
public class j3_Game {
	
	private static Scanner sc;

	public static void main(String args[]){
		sc = new Scanner(System.in);
		String str = sc.nextLine();
		char[] vow = {'a','a','a','e','e','e','e','i','i','i','i','i','o','o','o','o','o','o','u','u','u','u','u','u','u','u'};
		char[] next = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		for(int i = 0;i<str.length();i++){
			char ch = str.charAt(i);
			if(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u'){
				System.out.print(ch);
			}
			else{
				if(ch != 'z'){
					if(next[ch-96] == 'a' || next[ch-96] == 'e' || next[ch-96] == 'i' || next[ch-96] == 'o' || next[ch-96] == 'u')
						System.out.print("" + ch + vow[ch-97] + next[ch-95]);
					else
					System.out.print("" + ch + vow[ch-97] + next[ch-96]);
				}
				else {

					
					System.out.print("" + ch + vow[ch-97] + next[ch-97]);
					
					
				}
			}
		}
	}
}