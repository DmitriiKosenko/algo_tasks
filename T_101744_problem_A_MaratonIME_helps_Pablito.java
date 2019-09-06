
/*
As is well known by any cultured person, rats are the smartest beings on earth. Followed directly by dolphins.

MaratonIME knows about the species hierarchy and uses this knowledge in it's regard. Usually, when they need some resource, they know it's always useful to have a smart rat available. Unfortunately, rats are not very fond of us, primates, and will only help us if they owe us some favour.

With that in mind, MaratonIME decided to help a little rat called Pablito. Pablito is studying rat's genealogy, to help with cloning and genetic mapping. luckily, the way rats identify themselves make the job much easier.

The rat society is, historically, matriarchal. At first, there were little families, each of which had it's own leading matriarch. At that time, it was decided that rats would organize themselves according to the following rules:

    Each martiarch had an id number greater than one.
    Each of these ids were chosen in a way such that they would have the least amount of divisors possible.
    Each family member had the same id as the matriarch.
    The id of any newborn rat would be the product of its parents id's. 

For instance, the offspring of a rat with id 6 and another with id 7 is 42.

Pablito needs to know if two given rats have a common ancestor, but his only tool is the id number of each of the two rats, which is always a positive integer greater than 1 with no more than 16 digits. Can you help him?

Create a program that decides if a pair of rats have some common ancestor.
Input

The input begins with a positive integer t ≤ 105, the number of test cases.

After that, follows t lines, each with two integers ai e bi identifying two rats.

Every rat's id is a positive integer greater than 1 and with no more than 16 digits.
Output

For each test case, print "Sim" if the rats ai and bi share a common ancestor and "Nao" otherwise.

Example

Input
2
2 4
3 5

Output
Sim
Nao

*/

import java.lang.Math;
import java.util.Scanner;


public class T_101744_problem_A_MaratonIME_helps_Pablito {


	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

	    int size = Integer.parseInt(scanner.nextLine());
	    String[] result = new String[size];

	    for (int i = 0; i < size; i++) {
	    	String[] vals = scanner.nextLine().split(" ");

	    	Long v1 = Long.parseLong(vals[0].trim());
	    	Long v2 = Long.parseLong(vals[1].trim());
	    	if (v1 == v2) {
	    		result[i] = "Sim";
	    	} else {
	    		Long vmin = Math.min(v1, v2);
	    		Long vmax = Math.max(v1, v2);

	    		if (vmax % vmin == 0) {
	    			result[i] = "Sim";
	    		} else {
					boolean flag = true;
    				while (flag) {
    					long rest = vmax % vmin;
    					if (rest == 0l) {
    						flag = false;
    					} else {
    						vmax = vmin;
    						vmin = rest;
    					}
    				}
    				result[i] = vmin == 1 ? "Nao" : "Sim";
	    		}
	    	}
	    }

	    for (int i = 0; i < result.length; i++) {
    		System.out.println(result[i]);
    	}

	}
}