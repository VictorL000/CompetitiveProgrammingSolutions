import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for(int i = 0; i < n; i++){
        long a = sc.nextLong();
        long b = sc.nextLong();
        long sum = a+ b;
        System.out.println(sum);
        }
    }
}