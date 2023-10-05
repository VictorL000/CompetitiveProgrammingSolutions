import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt();
        int[] x = new int[p];
        int[] y = new int[p];
        for(int i = 0; i < p; i++){
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        
        Arrays.sort(x);
        Arrays.sort(y);
        int leftbound = x[0];
        int rightbound = x[p-1];
        int topbound = y[0];
        int botbound = y[p-1];

        System.out.println(2*(rightbound-leftbound + botbound-topbound));
    }
}