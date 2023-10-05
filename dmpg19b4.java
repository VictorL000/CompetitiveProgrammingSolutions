import java.util.*;
public class B5 {
	public static void main(String[] args) {
		String b1[] = new String[27];
		String b2[] = new String[27];
		String b3[] = new String[27];
		for(int i = 65; i < 91; i++) {
			switch((char)i) {
				case 'A': case 'B': case 'E': case 'H': case 'K': case 'L': case 'O': case 'R': case 'U': case 'V': case 'Z': b1[i-'A'] = "o."; break;
				case 'C': case 'D': case 'F': case 'G': case 'M': case 'N': case 'P': case 'Q': case 'X': case 'Y': b1[i-'A'] = "oo";break;
				case 'J': case 'I': case 'S': case 'T': case 'W': b1[i-'A'] = ".o";break;
			}
			switch((char)i) {
				case 'A': case 'C': case 'M': case 'K': case 'U': case 'X':  b2[i-'A'] = "..";break;
				case 'B': case 'F': case 'I': case 'S': case 'P': case 'L': case 'V': b2[i-'A'] = "o.";break;
				case 'G': case 'H': case 'J': case 'Q': case 'R': case 'T': case 'W': b2[i-'A'] = "oo";break;
				case 'N': case 'D': case 'E': case 'O': case 'Y': case 'Z': b2[i-'A'] = ".o";break;
			}
			switch((char)i) {
				case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': b3[i-'A'] = ".." ;break;
				case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': b3[i-'A'] = "o." ;break;
				case 'U': case 'V': case 'X': case 'Y': case 'Z':  b3[i-'A'] = "oo";break;
				case 'W': b3[i-'A'] = ".o";break;
			}
		}
		b1[26] = "..";
		b2[26] = "..";
		b3[26] = "..";
		
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < s.length(); j++) {
				char g = s.charAt(j);
				if(g == ' ')System.out.print("..");
				else {
					if(i ==0)System.out.print(b1[g-'A']);
					if(i ==1)System.out.print(b2[g-'A']);
					if(i ==2)System.out.print(b3[g-'A']);
				}
			}
			System.out.println();
		}
	}
}