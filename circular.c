# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>


typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	t_philo			*next;
	t_philo			*prev;
    t_philo			*philo;
}	t_philo;

void	add_to_list(t_philo *philo, int n)
{
	t_philo	*new_philo;
	t_philo	*first;

    first = philo;
	new_philo = (t_philo *) malloc (sizeof(t_philo));
	new_philo->id = 1;
	while (philo->next != first)
		philo = philo->next;
	philo->next = new_philo;
	new_philo->next = first;
	new_philo->prev = philo;
	first->prev = new_philo;
}

int main(t_philo *philo)
{
    int	n;
	n = 0;
    philo = (t_philo *) malloc (sizeof(t_philo));
	while (++n < 5)
    {
		add_to_list(philo, n);
    }
}