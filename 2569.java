package br.ufc.teste;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int a, b;
		char op;
		String frase, aux1;
		String array[] = new String[3];

		frase = s.nextLine();
		array = frase.split(" ");

		array[0] = array[0].replaceAll("7", "0");
		array[2] = array[2].replaceAll("7", "0");

		a = Integer.valueOf(array[0]);
		b = Integer.valueOf(array[2]);

		if (array[1].equals("+")) {
			int r = a + b;
			aux1 = String.valueOf(r);
			aux1 = aux1.replace("7", "0");

			System.out.println(Integer.valueOf(aux1));

		} else {
			int r = a * b;
			aux1 = String.valueOf(r);
			aux1 = aux1.replace("7", "0");

			System.out.println(Integer.valueOf(aux1));

		}

	}

}