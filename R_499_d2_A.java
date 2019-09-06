
import java.lang.Math;
import java.util.Arrays;
import java.util.Scanner;



public class R_499_d2_A {
	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

    	String[] vals = scanner.nextLine().split(" ");

    	int n = Integer.parseInt(vals[0].trim());
    	int k = Integer.parseInt(vals[1].trim());

    	String chars = scanner.nextLine();

    	char tempArray[] = chars.toLowerCase().toCharArray();
        Arrays.sort(tempArray);
        
        int sum = 0;
        int counter = 0;
        char prev = 0;
        int i = 0;
        while (i < tempArray.length && counter < k) {
        	if (tempArray[i] - prev >= 2) {
        		prev = tempArray[i];
        		counter++;
        		sum += (int) (tempArray[i] - 96);
        	}
        	i++;
        }

        System.out.println((counter < k) ? -1 : sum);
        
	}
}