# Data Structures - All implementations in C

## Linked Lists

### Singular - singly.c
* Operations:
	- insertFront - O(1)
	- insertEnd - O(n)
	- insertInorder - O(n)
	- delete - O(n)

### Circular - ciruclar.c
* Advantages over singular:
	- Able to traverse to previous node
	- Can be traversed from any node

* Disadvantages over singular:
	- More memory
 
* Operations:
	- insertFront - O(n)
	- insertEnd - O(n)
	- insertInorder - O(n)
	- delete - O(n)

### Doubly - doubly.c
* Advantages over singular:
	- Traversal can be forwards or backwards
	- Even easier than circular to go to previous node

* Disadvantages over singular:
	- More memory
	- Harder to implement, along with ins./del. functions

* Operations:
	- insertFront - O(1)
	- insertEnd - O(1)
	- insertInorder - O(n)
	- delete - O(n)

### Doubly circular - doubly-circular.c
* Advantages over singular:
	- Traversal can be forwards or backwards
	- Can be traversed from any node
	- Even easier than circular to go to previous node

* Disadvantages over singular:
	- More memory
	- Harder to implement, along with ins./del. functions

* Operations:
	- insertFront - O(1)

## Queues
* Operations:
	- enqueue - O(1)
	- dequeue - O(1)
	- isEmpty - O(1)
	- isFull - O(1)
	- init. - O(1)

* Implementations:
	- Array
	- Linked list

## Stacks
* Operations:
	- push - O(1)
	- pop - O(1)
	- isEmpty - O(1)
	- top - O(1)
	- isFull - O(1)
	- init. - O(1)

* Implementations:
	- Array
	- Linked list
