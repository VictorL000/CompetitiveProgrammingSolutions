import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        Stack<Integer> nums = new Stack<Integer>();
        int a;
        int sum = 0;
        int num = sc.nextInt();
        // Let's add some items to it
        for (int i = 0; i < num; i++){
        	a = sc.nextInt();
        	if(a != 0)
        		nums.push(a);
        	if(a == 0)
        		nums.pop();
                
        }
        

        for(int i = 0; i < nums.size(); i++){
        	sum += nums.get(i);
        }
        System.out.println(sum);
        

	}
}