#include "../includes/lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void current_vertex_and_queue_initializer(t_lem1 **current_vertex,
    t_queue **queue, t_queue **buff_queue, t_lem0 *st0)
{
    (*current_vertex) = st0->start;
    (*queue) = (t_queue *)ft_memalloc(sizeof(t_queue));
    (*queue)->vertex = (*current_vertex);
    (*buff_queue) = (*queue);
    (*queue)->next = NULL;
    (*current_vertex)->current = (t_parents *)ft_memalloc(sizeof(t_parents));
    (*current_vertex)->current->prev = NULL;
    (*current_vertex)->current->vertex = (*current_vertex);
    (*current_vertex)->parents = NULL;
}

// bool parents_contain_way(t_queue *buff_queue)
// {
//     t_parents *parent;

//     parent = 0;
//     while (buff_queue)
//     {
//         parent = buff_queue->vertex->parents;
//         while (parent)
//         {
//             if (parent->vertex->flag == 1)
//                 return (true);
//             parent = parent->prev;
//         }
//         buff_queue = buff_queue->next;
//     }
//     return (false);
// }

void parents_deleter(t_lem0 *st0)
{
    t_lem1 *buff_lem;
    int i;

    i = 0;
    while (i < 10)
    {
        buff_lem = (st0->lem1)[i];
        while(buff_lem)
        {
            free(buff_lem->current);
            buff_lem->current = NULL;
            buff_lem->parents = NULL;
            buff_lem = buff_lem->prev;
        }
        i++;
    }
}

void queue_deleter(t_queue *queue)
{
    t_queue *buff_queue;

    while (queue)
    {
        buff_queue = queue;
        queue = queue->next;
        free(buff_queue);
    }
}

void    ways_creator(t_lem1 *current_vertex, t_lem0 *st0,
        int *i, t_queue *buff_queue, t_sol_links **way_keeper)
{
    t_parents *parent;
    t_links     *begin_way;
    t_links     *way2;
    t_links     *buff_links;
    bool        criterion;
    int         length;

    length = 0;
    parent = current_vertex->current;
    begin_way = (t_links *)ft_memalloc(sizeof(t_links));
    begin_way->connection_room = parent->vertex;
    begin_way->next = 0;
    begin_way->prev = 0;
    parent = parent->prev;
    while (parent)
    {
        // if (parent->vertex != st0->start)
        // {
            way2 = (t_links *)ft_memalloc(sizeof(t_links));
            way2->connection_room = parent->vertex;
            // buff_links = way2->connection_room->links;
            // while(buff_links->connection_room != begin_way->connection_room)
            //     buff_links = buff_links->prev;
            // buff_links->weight = -1;
            if (parent->vertex != st0->end
                && parent->vertex != st0->start)
                way2->connection_room->flag = 1;
            way2->next = begin_way;
            begin_way->prev = way2;
            begin_way = way2;
            way2->prev = 0;
        // }
        parent = parent->prev;
        length += 1;
    }
    if (*i == 0)
    {
        (*way_keeper)->links = way2;
        (*way_keeper)->next = 0;
        (*way_keeper)->prev = 0;
        (*way_keeper)->length = length;
    }
    else
    {
        (*way_keeper)->next = (t_sol_links *)ft_memalloc(sizeof(t_sol_links));
        (*way_keeper)->next->links = way2;
        (*way_keeper)->next->prev = (*way_keeper);
        (*way_keeper) = (*way_keeper)->next;
        (*way_keeper)->length = length;
        (*way_keeper)->next = 0;
    }
}

void queue_creator(t_lem1 **current_vertex, t_queue **queue, t_links **buff_links, bool state)
{
    (*queue)->next = (t_queue *)ft_memalloc(sizeof(t_queue));
    (*queue)->next->vertex = (*buff_links)->connection_room;
    (*queue)->next->state = state;
    (*queue)->next->vertex->current = (t_parents *)ft_memalloc(sizeof(t_parents));
    (*queue)->next->vertex->current->prev = (*current_vertex)->current;
    (*queue)->next->vertex->current->vertex = (*queue)->next->vertex;
    (*queue)->next->vertex->parents = (*current_vertex)->current;
    (*queue) = (*queue)->next;
    (*queue)->next = NULL;
}

