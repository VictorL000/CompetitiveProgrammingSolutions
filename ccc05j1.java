import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int day = sc.nextInt();
		int eve = sc.nextInt();
		int week = sc.nextInt();
		int totala = 0;
		int totalb = 0;
		if(day-100 > 0)totala+= (day-100)*25;
		totala += eve*15;
		totala += week*20;
		
		if(day-250 > 0)totalb+= (day-250)*45;
		totalb += eve*35;
		totalb += week*25;
		
		System.out.printf("Plan A costs %.2f\n",(double) totala/100);
		System.out.printf("Plan B costs %.2f\n", (double) totalb/100);

		if (totala < totalb)System.out.println("Plan A is cheapest.");
		if (totala > totalb)System.out.println("Plan B is cheapest.");
		if (totala == totalb)System.out.println("Plan A and B are the same price.");


	}
}