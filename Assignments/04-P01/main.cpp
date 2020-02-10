//////////////////////////////////////////////////////////////////////////////////
//																				                                      //
// Author:           Khethulwazi Kunene											                    //
// Email:            khethokunene@gmail.com										                  //
// Label:            A04														                            //
// Title:            Resize Stack												                        //
// Course:           CMPS 3013													                        //
// Semester:         Spring 2020												                        //
//																				                                      //
// Description:																	                                //
//      This program will read integers in from a file, if the integer is		    //
//		even it will be pushed on to the stack, if the integer is odd then		    //
//		the last even number pushed on the stack will be popped off.			        //
//		The stack has been set to resize when it is full and shrink when		      //
//		half full without dropping below the original stack size.				          //
//////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

/**
* ArrayStack
*
* Description:
*      Array based stack
*
* Public Methods:
*      - See class below
*
* Usage:
*      - See main program
*
*/
class ArrayStack {
private:
	int *A;           // pointer to array of int's
	int size;         // current max stack size
	int top;          // top of stack 
	int maxSize;	  // records the largest size of the stack
	int resizeCount;  // records how many times a resize occurs
public:
	/**
	* ArrayStack
	*
	* Description:
	*      Constructor no params
	*
	* Params:
	*     - None
	*
	* Returns:
	*     - NULL
	*/
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
		maxSize = size;
		resizeCount = 0;
	}

	/**
	* ArrayStack
	*
	* Description:
	*      Constructor size param
	*
	* Params:
	*     - int size
	*
	* Returns:
	*     - NULL
	*/
	ArrayStack(int s) {
		size = s;
		A = new int[s];
		top = -1;
		maxSize = size;
		resizeCount = 0;
	}

	/**
	* Public bool: Empty
	*
	* Description:
	*      Stack empty?
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [bool] true = empty
	*/
	bool Empty() {
		return (top <= -1);
	}

	/**
	* Public bool: Full
	*
	* Description:
	*      Stack full?
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [bool] true = full
	*/
	bool Full() {
		return (top >= size - 1);
	}

	/**
	* Public int: Peek
	*
	* Description:
	*      Returns top value without altering the stack
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [int] top value if any
	*/
	int Peek() {
		if (!Empty()) {
			return A[top];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	* Public int: Pop
	*
	* Description:
	*      Returns top value and removes it from stack
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [int] top value if any
	*/
	int Pop() {
		if (top >= 20 && top == (size / 2)) {
			Shrink();
			resizeCount++;
		}
		if (!Empty()) {
			return A[top--];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	* Public void: Print
	*
	* Description:
	*      Prints stack to standard out
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      NULL
	*/
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}

	/**
	* Public bool: Push
	*
	* Description:
	*      Adds an item to top of stack
	*
	* Params:
	*      [int] : item to be added
	*
	* Returns:
	*      [bool] ; success = true
	*/
	bool Push(int x) {
		if (Full()) {
			ContainerGrow();
			resizeCount++;
		}
		if (!Full()) {
			A[++top] = x;
			return true;
		}

		return false;

	}

	/**
	* Public void: Resize
	*
	* Description:
	*      Resizes the container for the stack by doubling
	*      its capacity
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      NULL
	*/
	void ContainerGrow() {
		int newSize = size * 2;       // double size of original
		int *B = new int[newSize];  // allocate new memory

		for (int i = 0; i< size; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                // delete old array
		maxSize = newSize;			// every time the stack grows set max to new size
		size = newSize;             // save new size

		A = B;                      // reset array pointer

	}

	void Shrink() {
		int newSize = size/2;       // double size of original
		int *B = new int[newSize];  // allocate new memory

		for (int i = 0; i<newSize - 1; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                // delete old array

		size = newSize;             // save new size

		A = B;                      // reset array pointer

	}

	/**
	* Public int: getSize
	*
	* Description:
	*      Returns size of stack without altering the stack
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [int] size of stack
	*/
	int getSize() {
		return size;
	}

	/**
	* Public int: getMaxSize
	*
	* Description:
	*      Returns the largest size of the stack 
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [int] largest stack size
	*/
	int getMaxSize() {
		return maxSize;
	}

	/**
	* Public int: getResizeCount
	*
	* Description:
	*      Returns number of times stack grew and shrunk
	*
	* Params:
	*      NULL
	*
	* Returns:
	*      [int] resize count
	*/
	int getResizeCount() {
		return resizeCount;
	}
};

void openFile(ifstream &infile) {
	char fileName[] = "nums.dat";
	infile.open(fileName);

}

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
	ArrayStack stack;
	ifstream infile;
	int r = 0;
	openFile(infile);

	while (!infile.eof()) {
		infile >> r;
		if (r % 2 == 0) {
			stack.Push(r);
		}
		if (r % 2 > 0) {
			stack.Pop();
		}
	}

	cout << "============================================\n";
	cout << "Assignment 4 - Resizing the Stack\n";
	cout << "CMPS 3013\n";
	cout << "Khethulwazi Kunene\n\n";
	cout << "Max Stack Size: " << stack.getMaxSize() << endl;
	cout << "End Stack Size: " << stack.getSize() << endl;
	cout << "Stack Resized: " << stack.getResizeCount() << " times" << endl;
	cout << "============================================\n";
	infile.close();
	system("pause");
	return 0;
}
