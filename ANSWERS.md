**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- New - A process is that will soon be created. It is being help in memory for the operating system to create a process from.
- Ready State - A process has been created and are in a queue waiting for the operating system to give the process CPU time.
- Run - The CPU has picked the process to run and the process is executed on one of the CPU cores.
- Blocked - A process enters blocked state when it is awaiting input from a user. Once the action is completed the process goes back into ready state.
- Terminated - The process is completed and killed along with teh process control block.

**2. What is a zombie process?**

- A zombie process is a child process created by a fork, that has finished executing but is has not been exited yet by it's parent process.

**3. How does a zombie process get created? How does one get destroyed?**

- A zombie process gets created when a parent process executes its task and exits, before reading the exit status of a child to terminate the child process. If the exit status isn't read by the parent the child process will remain in the process table. One way to prevent a zombie process is to use the wait() system call in the parent process, which will make the parent stop executing it's process until the child process has finished.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- A compiled language has the advantage of completing all of the translation into machine code needed to execute the program once, which can then be loaded and ran any number of times without needing to do the translation again.
