import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		String a;
		int b, res = 0;

		int t = 1, k = 0;
		t = Integer.valueOf(s.nextLine());

		while (t != 0) {

			k = 0;
			res = 0;

			while (k < t) {
				a = s.nextLine();
				String array[];
				array = a.split(" ");
				b = Integer.valueOf(array[0]);
				a = array[1];
				if(a.equals("laranja")) {
					a = "laranjap";
				}
				res += b * retorne(a);
				k++;
			}

			if (res >= 110 && res <= 130)
				System.out.println(res + " mg");
			if (res < 110)
				System.out.println("Mais " + (110 - res) + " mg");
			if (res > 130)
				System.out.println("Menos " + (res - 130) + " mg");

			t = Integer.valueOf(s.nextLine());

		}
	}

	static int retorne(String a) {
		String vs[] = { "suco de laranja", "morango fresco", "mamao", "goiaba vermelha", "manga", "laranjap",
				"brocolis" };

		int[] vi = { 120, 85, 85, 70, 56, 50, 34 };

		for (int i = 0; i < vs.length; i++)
			if (vs[i].contains(a))
				return vi[i];

		return -1;
	}

}
