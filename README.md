PUSH_SWAP

## Description

**push_swap** is a sorting algorithm project that computes a minimal sequence of stack instructions to sort a list of integers. The goal is to implement efficient custom algorithms using two stacks (`a` and `b`), with limited permitted operations.

This project improves understanding of pointer management, linked list or array stack simulation, and algorithmic complexity. It also strengthens knowledge of condition parsing, error handling, and optimization for minimal instruction count.
It is part of the curriculum at **42**.

### Supported Features

- Parsing of integer arguments with strict validation
- Detecting duplicates and invalid numbers
- Sorting using stack operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Special-case sorting for 2/3/4/5 elements for low push count
- Adaptive strategy for medium/large sizes
- Output of valid move list to standard output
- Efficient handling of worst-case scenarios
- Compatible with `checker` program for verification

## Instructions

### Installation and Setup

Makefile Commands:

`make` : Compiles the push_swap executable.

`make clean` : Removes object files (.o).

`make fclean` : Removes object files and the binary executable.

`make re` : Recompiles the entire project.`

### Example Usage

```bash
./push_swap 5 2 3 1 4
```

Output is a list of operations, for example:
```
pb
pb
sa
pa
pa
```

## Resources

**References:**

- [Linux man page - malloc/free](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [GeeksforGeeks - radix sort/ chunk sort/ selection sort](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [Openclassrooms - C Programming](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c)
- [CommentCaMarche](https://web.maths.unsw.edu.au/~lafaye/CCM/c/cop.htm)
- [w3schools](https://www.w3schools.com/dsa/dsa_algo_radixsort.php)
- [CS people](https://people.cs.pitt.edu/~lol16/CS1501_sp17/data/radix_sort.pdf)
- [doc radix sort](https://www.cs.helsinki.fi/u/tpkarkka/opetus/13s/spa/lecture03.pdf)

**Tutorials (YouTube) and articles on:**
- Memory management in C and avoiding memory leaks
- Stack algorithms and sorting strategies
- Parsing command-line arguments safely
- Debugging and unit testing in C

### Use of AI

**AI was used to:**

- Clarification of theoretical concepts related to C programming, stack operations, and algorithmic optimization
- Assistance with writing, translating, and correcting spelling and grammar errors in the README file

AI was not used to write the core implementation logic.

## Algorithm and Technical Choices

The push_swap program uses a combination of simple deterministic algorithms and adaptive methods for larger data sets.

### Algorithm

- 1 - Parse all arguments and validate input (integers, duplicates, overflow).
- 2 - Convert values to indexed ranks to normalize value range.
- 3 - If size <= 5, use dedicated sort routines (`sort_3`, `sort_4`, `sort_5`).
- 4 - For size > 5, evaluate disorder ratio from stack `a`.
- 5 - `sort_adaptive()` chooses:
  - `sort_simple()` when mostly sorted,
  - `sort_medium()` when semi-random,
  - `sort_complex()` when highly disordered.
- 6 - Emit stack operations step-by-step.
- 7 - Ensure final stack `a` is sorted and stack `b` empty.

### sort_simple : *Selection Sort ($O(n^2)$)*

- Find minimal element position by `get_min_pos()`.
- Rotate (`ra`) or reverse rotate (`rra`) to bring minimal to top.
- Push to `b` (`pb`) until `a` is empty.
- Restore all values from `b` to `a` with `pa`.

### sort_medium : *Chunk Sort ($O(n\sqrt{n})$)*

- Use indexed range strategy (`get_range()`, `push_to_b()`) to offload elements progressively.
- Push element to `b` and optionally rotate `b` to keep larger values near top.
- After all from `a` are in `b`, rebuild `a` with `push_back_to_a()` using max position rotations.

### sort_complex : *Radix Sort ($O(n \log n)$)*

- Use binary radix sort on index bits.
- Repeat for each bit position up to `max_bits`.
- Push elements with bit 0 to `b` and rotate bit 1 in `a`.
- Reassemble `a` by merging from `b` with `pa`.

### Data Structure

- `int *stack_a`, `int *stack_b` (or equivalent via linked list)
- `int size_a`, `int size_b`
- `int *indexed_values` for rank mapping
- auxiliary counters and rotation infos

### Key Functions

- `parse_input()` - validate input and build initial stack
- `apply_sort()` - select sorting strategy and run it
- `index_stack()` - compress numbers into ranks
- `sort_3()`, `sort_4()`, `sort_5()` - minimal operation sorting small cases
- `sort_simple()` / `sort_medium()` / `sort_complex()` - scalable sorting strategies
- `sort_adaptive()` - picks algorithm based on disorder
- `push()`, `swap()`, `rotate()`, `reverse_rotate()` - stack operation implementations

### Justification

- **Indexed values:** simplify comparisons and reduce edge-case behavior.
- **Modular functions:** easier debugging and isolated logic per operation.
- **Non-recursive simple approach:** minimal memory overhead and predictable behavior.
- **Safe NULL handling:** checks before dereference to avoid segmentation faults.
- **Output compliance:** conform to `push_swap` grading requirement of one operation per line.


## Contributors

- **henirako**: Responsible for implementing the core sorting algorithms (sort_simple, sort_medium, sort_complex) and the adaptive sorting logic. Also managed the project structure and documentation.
- **nfitahin**: Handled input parsing, validation, stack operations, and utility functions. 


This approach ensures the program is **efficient, readable, and fully compliant** with the 42 `push_swap` subject requirements.
