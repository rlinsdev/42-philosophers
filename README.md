
<div align="center">

<p align="center">

<!-- <img src="https://game.42sp.org.br/static/assets/achievements/philosophersn.png" alt="Philosophers"> -->
<img src="https://i2.wp.com/www.aponia-dental-center.com/fachzahnarztliche-praxis/wp-content/uploads/2014/01/work-in-progress.png?fit=286%2C253" alt="Working Progress">
</p>

</div>


# Philosophers:
In this project, we must solve the classic problem *diner philosopher* problem



## Definitions / Infos:
* Data Races: Occur when multiple tasks or threads access a shared resource without sufficient protections
* Mutex: MUTual EXclusion - Protect the execution again other threads running at the same time.
* Semaphore: Some kind of mutex, but with counter (Just bonus)
* Each philosopher is a thread and each fork is protected by a mutex.
* There are as many forks as philosophers.

## Parameters:
* **number_of_philosophers**: The number of philosophers and also the number of forks.
* **time_to_die**: (in milliseconds): It's the max time that the philo must stay without eat. Otherwise, he must die. To kill philo, we must calculate the last meal time with this time.
* **time_to_eat**: (in milliseconds): The time it takes for a philosopher to eat. The thread (or philo) will sleep until this time.
During that time, the philo needs hold two forks.
* **time_to_sleep**: (in milliseconds): The time a philosopher will spend sleeping. The thread (or philo) will sleep until this time.
* **number_of_times_each_philosopher_must_eat**: (optional argument): If all philosophers have eaten at least _this parametrized_ times, the simulation stops. If not specified, the simulation stops when a philosopher dies.



## New external functions.
| function | Description |
|-							|-		 |
|`usleep`					| suspend execution for microsecond intervals
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
$ ./philo 3 8100 2000 2000 2
```

## To Test:
* Valgrind with warning DataRace: Turn on flag: `-fsanitize=thread`
* Valgrind with helgrind: Found thread errors: execute `make helgrind`
<!-- * [Socrates framework:](https://github.com/nesvoboda/socrates)

	```Shell
	# in root folder:
	$ git clone https://github.com/nesvoboda/socrates
	$ python3 socrates/socrates.py .
	# Death test take more than 10 min. and crash in the middle
	``` -->
* [Philosphers-42Project-Tester:](https://github.com/newlinuxbot/Philosphers-42Project-Tester)

	```Bash
	# in root folder:
	$ git clone https://github.com/newlinuxbot/Philosphers-42Project-Tester.git
	$ cd Philosphers-42Project-Tester
	$  ./start.sh ../ 1
	# Death test take more than 10 min. and crash in the middle
	```

## Commands Sample:
```Bash
# Test 1: Philo Should not eat and should die
$ ./philo 1 800 200 200
# Test 2: No philo should die
$ ./philo 5 800 200 200
# Test 3: No philo should die and Dinning stop when each eat at least 7x
$ ./philo 5 800 200 200 7
$ ./philo 5 800 200 200 7 | grep 'is eating'
# Test4:  No philo should die
$ ./philo 4 410 200 200
# Test5:  One philo should die
$ ./philo 4 310 200 100
# Test6: 2 philos. Time to death, lower than 10ms
$ ./philo 2 310 200 100
##
##Random tests:
##
$ ./philo 3 8100 2000 2000 2
$ ./philo 2 4100 2000 2000 2
$ ./philo 4 410 200 200 5
$ ./philo 4 410 200 200
$ ./philo 2 800 200 200 2
#Kill philos
$ ./philo 2 60 60 60
$ ./philo 4 310 200 100
```


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

[Geeks for geeks](https://www.geeksforgeeks.org/multithreading-in-c/)



