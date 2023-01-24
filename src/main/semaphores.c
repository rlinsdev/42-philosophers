/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:43:47 by rlins             #+#    #+#             */
/*   Updated: 2023/01/23 13:02:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define THREAD_NUM 4

sem_t semaphore;

static void *routine(void *args) {
	sem_wait(&semaphore);
	sleep(1);
	printf("Hello - Thread: %d\n", *(int*)args);
	sem_post(&semaphore);
	free(args);
}

int	func_semaphore(void)
{
	pthread_t th[THREAD_NUM];
	sem_init(&semaphore, 0, 1);

	int i;
	for(i = 0; i < THREAD_NUM; i++) {
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0) {
			perror("Failed to create a Thread");
		}
	}

	for(i = 0; i < THREAD_NUM; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join thread");
		}
	}

	sem_destroy(&semaphore);

	return (0);
}
