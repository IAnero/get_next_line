Get Next Line
📝 Description

get_next_line is a function that reads a line from a file descriptor, including the newline character.
It allows you to read from files or standard input one line at a time, without losing the rest of the content.

📂 Content

get_next_line.c / .h → main function.

get_next_line_utils.c → helper functions.

Bonus: supports multiple file descriptors at the same time.

⚙️ Usage

Clone this repository
```
git clone <your_repo_url>
cd get_next_line
```

Compile with your program
```
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

Or for bonus:
```
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```
✅ Example
```
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```
📌 Notes

Returns NULL when there is nothing more to read or on error.

Works with both files and standard input.
