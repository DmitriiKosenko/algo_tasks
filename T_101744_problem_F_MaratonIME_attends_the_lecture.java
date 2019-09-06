
/*

In MaratonIME, as many other groups, some students want to attend lectures just enough to not be flunked by frequency (as we know, in USP, University of Sao Paulo, it is necessary to have 70 percent frequency), however some others are dedicated and try to accomplish the most frequency percent possible, going to school even when they are ill or tired. Curiously, there is not any other kind of students in MaratonIME.

Wood, an old MaratonIME's member, needs help. He is taking the course MAC4815162342, and attended k of m lectures that were given. Consider that MAC4815162342 has n lectures in total per semester. He ask you to help finding the best way to accomplish his objectives, but, as you are new in MaratonIME, you don't know the kind of student that he is. Embarassed to ask more, you decide to solve two problems, so there is not way to go wrong.
Input

The input consists of a just one line. In this line, you are given three integers n, m and k, with 1 ≤ n ≤ 107 and 0 ≤ k ≤ m ≤ n.

n is the number of lectures of MAC4815162342 per semester, m is the quantity of lectures that were given and k is the number of lectures attended by Wood.
Output

In the first line, print the minimum number of lectures that Wood needs to attend to accomplish at least 70% frequency, or  - 1 if it is impossible to accomplish 70% frequency.

In the second line, print the maximum frequency percent that Wood can accomplish, if he goes to all of the lectures from the next lecture. This value has to be rounded down to the closest integer. Don't print '%'.

*/

import java.lang.Math;
import java.util.Scanner;



public class T_101744_problem_F_MaratonIME_attends_the_lecture {
	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

	    	String[] vals = scanner.nextLine().split(" ");

	    	long n = Long.parseLong(vals[0].trim());
	    	long m = Long.parseLong(vals[1].trim());
	    	long k = Long.parseLong(vals[2].trim());

	    	if (k * 100 / n >= 70) {
	    		System.out.println(0);
	    	} else {
	    		long req = n * 70 / 100 + (n * 70 % 100 == 0 ? 0l : 1l);
	    		if (req - k > n - m) {
	    			System.out.println(-1);
	    		} else {
	    			System.out.println(req - k);
	    		}
	    	}

	    	System.out.println(Math.round((n - m + k) * 100 / n));
	}
}