void breadth_first_search_cycle_finder(t_queue **queue,
    t_queue **buff_queue, t_lem1 **current_vertex, t_lem0 *st0)
{
    t_queue *deleter_queue;
    t_links *buff_links;
    int i;

    i = 0;
    while(*current_vertex != st0->end &&
        *buff_queue != 0 && *current_vertex != NULL)
    {
        deleter_queue = *buff_queue;
        buff_links = (*current_vertex)->links;
        while (buff_links != 0)
        {
            if (buff_links->connection_room->flag == 0 && buff_links->weight != -1)
            {
                if (buff_links->connection_room->parents == 0 &&
                    buff_links->connection_room != st0->start)
                {
                    queue_creator(current_vertex, queue, &buff_links, false);
                    // (*queue)->next = (t_queue *)malloc(sizeof(t_queue));
                    // (*queue)->next->vertex = buff_links->connection_room;
                    // (*queue)->next->vertex->current = (t_parents *)malloc(sizeof(t_parents));
                    // (*queue)->next->vertex->current->prev = (*current_vertex)->current;
                    // (*queue)->next->vertex->current->vertex = (*queue)->next->vertex;
                    // (*queue)->next->vertex->parents = (*current_vertex)->current;
                    // (*queue) = (*queue)->next;
                    // (*queue)->next = NULL;
                    // i++;
                }
            }
            buff_links = buff_links->prev;
        }
        // if (i == 1)
        //     (*current_vertex) = NULL;
        if (*buff_queue)
            *buff_queue = (*buff_queue)->next;
        if (*buff_queue)
            (*current_vertex) = (*buff_queue)->vertex;
        free(deleter_queue);
    }
}

void ways_weight_modifier_1(t_sol_links *way_keeper, t_lem0 *st0)
{
    t_links *buff_link;
    t_links *buff_link_2;
    t_sol_links *buff_sol;
    int k;

    k = 0;
    buff_sol = way_keeper;
    while (buff_sol)
    {
        buff_link = buff_sol->links;
        while (buff_link && buff_link->connection_room != st0->end)
        {
            buff_link_2 = buff_link->connection_room->links;
            while (buff_link_2)
            {
                if (buff_link_2->connection_room == buff_link->next->connection_room)
                {
                    buff_link_2->weight = -1;
                    k++;
                }
                buff_link_2 = buff_link_2->prev;
            }
            buff_link = buff_link->next;
        }
        buff_sol = buff_sol->next;
    }
    // buff_link = st0->start->links;
    // while (buff_link && buff_link->connection_room != st0->solution->sol_links->links->connection_room)
    //     buff_link = buff_link->prev;
    // if (buff_link != 0)
    //     buff_link->weight = -1;
    // printf("%d\n", k);
}

void breadth_first_search(t_lem0 *st0)
{
    t_lem1 *current_vertex;
    t_queue *queue;
    t_queue *buff_queue;
    t_solution  *solution;
    // t_queue *deleter_queue;
    // t_parents *parent;
    // t_way     *begin_way;
    // t_way     *way2;
    // t_way     *way3;
    t_sol_links  *way_keeper;
    t_sol_links  *buff_keeper;
    int       i;
    int       j;
    bool      criterion;

    criterion = true;
    i = 0;
    j = 0;
    way_keeper = (t_sol_links *)ft_memalloc(sizeof(t_sol_links));
    way_keeper->next = 0;
    buff_keeper = way_keeper;
    while (criterion)
    {
        current_vertex_and_queue_initializer(&current_vertex, &queue, &buff_queue, st0);
        breadth_first_search_cycle_finder(&queue, &buff_queue, &current_vertex, st0);
        if (current_vertex == st0->end)
            ways_creator(current_vertex, st0, &i, buff_queue, &way_keeper);
        if (current_vertex != st0->end)
            criterion = false;
        i = 1;
        parents_deleter(st0);
        if (criterion)
            ways_weight_modifier_1(way_keeper, st0);
        if (j == 0 && criterion == false)
        {
            free(way_keeper);
            error_management(st0, "no way\n");
        }
        j++;  
    }
    st0->solution = (t_solution *)ft_memalloc(sizeof(t_solution));
    st0->solution->next = 0;
    st0->solution->prev = 0;
    st0->solution->sol_links = buff_keeper;
    t_links *help;
    int c;
    c = 0;
    while (buff_keeper)
    {
        help = buff_keeper->links;
        while(help)
        {
            printf("%s ", help->connection_room->room_name);
            if (help->connection_room != st0->end)
                c++;
            help = help->next;
        }
        printf("\n");
        buff_keeper = buff_keeper->next;
    }
    printf("\n");
    // printf("%d\n", c);
    bfs_expand(st0);
    // // shortest_ways_free(st0);
    // calc_length(st0);
    // printf("\n");
}