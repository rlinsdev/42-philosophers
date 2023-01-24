
<div align="center">

<!-- <p align="center">
	<img src="https://i2.wp.com/www.aponia-dental-center.com/fachzahnarztliche-praxis/wp-content/uploads/2014/01/work-in-progress.png?fit=286%2C253" alt="Working Progress">
</p> -->

</div>


# Philosophers
42 Project Aux tests and definitions



## Definitions
* Data Races: Occur when multiple tasks or threads access a shared resource without sufficient protections
* Mutex: MUTual EXclusion - Protect the execution again other threads running at the same time.
* Semaphore: Some kind of mutex, but with counter


## External functions.
| function | Description |
|-							|-		 |
|`memset`					| ToDo
|`printf`					| ToDo
|`malloc`					| ToDo
|`free`						| ToDo
|`write`					| ToDo
|`usleep`					| ToDo
|`gettimeofday`				| sys/time.h - get / set time
|`pthread_create`			| pthread.h - Thread creation
|`pthread_detach`			| pthread.h - When a detached thread terminates, its resources are automatically released back to the system
|`pthread_join`				| pthread.h - function waits for the thread specified by thread to terminate
|`pthread_mutex_init`		| pthread.h - destroy and initialize a mutex
|`pthread_mutex_destroy`	| pthread.h - destroy and initialize a mutex
|`pthread_mutex_lock`		| pthread.h - lock and unlock a mutex
|`pthread_mutex_unlock`		| pthread.h - lock and unlock a mutex


## Commands:
```Shell
#Generate code in machine language
$ gcc -S main.c
$ ./philo 5	86400000 3600000 28800000 2
```

## To Test:
* Valgrind with race condition

## Links
[Code Vault - Playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

[What are Race conditions?](https://www.youtube.com/watch?v=FY9livorrJI)

[Mutex in C?](https://youtu.be/oq29KUy29iQ)

[Deadlock C?](https://youtu.be/LjWug2tvSBU)

[Semaphores?](https://youtu.be/YSn8_XdGH7c)

[Dining philosophers problem](https://youtu.be/FYUi-u7UWgw)

[Dining philosophers problem 2](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

[Dining philosophers problem 3](https://www.ecb.torontomu.ca/~courses/coe518/Labs/lab4/lisi.edu-dining-Philosopherecture8.pdf)

[Dining philosophers problem 4](https://www.youtube.com/watch?v=knJ4MHWPIwk)
