## Summary

In this project, you are required to create a program that should take a list of integers as input and output a series of operations to sort the list using only two stacks and a specific set of operations.

## Skills to Learn

- Sorting Algorithms
- Stack Manipulation
- Algorithm Optimization
- Problem Solving

## The "push_swap" Program

### Usage

```bash
./push_swap [list of integers]
```

### Description

The "push_swap" program takes a list of integers as arguments and outputs the series of operations needed to sort the list in ascending order using only two stacks, named "stack A" and "stack B". The allowed operations are:

- `sa`: Swap the first two elements at the top of stack A.
- `sb`: Swap the first two elements at the top of stack B.
- `ss`: Do `sa` and `sb` simultaneously.
- `pa`: Push the first element at the top of stack B to stack A.
- `pb`: Push the first element at the top of stack A to stack B.
- `ra`: Rotate stack A upward (all elements move up by one index). The first element becomes the last.
- `rb`: Rotate stack B upward (all elements move up by one index). The first element becomes the last.
- `rr`: Do `ra` and `rb` simultaneously.
- `rra`: Rotate stack A downward (all elements move down by one index). The last element becomes the first.
- `rrb`: Rotate stack B downward (all elements move down by one index). The last element becomes the first.
- `rrr`: Do `rra` and `rrb` simultaneously.
