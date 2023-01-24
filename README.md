
<div align="center">

<p align="center">
	<img src="https://i2.wp.com/www.aponia-dental-center.com/fachzahnarztliche-praxis/wp-content/uploads/2014/01/work-in-progress.png?fit=286%2C253" alt="Working Progress">
</p>

</div>


# Philosophers:
TODO



## Definitions:
* Data Races: Occur when multiple tasks or threads access a shared resource without sufficient protections
* Mutex: MUTual EXclusion - Protect the execution again other threads running at the same time.
* Semaphore: Some kind of mutex, but with counter

## Parameters:
* **number_of_philosophers**: The number of philosophers and also the number of forks.
* **time_to_die**: (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
* **time_to_eat**: (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
* **time_to_sleep**: (in milliseconds): The time a philosopher will spend sleeping.
* **number_of_times_each_philosopher_must_eat**: (optional argument): If all philosophers have eaten at least _this parametrized_ times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.



## New external functions.
| function | Description |
|-							|-		 |
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



