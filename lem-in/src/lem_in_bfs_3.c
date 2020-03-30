/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bfs_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:09:00 by gtristan          #+#    #+#             */
/*   Updated: 2020/03/31 00:02:27 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void	way_keeper_modifier(bool criterion, t_sol_links *way_keeper,
	t_lem0 *st0, int *arr)
	{
	if (criterion)
		ways_weight_modifier_1(way_keeper, st0);
	if (arr[1] == 0 && criterion == false)
	{
		free(way_keeper);
		error_management(st0, "no way\n");
	}
	arr[1]++;
}

t_sol_links *breadth_first_search_helper(t_lem0 *st0, t_sol_links *way_keeper)
{
	t_lem1      *current_vertex;
	t_queue     *queue;
	t_queue     *buff_queue;
	int         arr[2];
	bool        criterion;

	criterion = true;
	arr[0] = 0;
	arr[1] = 0;
	while (criterion)
	{
		current_vertex_and_queue_initializer(&current_vertex, &queue, &buff_queue, st0);
		breadth_first_search_cycle_finder(&queue, &buff_queue, &current_vertex, st0);
		if (current_vertex == st0->end)
			ways_creator(current_vertex, st0, &(arr[0]), &way_keeper);
		if (current_vertex != st0->end)
			criterion = false;
		arr[0] = 1;
		parents_deleter(st0);
		way_keeper_modifier(criterion, way_keeper, st0, arr);
	}
	return (way_keeper);
}

void breadth_first_search(t_lem0 *st0)
{
	t_sol_links  *buff_keeper;

	buff_keeper = (t_sol_links *)ft_memalloc(sizeof(t_sol_links));
	buff_keeper->next = 0;
	breadth_first_search_helper(st0, buff_keeper);
	st0->solution = (t_solution *)ft_memalloc(sizeof(t_solution));
	st0->solution->next = 0;
	st0->solution->prev = 0;
	st0->solution->sol_links = buff_keeper;
	// t_links *help;
	// int c;
	// c = 0;
	// while (buff_keeper)
	// {
	//     help = buff_keeper->links;
	//     while(help)
	//     {
	//         printf("%s ", help->connection_room->room_name);
	//         if (help->connection_room != st0->end)
	//             c++;
	//         help = help->next;
	//     }
	//     printf("\n");
	//     buff_keeper = buff_keeper->next;
	// }
	// printf("\n");
	// printf("%d\n", c);
	bfs_expand(st0);
	calc_length(st0);
}