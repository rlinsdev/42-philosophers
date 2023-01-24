/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_cond_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:38:38 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 17:41:37 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int mails = 0;
pthread_mutex_t mutex; // Create mutex

static void	*routine() {
	// Lock the mutex
	pthread_mutex_lock(&mutex);
	for (int i = 0; i < 1000000; i++) { // Error
	// for (int i = 0; i < 100; i++) { // OK
		mails++;
	}
	// Unlock mutex
	pthread_mutex_unlock(&mutex);
}

int	race_cond()
{
	pthread_t p1, p2;
	pthread_mutex_init(&mutex, NULL); // Initialize Mutex

	if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
		return (1);
	}
	if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
		return (2);
	}
	if (pthread_join(p1, NULL) != 0) {
		return (3);
	}
	if (pthread_join(p2, NULL) != 0) {
		return (4);
	}

	pthread_mutex_destroy(&mutex); //  Destroy - remove from memory
	printf("Number of mails: %d\n", mails);
	return (0);
}
