- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 


- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
- 1 ) Finding the max element in an unordered stack would require O(n) operations
- 2 ) Finding the min element in an unordered queue would require O(n) operations
- 3 ) Finding some element in some Binary Search Tree would require O(log n) operations
- 4 ) Finding some element in a balanced Binary Search Tree would require O(log n) operations
- 5 ) Finding some element in an ordered linked list would require O(n) operations (worst case)
- 6 ) Finding some element in an ordered linked list would require O(n) operations (average case)
- 7 ) Finding some element in an unordered linked list would require O(n) operations (worst case)


- 8) For each of the following, count the number of operations where some_statement is executed based on the loops

- 8A)
```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
//Answer
The statement will be executed (N^2 - N) times        
```
- 8B)
```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
//Answer        
The statement will be executed (N^2 - N)/2 times        
```

- 8C)
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
//Answer        
The statement will be executed (N^2 - 2N + 1)/2 times      
```

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm?

it requires 10 Comparrisons to search a sorted vector using the binary search algorithm.

In each of the following examples, please choose the best data structure(s).
- 9 ) Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- 10 ) Note that there may not be one clear answer.

- 10 ) You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.

Answer)Linked Lists

- 11 ) You need to store undo/redo operations in a word processor.

Answer)Stack

- 12 ) You need to evaluate an expression (i.e., parse).

Answer)Linked Lists

- 13 ) You need to store the friendship information on a social networking site. I.e., who is friends with who.

Answer)Linked Lists

- 14 ) You need to store an image (1000 by 1000 pixels) as a bitmap.

Answer)Array

- 15 ) To implement printer spooler so that jobs can be printed in the order of their arrival.

Answer)Queues

- 16 ) To implement back functionality in the internet browser.

Answer)Hash Tables

- 17 ) To store the possible moves in a chess game.

Answer)Array

- 18 ) To store a set of fixed key words which are referenced very frequently.

Answer)Linked Lists

- 19 ) To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)

Answer)Queues

- 20 ) To store the genealogy information of biological species.

Answer)Graphs

- 21 ) To store an alphabetized list of names in order to look up quickly.

Answer)Array
