 **Custom Shell Project**

This project implements a simple Unix shell in C, allowing users to execute commands, manage processes, and use built-in functions such as `cd` and `exit`. It mimics the behavior of standard shells like `bash` or `sh` but with basic functionality.

---

## **Features**
- Execute built-in commands: `cd` and `exit`.
- Execute external commands (e.g., `/bin/ls`).
- Tokenize user input and pass arguments.
- Signal handling for graceful process management.
- Works with standard Unix environment variables.

---

## **Dependencies**
The following standard C libraries are included in `shell.h` to support various features:

### **Standard Libraries**
1. **`#include <stdio.h>`**  
 - Provides functions for input/output, such as `printf`, `perror`, and `getline`.  
 - Used for reading commands from the user and printing messages.

2. **`#include <stdlib.h>`**  
 - Provides memory management (`malloc`, `free`), program control (`exit`), and other utility functions like `_strdup`.

3. **`#include <string.h>`**  
 - Used for string manipulation, such as tokenizing strings (`strtok`) and copying/concatenating strings (`strcpy`, `strcat`).

4. **`#include <unistd.h>`**  
 - Provides access to the POSIX operating system API, including functions for process management (`fork`, `execve`), directory navigation (`chdir`), and file descriptors.

### **System-Specific Libraries**
5. **`#include <sys/wait.h>`**  
 - Allows the parent process to wait for the child process to finish execution using `wait`.

6. **`#include <fcntl.h>`**  
 - Used for file control, including manipulating file descriptors (though not explicitly in the current implementation).

7. **`#include <signal.h>`**  
 - Used to handle signals (e.g., ignoring `SIGINT` in this shell).

8. **`#include <sys/types.h>` and `#include <sys/stat.h>`**  
 - Support file attributes and types, useful for file and process-related operations.

### **Additional Libraries**
9. **`#include <ctype.h>`**  
 - Provides functions for character checks and transformations (e.g., `isdigit` for parsing numeric arguments in `_atoi`).

### **External Variables**
10. **`extern char **environ;`**  
 - Gives access to the environment variables of the current process, used when executing commands with `execve`.

---

## **Function Definitions**
The `shell.h` file also declares the following functions:

### **Main Shell Functions**
- `void type_prompt(void);`  
 - Displays a shell prompt for user interaction.

- `int handle_builtins(char *command, char **parameters);`  
 - Handles built-in commands like `cd` and `exit`.

- `void read_command(char cmd[], char *par[]);`  
 - Reads user input and tokenizes it into commands and parameters.

- `void execute_command(char *command, char **parameters);`  
 - Executes valid commands by checking if they are built-in or external.

- `void execute_external_command(char *command, char **parameters);`  
 - Executes external commands using the `/bin/` path.

### **Utility Functions**
- `int _strlen(char *s);`  
 - Returns the length of a string.

- `char *_strcat(char *dest, char *src);`  
 - Concatenates two strings.

- `int _strcmp(char *s1, char *s2);`  
 - Compares two strings.

- `char *_strcpy(char *dest, char *src);`  
 - Copies a string to another.

- `char *_strdup(const char *str);`  
 - Duplicates a string in memory.

- `int _atoi(char *s);`  
 - Converts a string to an integer.

---

## **How to Run the Project**

### **Clone the Repository**
1. Clone the repository using Git:  
   ```bash
   git clone https://github.com/Only1allan/simple_shell.git
   cd simple_shell`` 

### **Compile the Code**

2.  Compile all `.c` files into an executable named `my_shell`:
    
    bash
    
    Copy code
    
    `gcc -Wall -Werror -Wextra -pedantic *.c -o my_shell` 
    

### **Run the Shell**

3.  Start the shell:
    
    bash
    
    Copy code
    
    `./my_shell` 
    

### **Use the Shell**

4.  Enter commands like you would in a typical shell:
    -   List directory contents:
        
        bash
        
        Copy code
        
        `ls -l` 
        
    -   Change directories:
        
        bash
        
        Copy code
        
        `cd /path/to/directory` 
        
    -   Exit the shell:
        
        bash
        
        Copy code
        
        `exit` 
        

----------

## **Known Limitations**

-   Currently supports only basic commands and simple pipes.
-   Error handling can be improved for invalid inputs or commands.

----------

## **License**

This project is open-source and free to use under the MIT License.
