/*
Problem 20:

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Input:
Void

Output:
648
*/
using System;

public class Test {
	public static void inserting(ref int[] digitA, ref bool[] usageA, int digit, bool trimming) {
		int size = usageA.Length;

		if(trimming) {
			for(int i=size-1; i>=0; i--) {
				if(usageA[i] && digitA[i] >= 10) {
					int value = digitA[i];
					digitA[i] = value%10;
					usageA[i-1] = true;
					digitA[i-1] += value/10;
				}
			}
		}else {
			if(usageA[size-1] == false) {
				digitA[size-1] = digit;
				usageA[size-1] = true;
			}else {
				for(int i=0; i<size; i++) {
					if(usageA[i]) {
						digitA[i] *= digit;
					}
				}

				inserting(ref digitA, ref usageA, 1, true);
				//Console.WriteLine("Done2");
			}
		}
	}

	public static void factorializing(ref int[] digitA, ref bool[] usageA) {
		int start_N = 1;
		int final_N = 5;

		for(int i=start_N; i<=final_N; i++) {
			//Console.WriteLine("factorializing for {0}: ", i);

			inserting(ref digitA, ref usageA, i, false);
		}
	}
	
	public static int summing(int[] digitA, bool[] usageA) {
		int sum = 0;
		int size=digitA.Length;

		for(int i=0; i<size; i++) {
			if(usageA[i]) {
				sum += digitA[i];
			}
		}

		return sum;
	}

	public static void Main() {
		const int size = 500;
		int[] digitA = new int[size];
		bool[] usageA = new bool[size];


		factorializing(ref digitA, ref usageA);

		/*
		//Checking Method
		for(int i=0; i<size; i++) {
			Console.WriteLine("{0} : {1}  {2}", i, digitA[i], usageA[i]);
		}
		*/

		int answer = summing(digitA, usageA);
		Console.WriteLine("The answer is {0}", answer);

	}
}