/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 05:36:30 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/23 09:20:28 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>

typedef struct s_Params
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}	t_Params;

typedef struct s_Coder
{
	int				id;
	int				in_action;
	int				compiles_done;
	int				is_burnt_out;
	int				last_compile_time;
	int				last_debug_time;
	int				last_refactor_time;
	pthread_t		thread;
	pthread_mutex_t	*dongle_mutex;
	t_Params		*params;
}	t_Coder;

typedef struct dongle
{
	int				id;
	int				is_available;
	pthread_mutex_t	mutex;
}	t_Dongle;

typedef struct s_world
{
	t_Params		params;
	t_Coder			*coders;
	t_Dongle		*dongles;
	pthread_mutex_t	print_mutex;
}	t_World;
#endif
