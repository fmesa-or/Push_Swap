<div align="center">

# Push_Swap

![Norminette](https://img.shields.io/badge/Norm-passing-brightgreen?style=flat-square) ![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white) ![Makefile](https://img.shields.io/badge/Makefile-427819?style=flat-square) ![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat-square&logo=linux&logoColor=black) ![macOS](https://img.shields.io/badge/macOS-000000?style=flat-square&logo=apple&logoColor=white) ![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square)

*An efficient sorting algorithm using two stacks.*

</div>

---

## About the Project

Push_Swap is a sorting algorithm project that uses two stacks to sort a sequence of integers with the minimum number of operations. The program implements various stack operations (push, swap, rotate, reverse rotate) and uses optimized search algorithms to find the most efficient sorting strategy.

## Requirements

- Compiler: `gcc`
- Flags: `-Wall -Wextra -Werror`
- OS: Linux / macOS
- Standard: C99 or later

## Installation and Usage

### Building

```bash
# Clone the repository
git clone https://github.com/usuario/Push_Swap.git
cd Push_Swap

# Compile the executable
make

# Clean build artifacts
make clean

# Remove all generated files including the executable
make fclean

# Rebuild everything
make re
```

### Running the Program

```bash
# Basic usage with arguments
./push_swap 3 2 1 0

# Pipe output to checker (checker needed)
ARG="5 3 2 1 4"; ./push_swap $ARG | ./checker_linux $ARG

# Count total operations
ARG="5 3 2 1 4"; ./push_swap $ARG | wc -l
```

## Testing

### Generate Random Numbers

Use this resource to generate random test numbers:
[Random Number Generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

### Verify Correctness

```bash
# Test with specific numbers
ARG="5 3 2 1 4"; ./push_swap $ARG | ./checker_linux $ARG

# Count operations
ARG="5 3 2 1 4"; ./push_swap $ARG | wc -l
```

## Memory Leak Detection

### Using Valgrind / Leaks

To check for memory leaks:

```bash
valgrind ./push_swap 3 2 1 0
leaks --atExit -- ./push_swap 3 2 1 0
```

#### Useful Flags for Valgrind

| Flag | Purpose |
|------|---------|
| `--leak-check=full` | Show details of leaked memory |
| `--leak-check=full --show-leak-kinds=all` | See all leaks and their locations |
| `--track-origins=yes` | Identify where uninitialized values come from |
| `--log-fd=1` | Output log to stdout |
| `--show-leaks-kinds=all` | Display all types of leaks |
| `--suppressions=suppressions.supp` | Use suppression file for known issues |

#### Example with Full Output

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 3 2 1 0
```

### Using LLDB Debugger

For low-level debugging:

```bash
lldb ./push_swap
(lldb) run 3 2 1 0
(lldb) break set -f main.c -l 10
(lldb) continue
(lldb) print variable_name
```

## Implementation Details

### Supported Operations

- `sa` - Swap first two elements of stack A
- `sb` - Swap first two elements of stack B
- `ss` - Execute sa and sb
- `pa` - Push top element from stack B to stack A
- `pb` - Push top element from stack A to stack B
- `ra` - Rotate stack A upwards
- `rb` - Rotate stack B upwards
- `rr` - Execute ra and rb
- `rra` - Reverse rotate stack A
- `rrb` - Reverse rotate stack B
- `rrr` - Execute rra and rrb

### File Structure

```
.
├── Makefile                 # Compilation rules
├── include/
│   └── push_swap.h          # Header file with function declarations
├── lib/
│   ├── ft_printf/           # Printf utility library
│   └── libft/               # Standard C functions library
├── src/
│   ├── main.c               # Main program entry
│   ├── algorithm.c          # Sorting algorithms
│   ├── sort_*.c             # Specific sorting implementations
│   ├── checkers.c           # Input validation
│   ├── errors.c             # Error handling
│   ├── ft_*.c               # Utility functions
│   └── Makefile             # Section-specific compilation
└── README.md                # This file
```

## Compilation Notes

- The program is compiled as an executable: `push_swap`
- Includes custom implementations of libft and ft_printf
- Follows the 42 School Norm standards
- All functions are optimized for minimal stack operations
- Proper memory management with valgrind verification

## Performance Optimization

### Algorithm Complexity

- Small stacks (5 numbers): ≤ 12 operations
- Large stacks (100 numbers): ≤ 1,500 operations
- Large stacks (500 numbers): ≤ 11,500 operations

### Testing Performance

```bash
# Generate random numbers and test on Linux
ARG="$(seq 1 100 | shuf | tr '\n' ' ')"; ./push_swap $ARG | wc -l

# Generate random numbers and test on macOS
ARG="$(seq 1 100 | jot -r 36 10000000 99999999 | tr '\n' ' ')"; ./push_swap $ARG | wc -l
```

---

<div align="center">
Made with ☕ at <a href="https://42malaga.com">42 Málaga</a>
</div>