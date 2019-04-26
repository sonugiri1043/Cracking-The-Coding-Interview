## Random Crashes:
You are given the source to an application which crashes when it is run. After
running it ten times in a debugger, you find it never crashes in the same place. The application is
single threaded, and uses only the C standard library. What programming errors could be causing
this crash? How would you test each one?

## Solution
we can give some general causes of random crashes.
- **Random Variable:** The application may use some random number or variable component that may not
be fixed for every execution of the program. Examples include user input, a random number generated
by the program, or the time of day.
- **Uninitialized Variable:** The application could have an uninitialized variable which, in some languages,
may cause it to take on an arbitrary value. The values of this variable could result in the code taking a
slightly different path each time.
- **Memory Leak:** The program may have run out of memory. Other culprits are totally random for each run
since it depends on the number of processes running at that particular time. This also includes heap
overflow or corruption of data on the stack.
- **Externel Dependencies:** The program may depend on another application, machine, or resource. If there
are multiple dependencies, the program could crash at any point.