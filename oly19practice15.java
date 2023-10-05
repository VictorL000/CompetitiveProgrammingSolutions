import java.util.*;
public class ToLower {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st = sc.nextLine();
		st = st.toLowerCase();
		st = (char)(st.charAt(0)-32) + "" + st.substring(1);
		for(int i = 1; i < st.length(); i++) {
			
			if(i == st.length()-1 && st.charAt(i-1) == ' ' && st.charAt(i) == 'i')st = st.substring(0,i)+"I";
			if(st.charAt(i-1) == ' ' || st.charAt(i-1) == '.') {
				if(st.charAt(i) == 'i') {
					if(st.charAt(i+1) == ' ' || st.charAt(i+1) == '.') {
						st = st.substring(0,i-1)+" I"+st.substring(i+1);
					}
				}
			}
			if(((i > 1 && st.charAt(i-2) == '.' && st.charAt(i-1) == ' ') || (st.charAt(i-1) == '.') )&& st.charAt(i) > 65)st = st.substring(0,i)+""+(char)(st.charAt(i)-32)+""+st.substring(i+1);
		}
		System.out.println(st);
	}
}
//