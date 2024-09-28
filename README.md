# 42-push_swap, by Maxime Rochedy

Welcome to my implementation of **push_swap**, a sorting algorithm project undertaken during my time at **École 42**. In this repository, you will find my complete solution to the **push_swap** project, which successfully received a perfect score of **125/100**. This project aims to sort stacks of integers using a limited set of operations. Specifically, I used the **Turkish Algorithm** to solve this challenge.

In addition to the core sorting functionality, I also implemented the **bonus feature**, which is a **checker** to verify the correctness of the sequence of operations produced by the **push_swap** program. The checker confirms that the sequence of operations actually sorts the input list, enhancing the reliability and usability of the project.

This **push_swap** project was designed to further develop my algorithmic thinking, my understanding of data structures, and my problem-solving skills. I hope this repository is helpful for those looking to understand **push_swap**.

## About the Project

This repository presents my complete implementation of the **push_swap** project, part of the **42** curriculum. It was developed by **Maxime Rochedy**, under the login **mrochedy**. The goal of **push_swap** is to sort stacks of integers using two auxiliary stacks and a set of predefined operations, all while minimizing the number of moves, and the Turkish approach helps achieve this goal by focusing on operational efficiency.

Please be mindful that the solutions provided here are for **learning purposes**—copying them outright goes against the **42 school's policies on plagiarism**. Use the repository responsibly to grow your understanding of data structures and sorting algorithms.

## Getting Started

To run this **push_swap** project on your system, clone the repository and compile the code using **Make**. Here are the steps:

```bash
git clone https://github.com/mrochedy/42-push_swap.git
cd 42-push_swap
make
```

After compilation, you can run the **push_swap** executable with the desired sequence of integers as arguments to see the sorting in action:

```bash
./push_swap 5 1 4 2 3
```

### Running the Bonus Checker

A **bonus checker** has been implemented to verify the correctness of the generated sequence of operations. To use the checker, first compile the bonus by running:

```bash
make bonus
```

You can then use the checker as follows:

```bash
ARG="5 1 4 2 3"; ./push_swap $ARG | ./checker $ARG
```

This command will execute the **push_swap** program and pipe its output to the **checker** to validate whether the given series of operations successfully sorts the stack.

## How it works

The **push_swap** project relies on a predefined set of operations that can be performed on two stacks (`Stack A` and `Stack B`). These operations are fundamental to implementing the **Turkish Algorithm** for sorting. Below are the primary commands:

- **`sa`**: Swap the first two elements at the top of `Stack A`.
- **`sb`**: Swap the first two elements at the top of `Stack B`.
- **`ss`**: Perform `sa` and `sb` simultaneously.
- **`pa`**: Push the top element from `Stack B` to `Stack A`.
- **`pb`**: Push the top element from `Stack A` to `Stack B`.
- **`ra`**: Rotate `Stack A` upwards, moving the first element to the last position.
- **`rb`**: Rotate `Stack B` upwards.
- **`rr`**: Perform `ra` and `rb` simultaneously.
- **`rra`**: Reverse rotate `Stack A`, moving the last element to the first position.
- **`rrb`**: Reverse rotate `Stack B`.
- **`rrr`**: Perform `rra` and `rrb` simultaneously.

These operations are combined strategically to implement the **Turkish Algorithm** in a way that ensures the stacks are sorted with the minimum possible number of moves.

### The Turkish Algorithm

The **Turkish Algorithm** allows an approach that is focused on minimizing the total number of operations required to sort the input stack. Although it may not be the most computationally efficient algorithm in terms of processing time, it excels at reducing the number of moves, making it ideal for the **push_swap** challenge, where move count is key. Below is a step-by-step explanation of how the algorithm works in my **push_swap** implementation:

1. **Sending elements to Stack B**:

   - For each element in **Stack A**, the **cost** of pushing it to the correct position in **Stack B** is calculated. This cost represents the number of operations needed to move an element from its current position in **Stack A** to its appropriate position in **Stack B** in such a way that **Stack B** remains sorted.
   - All elements of **Stack A** are moved to **Stack B**, calculating costs as described above, except for the last three elements.

2. **Sorting the last three elements in Stack A**:

   - Once **Stack B** contains all but three elements, the remaining three elements in **Stack A** are sorted. Since there are only three elements, sorting them is straightforward and requires minimal operations.

3. **Re-integrating elements from Stack B to Stack A**:

   - After **Stack A** is sorted, the next task is to bring elements back from **Stack B** to **Stack A** in the correct order.
   - Similar to the initial transfer, the **cost** of moving each element from **Stack B** to **Stack A** is calculated, and the element with the lowest cost is moved. This process continues until **Stack B** is empty, resulting in a fully sorted **Stack A**.

4. **Final adjustment**:
   - After all elements are back in **Stack A**, a final adjustment is made to position the smallest element at the top of the stack. This final rotation ensures that **Stack A** is sorted from the smallest to the largest value.

### Why the Turkish Algorithm for push_swap?

The **Turkish Algorithm** is well-suited to the **push_swap** project because it focuses on minimizing the number of operations—a critical metric for achieving a high score. While it may not be the fastest algorithm in terms of computational complexity, it excels at achieving an extremely low number of moves, which is the key to scoring well in **push_swap**. With the **Turkish Algorithm**, my implementation can sort:

- **100 elements in fewer than 700 operations**.
- **500 elements in fewer than 5500 operations**.

These performance metrics are within the criteria for obtaining the maximum score for the **push_swap** project at **42**.

## Contributing

If this **push_swap** repository helps you understand sorting algorithms and their application in stack-based environments, please consider **⭐️ starring ⭐️** the project to support its visibility. Contributions are always welcome through pull requests. However, please be respectful of the **42** policies, and do not submit this code as your own for official project submissions.

Thank you for visiting and happy coding!
