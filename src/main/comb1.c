/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:49:57 by rlins             #+#    #+#             */
/*   Updated: 2023/01/24 06:43:55 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define TIMES_TO_COUNT 210

#define NC		"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"

typedef struct s_counter
{
	pthread_mutex_t count_mutex;
	unsigned int count;
} t_counter;

static void *thread_routine(void *data);

int	comb1()
{
	pthread_t tid1;
	pthread_t tid2;

	t_counter counter;
	counter.count = 0;

	pthread_mutex_init(&counter.count_mutex, NULL);

	printf("Main: Expected count is %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);

	pthread_create(&tid1, NULL, thread_routine, &counter);
	printf("Created first thread[%ld]\n", tid1);

	pthread_create(&tid2, NULL, thread_routine, &counter);
	printf("Created first thread[%ld]\n", tid2);

	pthread_join(tid1, NULL);
	printf("Join first thread[%ld]\n", tid1);

	pthread_join(tid2, NULL);
	printf("Join first thread[%ld]\n", tid2);

	if (counter.count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERROR ! Total count is %u%s\n", RED, counter.count, NC);
	else
		printf("%sMain: OK. Total count is %u%s\n", GREEN, counter.count, NC);

	pthread_mutex_destroy(&counter.count_mutex);

	return (0);
}


static void *thread_routine(void *data)
{
	pthread_t tid;
	t_counter *count;
	unsigned int i = 0;

	tid = pthread_self();
	count = (t_counter *)data;

	pthread_mutex_lock(&count->count_mutex);

	// Print the count before this thread starts iterating:
	printf("%sThread [%ld]: Count at thread start = %ls.%s\n",
		YELLOW, tid, &count->count, NC);

	pthread_mutex_unlock(&count->count_mutex);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
		pthread_mutex_lock(&count->count_mutex);
		count->count++;
		pthread_mutex_unlock(&count->count_mutex);
		i++;
	}
	pthread_mutex_lock(&count->count_mutex);
	printf("%sThread [%ld]: Final count = %u.%s\n",
		BYELLOW, tid, count->count, NC);
	pthread_mutex_unlock(&count->count_mutex);
	return (NULL); // Thread ends here.
}
