/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 05:36:30 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/26 11:58:26 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <pthread.h>
# include "core/core.h"

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
