# Multithreaded Counter Demo (POSIX Threads)

This project demonstrates:

- Thread creation using pthreads
- Shared memory between threads
- Mutex-based synchronization
- Race condition prevention
- Thread lifecycle behavior
- Context switching effects

## Build

gcc -O2 -Wall -Wextra -pthread threads_demo.c -o threads_demo

## Run

./threads_demo

Expected final output:
Final shared_counter value: 25 (Expected: 25)

Remove the mutex to demonstrate race conditions.
