# C Data Structures & Algorithm Applications

A modular collection of classic data structures, sorting algorithms, and common algorithmic problem implementations in C. 

The structures are designed to be type-aware and generic through the use of `void *` pointers accompanied by a custom `Type` enum mechanism.

---

## 📌 Implemented Structures & Algorithms

### 1. Data Structures
* **Stack**:
  * Array-backed dynamic stack (`ArrayStack`)
  * Linked list-backed stack (`LinkedListStack`)
* **Queue**:
  * Linear array queue (`Queue`)
  * Ring buffer / Circular array queue (`CircularQueue`)
  * Linked list-backed queue (`LinkedListQueue`)
* **Linked List**:
  * Singly linked list with head and tail tracking (`LinkedList`)
  * Circular linked list (`CircularLinkedList`)

### 2. Algorithmic Problems & Utilities
* **Infix to Postfix & Evaluation** (`infinix_to_postfix.c`): Shunting-yard-style operator precedence parser and postfix evaluator.
* **Balanced Braces Verification** (`checkBalancedBraces.c`): Stack-based matching validator for nested blocks.
* **Josephus Problem** (`josephus.c`): Implementation featuring both a simulation via `Queue` and a closed-form $O(\log n)$ mathematical solution.
* **Language & Palindrome Recognition** (`palindrome.c`, `recognizeStringsInLanguage.c`): Symmetry analysis using dual stack/queue buffers.
* **Radix / Base Conversion** (`IntegerToBinary.c`): Bit generation using stack-based reversal.
* **Sorting Algorithms** (`sorting.c`):
  * Selection Sort
  * Insertion Sort
  * Bubble Sort (featuring XOR swap)
  * Merge Sort (Divide & Conquer)
  * Quick Sort (Lomuto Partition Scheme)

---

## 📂 Project Structure

```text
.
├── ArrayStack.c / .h               # Array stack implementation
├── LinkedListStack.c / .h          # List stack implementation
├── CircularQueue.c / .h            # Circular queue implementation
├── Queue.c / .h                    # Linear queue implementation
├── LinkedListQueue.c / .h          # List queue implementation
├── LinkedList.c / .h               # Singly linked list implementation
├── CircularLinkedList.c / .h       # Circular linked list implementation
├── sorting.c                       # Sorting suite (Quick, Merge, etc.)
├── checkBalancedBraces.c           # Bracket checker utility
├── infinix_to_postfix.c            # Expression converter & evaluator
├── josephus.c                      # Josephus problem solutions
├── palindrome.c                    # Palindrome verifier
├── IntegerToBinary.c               # Decimal-to-binary stack converter
```

---

## 🛠️ Build & Run

All source files are compatible with standard C99/C11 compilers (e.g., GCC or Clang).

### Examples

**Infix-to-Postfix Evaluator:**
```bash
gcc -Wall -Wextra -O2 ArrayStack.c infinix_to_postfix.c -o infix_eval
./infix_eval
```

**Circular Queue Test:**
```bash
gcc -Wall -Wextra -O2 CircularQueue.c CircularQueue_test.c -o queue_test
./queue_test
```

**Sorting Suite:**
```bash
gcc -Wall -Wextra -O2 sorting.c -o sorting
./sorting
```

**Balanced Braces Check:**
```bash
gcc -Wall -Wextra -O2 ArrayStack.c checkBalancedBraces.c -o braces_check
./braces_check
```

---

## Key Highlights
- **Generic Data Storage:** Leverages `void *` payloads coupled with tagged types (`Type`) to store arbitrary elements.
- **Low-Level Memory Management:** Explicit allocation (`malloc`) and deallocation (`free`) tracking across list nodes and dynamic buffers.
- **Index Arithmetic:** Efficient circular buffer wrapping using modulo arithmetic (`(index + 1) % capacity`).
