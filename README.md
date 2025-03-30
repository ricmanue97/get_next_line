# Get Next Line

## Overview
`get_next_line` is a function designed to read a line from a file descriptor. This function is useful for reading text files line by line, either from a file or from standard input. The function ensures that each line read includes the terminating newline character (`\n`), except when the end of the file is reached and the file does not end with a newline character.

## Function Prototype
```c
char *get_next_line(int fd);
```

## Files to Submit
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

## Parameters
- `fd`: The file descriptor to read from.

## Return Value
- **Read line**: Returns the line read from the file descriptor.
- **NULL**: Returns NULL if there is nothing else to read or if an error occurred.

## External Functions
- `read`
- `malloc`
- `free`

## Description
The `get_next_line` function reads a line from a file descriptor and returns it. Repeated calls to `get_next_line` in a loop will read the text file pointed to by the file descriptor, one line at a time. 

### Behavior
- The function should return the line that was read.
- If there is nothing left to read or if an error occurs, it should return NULL.
- Ensure the function works as expected both when reading a file and when reading from the standard input.
- The returned line should include the terminating newline character (`\n`), except when the end of the file is reached and the file does not end with a newline character.

### Header File
- The header file `get_next_line.h` must at least contain the prototype of the `get_next_line` function.

### Helper Functions
- Add all the necessary helper functions in the `get_next_line_utils.c` file.
- Understanding static variables could be beneficial.

## Compilation
To compile the project, use the following command (example with a buffer size of 42):
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

### Buffer Size
- The buffer size value can be adjusted for testing purposes.
- The project must be compilable with and without the `-D BUFFER_SIZE` flag.

### Edge Cases
- Handle cases where the buffer size is very small (e.g., 1) or very large (e.g., 9999).

### Forbidden
- Usage of `libft` is not allowed.
- `lseek` is forbidden.
- Global variables are forbidden.

### Notes
- Ensure to read as little data as possible each time `get_next_line` is called.
- If a newline character is encountered, return the current line immediately.
- Avoid reading the whole file before processing each line.
- `get_next_line` exhibits undefined behavior if the file associated with the file descriptor is modified after the last call while `read` has not yet reached the end of the file.
- `get_next_line` also exhibits undefined behavior when reading a binary file. You can implement a logical way to handle this behavior if desired.

## Conclusion
Implementing `get_next_line` will help simplify the process of reading lines from a file descriptor, making it more efficient and manageable.
