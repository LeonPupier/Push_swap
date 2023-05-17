# Push-Swap

This project was completed as part of the curriculum at École 42. The goal of the project is to sort a stack of integers using a limited set of operations. 

## Installation

To install and run the program, follow these steps:

1. Clone the repository to your local machine.
2. Open a terminal window and navigate to the root directory of the project.
3. Run the command `make` to compile the program.
4. Run the program using the command `./push_swap [list_of_numbers]`.

## Usage

The program takes a list of integers as a command-line argument and sorts them using the following operations:

- `sa`: swap the first two elements of stack A.
- `sb`: swap the first two elements of stack B.
- `ss`: do `sa` and `sb` simultaneously.
- `pa`: push the first element of stack B onto stack A.
- `pb`: push the first element of stack A onto stack B.
- `ra`: rotate stack A so that the first element becomes the last.
- `rb`: rotate stack B so that the first element becomes the last.
- `rr`: do `ra` and `rb` simultaneously.
- `rra`: reverse rotate stack A so that the last element becomes the first.
- `rrb`: reverse rotate stack B so that the last element becomes the first.
- `rrr`: do `rra` and `rrb` simultaneously.

The program must output a list of operations that sorts the stack in ascending order using the smallest number of operations possible.

## Example

Here's an example of how to use the program to sort a stack of numbers:

```bash
$ ./push_swap 3 1 4 2
sa
ra
sa
rra
```

In this example, the program sorts the stack `[3, 1, 4, 2]` using the operations `sa`, `ra`, `sa`, and `rra`.

## Credits

This project was completed by Léon Pupier as part of the curriculum at École 42.
