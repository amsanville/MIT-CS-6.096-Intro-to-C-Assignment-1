#include <iostream>
#include <vector>
using namespace std;
/*
MIT OCW 6.096 Introduction to C++

Assignment 1

Part 2: Hello World

2.1: Write a program that outputs "Hello, World!" by printing a const char*
with the value "Hello, World!
*/
void assignment_1_2_1() {
	const char* message = "Hello, World!";
	cout << message << endl;
}
/*
2.2: Write a program that outputs "Hello, World!" n times (where n is a
nonnegative interger that user will input) with:
-> a for loop
-> a while loop
-> a do while loop
*/
void assignment_1_2_2(int loopType) {
	// Validate the loop type
	if (loopType >= 0 && loopType < 3) {
		// Read user input
		cout << "Please enter a non-negative integer value and press enter:" << endl;
		int n;
		cin >> n;

		if (n >= 0) {
			// Verify non-negative integer
			int i;
			if (loopType == 0) {
				/*
				For Loop

				Notes: see syntax below. Additional conditions can be put into the
				second block
				*/
				for (i = 0; i < n; i++) {
					cout << "Hello, World!" << endl;
				}
			}
			else if (loopType == 1) {
				/*
				While Loop

				Notes: here is a while loop acting just like a for loop. Usually for
				loops are used when we have an explicit number of times we want
				something done and while loop is used when we want to do something
				an indefinite number of times.
				*/
				i = 0;
				while (i < n) {
					cout << "Hello, World!" << endl;
					i++;
				}
			}
			else {
				/*
				Do While

				Notes: just like while, except it always does the contents of the
				loop at least once. Least ideal for this situation, because the value
				of n can be 0. Thus, we must use an if statement to get the n = 0 case
				correct.
				*/
				i = 0;
				do {
					cout << "Hello, World!" << endl;
					i++;
				} while (i < n);
			}
		}
		else {
			cout << "Error: Enter a non-negative integer." << endl;
		}
	}	
	else {
		cout << "Error: Invalid loop type specified" << endl;
	}
}

/*
3.2: Given a list of N integers, find its mean (as a double), maximum value,
minimum value, and range. Your program will first ask for N, the number of
integers in the list, which the user will input. Then the user will input N
more numbers.
*/
void assignment_1_3_2() {
	int n, curr;
	cout << "Please enter the number of integers in the list, N:" << endl;
	cin >> n;
	if (n > 0) {
		cout << "Please enter a sequence of n numbers:" << endl;
		double mean;
		int min, max;

		// Read the first number in the list
		cin >> curr;
		mean = (double) curr; // Note: cast will happen automatically
		min = curr;
		max = curr;

		// Read all remaining
		for (int i = 1; i < n; i++) {
			cin >> curr;
			mean += (double) curr;
			if (min > curr) min = curr;
			if (max < curr) max = curr;
		}
		mean /= (double) n;

		// Print
		cout << "Mean: " << mean << endl;
		cout << "Max: " << max << endl;
		cout << "Min: " << min << endl;
		cout << "Range: " << max - min << endl;
	}
	else {
		// Print out for inputs of 0 or smaller
		cout << "Statistics undefined." << endl;
		cout << "Mean:" << endl;
		cout << "Max:" << endl;
		cout << "Min:" << endl;
		cout << "Range:" << endl;
	}
}

/*
3.3: Write a program to read a number N from the user and then find the first
N primes. A prime number is a number that only has two divisors, one and itself.

Note: isPrime is a helper function for the assignment.
*/
bool isPrime(int n) {
	// If the number is greater than 2, if prime
	if (n >= 2) {
		switch (n) {
		case 2:
		case 3:
			// Special low number cases where the algorithm might break
			return true;
		default:
			// Default case, check if all numbers less than half the number can
			// evenly divide it
			bool noDivisor = true;
			for (int i = 2; i <= n / 2 && noDivisor; i++) {
				noDivisor = n % i;
			}
			return noDivisor;
		}
	}
	else {
		return false;
	}
}

void assignment_1_3_3() {
	// Read input
	int n;
	cout << "Please enter a number, N, of primes you would like to know." << endl;
	cin >> n;
	cout << "The first " << n << " primes are:" << endl;

	// Iteratively find the primes using the helper function
	int primeCount = 0;
	int currNumber = 2;
	while (primeCount < n) {
		if (isPrime(currNumber)) {
			primeCount++;
			cout << currNumber << endl;
		}
		currNumber++;
	}
}

