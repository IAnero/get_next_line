# get_next_line

A C function that reads and returns the next line from a file descriptor. Implements efficient buffered line reading with support for arbitrary buffer sizes and multiple file descriptors.

## Overview

`get_next_line` is a core I/O utility that reads one line at a time from any file descriptor (files, pipes, standard input, etc.). The function preserves the newline character in the returned string and manages internal state to seamlessly handle subsequent calls. A bonus implementation supports simultaneous reading from up to 4096 different file descriptors.

## Features

- **Buffered Reading**: Configurable buffer size via `BUFFER_SIZE` macro (default: 10 bytes)
- **Memory Efficient**: Linked-list based buffer management with proper cleanup
- **Multi-FD Support** (bonus): Read from multiple file descriptors concurrently
- **Robust Error Handling**: Returns `NULL` on EOF or read errors
- **Standards Compliant**: Uses only POSIX functions and standard C library

## Implementation

### Architecture

The implementation uses a linked-list structure to manage partial reads and buffer overflow:

```
t_list {
    char *str;        // Partial buffer data
    t_list *next;     // Next node in chain
}
```

### Core Functions

| Function | Purpose |
|----------|---------|
| `get_next_line(int fd)` | Read and return the next line from `fd` |
| `create()` | Fill buffer from file descriptor |
| `linking_the_list()` | Build linked list of buffer chunks |
| `get_before_newline()` | Extract line content up to newline |
| `after_newline()` | Manage remaining buffer after line extraction |
| `all_free()` | Clean up nodes and deallocate memory |

### Bonus (Multi-FD)

The bonus version maintains a static array of up to 4096 independent linked lists, enabling concurrent reading from multiple file descriptors without interference.

## Compilation

### Standard Version

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o program
```

### Bonus Version (Multiple File Descriptors)

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o program
```

**Note**: `BUFFER_SIZE` can be redefined at compile time. If omitted, defaults to 10.

## Usage

### Basic File Reading

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    
    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Reading from Multiple Files (Bonus)

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);
char *line3 = get_next_line(fd1);  // Next line from file1

// Clean up
free(line1);
free(line2);
free(line3);
close(fd1);
close(fd2);
```

## Technical Details

### Memory Management

- Each `get_next_line()` call returns dynamically allocated memory (`malloc`)
- Caller is responsible for freeing returned strings
- Internal state is maintained via `static` pointers (one for standard, array of 4096 for bonus)
- Proper cleanup on error conditions prevents memory leaks

### Buffer Management

- Reads up to `BUFFER_SIZE` bytes per system call
- Handles arbitrary line lengths by chaining buffers
- Preserves newline character in returned string (important for some use cases)
- Returns `NULL` when no more lines available or on read error

### Edge Cases

- Empty lines (single `\n`) are returned as `"\n"`
- Lines without trailing newline (last line of file) are returned as-is
- Returns `NULL` for invalid file descriptors (`< 0`)
- Returns `NULL` if `BUFFER_SIZE <= 0`

## Requirements

- POSIX-compliant system
- C compiler supporting C89/C99
- Standard C library (`libc`)

## Files

```
├── get_next_line.h              # Header for standard version
├── get_next_line.c              # Main implementation
├── get_next_line_utils.c        # Helper functions
├── get_next_line_bonus.h        # Header for bonus version
├── get_next_line_bonus.c        # Multi-FD implementation
└── get_next_line_utils_bonus.c  # Bonus helper functions
```

## Notes

- Static variables are used to preserve state between calls on the same file descriptor
- The bonus implementation's 4096-FD limit is based on typical `ulimit` constraints
- Memory is allocated per read operation; performance optimizations may batch allocations
- The function is not thread-safe due to static state management

## License

Part of the 42 School curriculum.
