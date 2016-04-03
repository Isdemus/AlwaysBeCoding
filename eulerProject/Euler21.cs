/*
Problem #21:

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers und
er 10000.

Input:
Void

Output:
The number is 220 and 284
The number is 284 and 220
The number is 1184 and 1210
The number is 1210 and 1184
The number is 2620 and 2924
The number is 2924 and 2620
The number is 5020 and 5564
The number is 5564 and 5020
The number is 6232 and 6368
The number is 6368 and 6232

The answer is 31626
*/

using System;

public class Test {
	public static bool isDivisor(int value, int divisor) {
		if(value%divisor==0) { return true; }
		else{ return false; }

	}

	public static int summing_divisors(int start) {
		int sum = 0;
		//int start2 = start-1;
		for(int start2=start-1; start2>0; start2--) {
			if(isDivisor(start, start2)) {
				sum += start2;
			}
		}
		
		return sum;
	}

	public static void Main() {
		int limit = 10000;
		int sum = 0;
		for(int start=1; start<limit; start++) {
			int result = summing_divisors(start);
			if(result == 0) { continue; }
			else {
				int result2 = summing_divisors(result);
				if(result2 == start && start != result) {
					sum += start;
					Console.WriteLine("The number is {0} and {1}", start, result);
				}
			}
			//Console.WriteLine("The answer is {0}", addition);
		}

		Console.WriteLine("The answer is {0}", sum);
	}
}