/*
3.4.1: Write a program that loops indefinitely. In each iteration of the loop, 
read in an integer N (declared as an int) that is inputted by a user, output 
N/5 if N is nonnegative and divisible by 5, and -1 otherwise. Use the ternary 
operator.

3.4.2: Modify the code so that if the condition fails, nothing is printed. Use
an if and a continue command.

3.4.3: Modify the code so that it lets the user break out of the infinite loop
by entering a -1 or any negative number. Print "Goodbye! before exit.
*/
void assignment_1_3_4() {
	// 3.4.1
	// Note: while (true) replaced so that it does it twice. The style is valid
	// but I kind of hate it...
	cout << "Part 1" << endl;
	int n;
	int i = 0;
	while (i++ < 2) {
		cin >> n;
		cout << (n % 5 && n >= 0 ? -1 : n / 5) << endl;
	}

	// 3.4.2
	// Note: while true replaced so that it does it twice
	cout << "Part 2" << endl;
	i = 0;
	while (i++ < 2) {
		cin >> n;
		if (n % 5 && n >= 0) continue;
		cout << n / 5 << endl;
	}

	// 3.4.3
	cout << "Part 3" << endl;
	while (true) {
		cin >> n;
		if (n < 0) {
			cout << "Goodbye!" << endl;
			break;
		}
		if (n % 5) continue;
		cout << n / 5 << endl;
	}
}

/*
4.4: Rewriting factorial to account for the larger numbers and negative numbers.
*/
void assignment_1_4_4() {
	short number;
	cout << "Enter a number:";
	cin >> number;

	cout << "The factorial of " << number << " is ";
	long long accumulator = 1;
	if (number >= 0) {
		for (; number > 0; accumulator *= number--);
		cout << accumulator << ".\n";
	}
	else {
		cout << "factorial undefined." << endl;
	}
}

/*
4.5: Rewriting factorial with hardcoding and switch.

Note: one way this could be done as well is to simply multiply be each of the 
cases and remove the break statements. Switch does not treat the cases as 
exclusive, unless the explicit break statement is put into the code.
*/
void assignment_1_4_5() {
	short number;
	cout << "Enter a number:";
	cin >> number;

	cout << "The factorial of " << number << " is ";
	int accumulator;
	switch (number) {
	case 0:
	case 1:
		accumulator = 1;
		break;
	case 2:
		accumulator = 2;
		break;
	case 3:
		accumulator = 6;
		break;
	case 4:
		accumulator = 24;
		break;
	case 5:
		accumulator = 120;
		break;
	case 6:
		accumulator = 720;
		break;
	case 7:
		accumulator = 5040;
		break;
	case 8:
		accumulator = 40320;
		break;
	case 9:
		accumulator = 362880;
		break;
	case 10:
		accumulator = 3628800;
		break;
	case 11:
		accumulator = 39916800;
		break;
	case 12:
		accumulator = 479001600;
		break;
	default:
		if (number > 12) {
			cout << "factorial cannot be represented by ints." << endl;
		}
		else {
			cout << "factorial undefined." << endl;
		}
		return;
	}
	cout << accumulator << ".\n";
}

/*
For fun, I also thought I might try my hand at making a large factorial
calculator that would do exactly what I described in the README. This work will
likely become a class with operator overloading later.

Large Add

Adds two numbers represented by vector<int> and returns the result.

Note: the structure of these vectors is such that the numbers are assumed to be
positive and the 1s place is the last digit.
*/
vector<int> largeAdd(vector<int> a, vector<int> b) {
	// Pad with zeros
	while (a.size() > b.size()) {
		b.insert(b.begin(), 0);
	}
	while (b.size() > a.size()) {
		a.insert(a.begin(), 0);

	}

	// Digit by digit add together and carry the 1s
	vector<int> result;
	int carryover = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		// Add
		int temp = a[i] + b[i] + carryover;
		// Insert the digit
		result.insert(result.begin(), temp % 10);
		// Floor division for carryover
		carryover = temp / 10;
	}

	// Carry the last 1 if necessary
	if (carryover) {
		result.insert(result.begin(), 1);
	}
	return result;
}

