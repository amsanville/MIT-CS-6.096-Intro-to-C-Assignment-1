# MIT OCW 6.096 - Introduction to C++
## Assignment 1
Nominally, I would submit this file with the assignment. However, since this is all taken from MIT Open Course Ware, it will just be my version of the solutions posted there (https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-096-introduction-to-c-january-iap-2011/assignments/ ). I've answered the questions asked in the assignment here. I've constructed the solutions to the various parts of the assignment in Assignment1Main.cpp. I've also included a makefile and shell script to "show my work" on compiling and putting in arguments into the script.
### 3 More Programs
#### 3.1 Scope
What happens if we declare the same name twice within a block, giving it two different meanings? For example:
```
#include <iostream>

using namespace std;

int main(){
	int arg1;
	arg1 = -1;
	char arg1 = 'A';
	cout << arg1 << "\n";
	return 0;
}
```
It gives a compiler error, "redefinition; different basic types". This is essentially telling us that in the same scope you can't define two variables with the same name.

What happens if we declare an identifier block, and then redeclare that same identifier in nested within that block? Which declaration is used in the inner block? What about the outer block? For example:
```
#include <iostream>

using namespace std;

int main(){
	int arg1;
	arg1 = -1;
	{
		char arg1 = 'A';
		cout << arg1 << "\n";
	}
	cout << arg1 << "\n";
	return 0;
}
```
This will first print 'A' and then -1. This is because the inner variable is prioritized as the variable in scope. In C++ the block created by `{}` creates its own scope. Variables declared on the stack in that block only have the life time of that block. Hence, in this case, the block has its own internal arg1 and the external arg1 is ignored. After the block ends, the internal `arg1` is deleted and the external `arg1` is used. Generally speaking, this is confusing, so probably best to avoid without very good reason.

In the last question the include statement is at the end of the code. If we move that to the beginning it will compile. Interestingly, it only doesn't compile because we use `cout` before `iostream` is included. If we put something like `#include<string>` after main, it will still compiler because main doesn't need to use strings.

### 4 Factorial Gone Wrong
#### 4.1
Here is a factorial program:
```
#include <iostream>

using namespace std;

int main (){
	short number ;
	cout << "Enter a number:";
	cin >> number;
	
	cout << "The factorial of " << number << " is ";
	int accumulator = 1;
	for (; number > 0; accumulator *= number--);
	cout << accumulator << ".\n";
	return 0;
}
```
What do you get when you enter the following values: 0, 1, 2, 9, 10?

Tracing through the code (and running the code to verify), we get:  
* 0 gives 1 (the for loop does not run)
* 1 gives 1 (the for loop runs 1 step, multiplying by number, then decrementing, recall that -- after returns the value and then decrements)
* 2 gives 2 (the for loop runs two steps, accumulator multiplies by 2 and then 1, similar to above)
* 9 gives 362880
* 12 gives 479001600

One thing to note is that number is a short, which is the small version of `int` having 16 bits. Reading the documentation it sounds like `int`'s size depends on the system. On x64 systems, it will be 32 bits. The `short` should be upcast before multiplying.

#### 4.2 Breaking the Program
Running the program with -1 gives 1. In fact, it will do this for any negative number. It behaves exactly like the zero case, where loop does not run. It should be undefined. One fix is to put the for loop and subsequent `cout` in an if block conditioning on the number.

#### 4.3 Breaking the Program II
The upper limit is when the factorial gets too big to be properly represented by integers, in this case 32 bit numbers. So since the `INT_MAX` is 2147483647, we have:  
12! = 479,001,600 < 2,147,483,647  
13! = 6,227,020,800 > 2,147,483,647  
And we see that indeed 13! cannot be properly represented.

#### 4.5 Further testing
To be honest, the long long trick used is a patch and not a solution. The entire way the math would have to be done would have to change though. Languages like FORTRAN allow for freely requesting blocks of memory, so you could make a single number sufficiently large for the factorial just by creating a custom type. In C++, I would likely make an array or vector of digits of some allocated size based on the factorial itself (there is probably some proof out there relating the n in n! to the number of digits the result will have, otherwise vectors are much easier to use). I would then perform the math by hand (think multiplying large numbers like in elementary school, carrying ones and what not). See the `largeFactorial` code to see how this works.

The other thing to test would be nonsense input. It seems like `cin` is pretty good about not crashing, but it can also lead to weird behavior. For example, if I enter a character, say 'a', it sets the value of the input to zero and `cin` enters an error state. However, the factorial of the letter "a" is nonsense. Thus, I would also do some input scrubbing to make sure that `cin` actually received an integer input.
