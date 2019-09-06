
import java.util.Scanner;

public class T_101021_problem_A_Guess_the_Number {


	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		boolean found = false;
		int step = 0;

		int left = 1;
		int right = 1000001;

		while (!found && step <= 25) {

			int mid = (left + right) / 2;

			System.out.println(mid);
			System.out.flush();

			String info = scanner.nextLine();

			if (info.equals("<")) {
				right = mid - 1;
			} else {
				if (left == mid) {
					found = true;
				} else {
					left = mid;
				}
			}

			step++;
		}

		System.out.println("! " + left);
		System.out.flush();
	}
}