/*
Large Multiply

Multiply two numbers represented by vector<int>
*/
vector<int> largeMultiply(vector<int> a, vector<int> b) {
	// Final result
	vector<int> result;
	// Vector to hold intermediate vector<int> calculations
	vector<int> tempVec;

	// Multiply a by each digit in b one by one
	for (int i = b.size() - 1; i >= 0; i--) {
		// Pad with the appropriate number of zeros
		for (int j = b.size() - 1; j > i; j--) {
			tempVec.insert(tempVec.begin(), 0);
		}

		// Multiply
		int carryover = 0;
		for (int j = a.size() - 1; j >= 0; j--) {
			// Multiply
			int temp = b[i] * a[j] + carryover;
			// Insert the digit
			tempVec.insert(tempVec.begin(), temp % 10);
			// Floor division for carryover
			carryover = temp / 10;
		}
		// Make sure all digits make it into the temp vec
		if (carryover > 0) {
			tempVec.insert(tempVec.begin(), carryover);
		}

		// Add the results
		result = largeAdd(result, tempVec);
		// Clear tempVec
		tempVec.clear();
	}
	return result;
}

/*
Large Cast

Casts a regular integer into a vector<int> type number.
*/
vector<int> largeCast(int a) {
	// Use mod and integer division to extract each digit
	vector<int> result;
	while (a > 0) {
		result.insert(result.begin(), a % 10);
		a /= 10;
	}
	return result;
}

/*
Large Factorial

Generates the factorial using a regular integer as above, until it gets too
big. The function then uses vector<int> to represent the number, giving us a 
massive writing space for digits.
*/
void largeFactorial(){
	short number;
	cout << "Enter a number:";
	cin >> number;

	cout << "The factorial of " << number << " is ";
	if (number >= 0 && number <= 12) {
		int accumulator = 1;
		for (; number > 0; accumulator *= number--);
		cout << accumulator << ".\n";
	} else if(number > 12) {
		// Start with 12 factorial
		vector<int> accumulator = { 4, 7, 9, 0, 0, 1, 6, 0, 0 };
		int currMultiplier = 13;
		
		// Multiply until done
		while (currMultiplier <= number) {
			accumulator = largeMultiply(accumulator, largeCast(currMultiplier));
			currMultiplier++;
		}

		// Print the final result
		for (size_t i = 0; i < accumulator.size(); i++) {
			cout << accumulator[i];
		}
		cout << ".\n";
	}
	else {
		cout << "factorial undefined." << endl;
	}
}

int main() {
	// 2.1: Test Hello World
	// Output to standard out is "Hello, World!"
	cout << "Test 2.1" << endl;
	assignment_1_2_1();

	// 2.2: Test repeated Hello World
	// Output should be n Hello Worlds as dictated by standard in
	// Default input file prints 6.
	cout << "Test 2.2" << endl;
	assignment_1_2_2(0); // Test for
	assignment_1_2_2(1); // Test while
	assignment_1_2_2(2); // Test do-while
	assignment_1_2_2(2); // Imvalid user input
	assignment_1_2_2(2); // Imvalid user input
	// Clear as we expect the above to trip the flag
	cin.clear();
	cin.ignore();
	assignment_1_2_2(-1); // Invalid loop request

	// 3.2: Test integer statitics list
	assignment_1_3_2(); // Test valid list (mean: 1.5, max: 3, min: 0, range: 2)
	assignment_1_3_2(); // Test invalid list length
	assignment_1_3_2(); // Test invalid list length
	// Clear as we expect the above to trip the flag
	cin.clear();
	cin.ignore();

	// 3.3: Test n primes
	assignment_1_3_3();	// Give first 10 primes

	// 3.4: Test each of the parts
	// Should output 1, -1, 2, 3, -1, "Goodbye!"
	assignment_1_3_4();

	// 4.4: Test factorial method
	assignment_1_4_4();	// "Factorial undefined."
	assignment_1_4_4(); // 1
	assignment_1_4_4(); // 479001600 (12!)
	assignment_1_4_4(); // 6227020800 (13!)
	assignment_1_4_4(); // Integer overflow (so not 25!)

	// 4.5: Test second factorial method
	assignment_1_4_5(); // "Factorial undefined."
	assignment_1_4_5(); // 479001600 (12!)
	assignment_1_4_5(); // Integer overflow (so not 13!)

	// Test Large Factorial
	largeFactorial(); // 1.551121e+25
	largeFactorial(); // "Factorial undefined."

	return 0;
}
