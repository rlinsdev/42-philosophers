/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:58:27 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 17:46:50 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define THREAD_NUMB 8

pthread_mutex_t mutexFuel;
int fuel = 50;
pthread_mutex_t mutexWater;
int water = 10;

static void	*routine(void *args) {
	// CHANGE THE ORDER OF LOCK. THIS IS A PROBLEM
	// if (rand() % 2 == 1) {
	// 	pthread_mutex_lock(&mutexFuel);
	// 	sleep(1);
	// 	pthread_mutex_lock(&mutexWater);
	// } else {
		pthread_mutex_lock(&mutexWater);
		// sleep(1);
		pthread_mutex_lock(&mutexFuel);
	// }

	fuel += 50;
	water = fuel;
	printf("Increment fuel to: %d and set water to: %d\n", fuel, water);
	pthread_mutex_unlock(&mutexFuel);
	pthread_mutex_unlock(&mutexWater);
}

int	deadlock()
{
	pthread_t th[THREAD_NUMB];

	pthread_mutex_init(&mutexFuel, NULL);
	pthread_mutex_init(&mutexWater, NULL);
	int i;
	for (i = 0; i< THREAD_NUMB; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
			perror("Failed to create a thread");
		}
	}

		for (i = 0; i< THREAD_NUMB; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join a thread");
		}
	}
	printf("Fuel: %d\n", fuel);
	pthread_mutex_destroy(&mutexFuel);
	pthread_mutex_destroy(&mutexWater);

	return (0);
}
