# Chapter 15 - Threads and Locks

## Threads
Threads within a given process share the same memory space.
- Enables threads to share data.
- Issues when multiple threads modify a resource at the same time.

Threads can be implemented in one of two ways in java:
- By implementing the `java.lang.Runnable` interface
- By extending the `java.lang.Thread` class

See examples for java implementations.

## Synchronization
- keyword `synchronized` is used to solve multithreading issues.

Example 1 - Synchronized method:
```
public synchronized void foo(String name) {
    // code goes here
}
```

Example 2 - Synchronized block of code:
```
public class Foo {
    public void bar(String name) {
        synchronized(this) {
            // code goes here
        }
    }
}
```

## Locks
- Used to synchronize access to a shared resource by associating the resource with the lock
- At any given time, at most 1 thread can hold the lock and access the shared resource

### Deadlocks
A deadlock occurs when two threads, thread1 and thread2, is waiting for each others object locks; thread1 is waiting for an object lock that thread2 holds, and thread2 is waiting for an object lock that thread1 holds. This can also occur in similar fashion with multiple threads.

In order for a deadlock to occur, all 4 of the following conditions must be met:
1. Mutual Exclusion: Only one process can access a resource at a given time. (e.g. there is limited access to a resource)
2. Hold and Wait: Processes already holding a resource can request additional resources, without relinquishing their current resources.
3. No Preemption: One process cannot forcibly remove another process' resource.
4. Circular Wait: Two or more processes form a circular chain where each process is waiting on another resource in the chain.

### Deadlock Prevention
- Remove any of the above conditions.
  - Avoiding Mutual Exclusion is difficult - many resources can only be used by one process at a time (e.g. printers).
- Most deadlock prevention algorithms focus on avoiding Circular Wait.
