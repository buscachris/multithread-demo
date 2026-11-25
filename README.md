# Shared counters with POSIX threads

I wrote two C programs to see what happens when multiple threads update the same counter. In the [mutex example](threads_demo.c), five workers each increment it five times. I protect each update with a mutex and join the workers before printing the final value of 25.

In the [race example](threads_race.c), ten workers each attempt 1,000 updates. The code pauses between reading and writing the counter without locking it. The resulting data race makes the final value unreliable.

## Run the synchronized example

```sh
cc -pthread threads_demo.c -o /tmp/threads-demo
/tmp/threads-demo
```

I can compile `threads_race.c` the same way to inspect its interleaved output. The two programs use different workloads.
