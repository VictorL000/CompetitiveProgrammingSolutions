import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        
        int n = readInt();
        long total = 0;
        Stack<Pair> stk = new Stack();
        long x = readLong();
        stk.push(new Pair(x));
        for (int i = 1; i < n; ++i){
            x = readLong();
            while (!stk.isEmpty() && x > stk.peek().val){
                total += stk.peek().fre;
                stk.pop();
            }
            if (stk.isEmpty()){
                stk.push(new Pair(x));
            } else if (x < stk.peek().val){
                total += !stk.isEmpty()?1:0;
                stk.push(new Pair(x));
            } else { //if (x == stk.peek().val)
                Pair temp = stk.pop();
                total += !stk.isEmpty()?1:0;
                total += temp.fre;
                ++temp.fre;
                stk.push(temp);
            }
        }
        System.out.println(total);
        
    }
    
    static class Pair {
        
        long val;
        int fre;
        
        public Pair(long val){
            this.val = val;
            fre = 1;
        }
        
    }
	
    static String next() throws IOException {
	while (st == null || !st.hasMoreTokens()) 
            st = new StringTokenizer(br.readLine().trim());
	return st.nextToken();
    }
    static long readLong() throws IOException {
	return Long.parseLong(next());
    }
    static int readInt() throws IOException {
	return Integer.parseInt(next());
    }
    static double readDouble() throws IOException {
    	return Double.parseDouble(next());
    }
    static char readCharacter() throws IOException {
    	return next().charAt(0);
    }
    static String readLine() throws IOException {
	return br.readLine().trim();
    }

}