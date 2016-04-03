/*
Problem #18

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

input:
7595 6417 47 8218 35 87 1020 04 82 47 6519 01 23 75 03 3488 02 77 73 07 63 6799 65 04 28 06 16 70 9241 41 26 56 83 40 80 70 3341 48 72 33 47 32 37 16 94 2953 71 44 65 25 43 91 52 97 51 1470 11 33 28 77 73 17 78 39 68 17 5791 71 52 38 17 14 91 43 58 50 27 29 4863 66 04 68 89 53 67 30 73 16 69 87 40 3104 62 98 27 23 09 70 98 73 93 38 53 60 04 23
output(Answer):
1074
*/

using System;

public class Test
{
    public static int summing(int[] intA, int[] indexA, int index) {
        int size = intA.Length;
        int adder = indexA[index];
        int next = adder + index;
        int sum = intA[index];
        if(size > next+1 && indexA[next+1] != -1) {
            int sum1 = summing(intA, indexA, next);
            int sum2 = summing(intA, indexA, next+1);
    
            if(sum1 >= sum2) {
            	sum += sum1;
            }else {
            	sum += sum2;
            }
    	}    
        return sum;
	}

	public static int converting(char c) { return (int)Char.GetNumericValue(c); }

	public static int currentSize(int[] array) {
		int answer = 0;
		for(int i=0; i<array.Length; i++) {	
			if (array[i] < 0) {
				answer = i;
				break;
			}
		}

		return answer;
	}

	public static void inserting(int[] intA, int[] indexA, int i, string given, int row) {
		int value = converting(given[i-1])*10 + converting(given[i]);
		int size = currentSize(intA);
		intA[size] = value;
		indexA[size] = row;
	}

	public static void distribution(int[] intA, int[] indexA, string given) {
		int addToIndex = 3;
		int indexToAdd = 5;
		int endofRow = 1;
		int rowCount = 1;
		bool rowUp = false;

		Console.WriteLine("Testing {0}, {1}, {2}, {3}, {4}", addToIndex, indexToAdd, endofRow, rowCount, rowUp);

		for(int i=0; i<given.Length; i++) {
			if(rowUp) {
				rowCount++;
				rowUp = false;
			}else if(i==endofRow) {
				rowUp = true;
				inserting(intA, indexA, i, given, rowCount);
				endofRow += indexToAdd;
				indexToAdd += addToIndex;
			}else if(given[i]==' ') {
				//when in space
				inserting(intA, indexA, i-1, given, rowCount);
			}
		}
	}

	public static void Main() {
		int[] intA = new int[200];
		int[] indexA = new int[200];

		for(int i=0; i<intA.Length; i++) {
			intA[i] = -1;
			indexA[i] = -1;
		}

		string given;
		given = Console.ReadLine();
		//given += Console.ReadLine();

		distribution(intA, indexA, given);

/*		//checking the elements in the arrays
		for(int i=0; i<intA.Length; i++) {
			Console.WriteLine("{0}, {1}",intA[i], indexA[i]);
		}
*/
		int maxsum = summing(intA, indexA, 0);
		Console.WriteLine(maxsum);
	}
}