#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# define START 1
# define END 2

# include "../libft/libft.h"
# include "../ft_printf/includes/header_pf.h"
#include <stdbool.h>
#include <stdio.h>      //remove
// #include "mlx.h"		//if visualisation is present

struct s_lem1;

typedef struct		s_links
{
	int				weight;
	int				flag;
	int 			ant_number;
	struct s_links	*next;
	struct s_links	*prev;
	struct s_lem1	*connection_room;
}					t_links;

// each struct contains one path, path length and link to the first room from the start which defines the beginning of the path
// next and prev are links to other paths within the same solution
typedef struct			s_sol_links
{
	int 				length;
	int					ants_to_pass;
	t_links				*links;
	t_links				*links_end;
	struct s_sol_links	*prev;
	struct s_sol_links	*next;
}						t_sol_links;

// main structure with links to several solutions. Each solution can contain several paths
// moves is calculated as number of moves, needed for this solution to put through all ants
typedef struct		s_solution
{
	int					moves;
	t_sol_links			*sol_links;
	struct s_solution	*prev;
	struct s_solution	*next;
}					t_solution;

// gtapioca's structure
typedef struct		s_parents
{
	// struct s_parents *next;
	struct s_parents *prev;
	struct s_lem1	*vertex;
}					t_parents;

typedef struct		s_lem1
{
	int				flag;
	char			*room_name;
	int 			position[2];
	int 			room_type;
	struct s_lem1	*next;
	struct s_lem1	*prev;
	struct s_links	*links;
	t_parents		*parents;
	t_parents		*current;
}					t_lem1;

typedef struct	s_vis
{
	int 		offset_x;
	int 		offset_y;
	int 		zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*address;
	int 		bits_per_pixel;
	int 		size_line;
	int 		endian;
}				t_vis;

typedef struct	s_lem0
{
	int 		ants;
	int 		tmp_info;
	int         visualization;
	t_vis		*vis;
	t_lem1 		*start;
	t_lem1 		*end;
	t_lem1		*lem1[10];
	t_list		*head_print;
	t_list		*print;
	t_solution	*solution;
}				t_lem0;

// gtapioca's structures

typedef struct s_queue
{
	bool	state;
	t_lem1	*vertex;
	struct s_queue	*next;
}				t_queue;

typedef struct s_way
{
	t_lem1	*vertex;
	struct s_way *next;
}				t_way;

typedef struct s_way_holder
{
	t_way				*way;
	struct s_way_holder *next;
}				t_way_holder;

// end of gtapioca's structures

int		atoi_lem(char *str, t_lem0 *st0);
char	**split(char *line, char c);
void	error_management(t_lem0 *st, char *str);
int		get_next_line(int fd, char **line);
void	calc_length(t_lem0 *lem0);

// gtapioca's functions
void		breadth_first_search(t_lem0 *st0);
void		breadth_first_search_2(t_lem0 *st0);
// void	shortest_ways_free(t_lem0 *st0);
void		bfs_expand(t_lem0 *st0);
t_links 	*is_vertex_has_negative_links(t_lem1 *current_vertex, t_queue *buff_queue);
t_sol_links *bfs_collision_modifier(t_lem0 *st0);
void		bfs_expand(t_lem0 *st0);
void		b_f_s(t_lem1 *current_vertex,
t_lem0 *st0, t_queue *buff_queue, int *j);
bool		b_f_s_2(t_lem0 *st0, t_queue *buff_queue, int *j);
bool		bfs_mdf(t_lem1 *current_vertex, t_lem0 *st0,
t_queue *buff_queue, bool criterion);
void		breadth_first_search_2(t_lem0 *st0);
t_sol_links *bfs_collision_modifier(t_lem0 *st0);
t_sol_links *bfs_collision_modifier_2(t_lem1 *current_vertex, t_queue *queue,
t_lem0 *st0, t_queue *buff_queue);
void 		way_keeper_reverse(t_sol_links  **way_keeper);
void		ways_creator_2(t_lem1 *current_vertex, t_lem0 *st0,
t_sol_links **way_keeper);
int			one_way_creator(t_links *begin_way, t_parents *parent,
t_links **way2, t_lem0 *st0);
t_sol_links *bfs_collision_modifier(t_lem0 *st0);
void		weight_zeroing_helper(t_lem1 *buff);
void		weight_zeroing(t_lem0 *st0);
void		delete_flags(t_lem0 *st0);
void		ways_weight_modifier(t_lem0 *st0);
void		ways_array_creator(t_sol_links **way_keeper,
int length, t_links *way2);
void		bfs_expand_helper_queue_maker(t_queue **queue,
t_lem1 **current_vertex, t_lem0 *st0);
void		bfs_expand_helper(t_queue **queue,
t_queue **buff_queue, t_lem1 **current_vertex, t_lem0 *st0);
bool		breadth_first_search_cycle_finder_1(t_queue **queue,
t_queue **buff_queue, t_lem1 **current_vertex, t_lem0 *st0);
void		link_deleter_helper(t_links *link, t_lem1 *buff);
void		link_deleter(t_links *link_1, t_links *link_2,
t_lem1 *buff_1, t_lem1 *buff_2);
bool		breadth_first_search_cycle_finder_2(t_queue **queue,
t_queue **buff_queue, t_lem1 **current_vertex, t_lem0 *st0);
bool		negative_link_checker(t_lem1 *current_vertex, t_links *link);
t_links		*is_vertex_has_negative_links(t_lem1 *current_vertex, t_queue *buff_queue);
bool		destroyed_link_checker(t_lem1 *current_vertex);
void		parents_deleter_current_vertex(t_lem1 *current_vertex);
void		bfs_cycle_finder_helper(t_lem1 **current_vertex,
t_queue **queue, t_lem0 *st0);
bool		destroyed_links_finder(t_links *direct_link,
t_lem1 *current_vertex);
bool    	ways_destroyer(t_lem1 *current_vertex);
bool		parents_contain_way(t_queue *buff_queue);
bool		negative_weigth_finder(t_parents *begin_way, t_parents *way2);
void		current_vertex_and_queue_initializer(t_lem1 **current_vertex,
t_queue **queue, t_queue **buff_queue, t_lem0 *st0);
void		parents_deleter(t_lem0 *st0);
void		queue_deleter(t_queue *queue);
int			length_counter(t_links **way2, t_links *begin_way,
t_parents *parent, t_lem0 *st0);
int			ways_creator_helper(t_lem1 *current_vertex,
t_links **way2, t_lem0 *st0);
void		ways_weight_modifier_1(t_sol_links *way_keeper,
t_lem0 *st0);
void breadth_first_search_cycle_finder(t_queue **queue,
t_queue **buff_queue, t_lem1 **current_vertex, t_lem0 *st0);
void    	ways_creator(t_lem1 *current_vertex, t_lem0 *st0,
int *i, t_sol_links **way_keeper);
void		queue_creator(t_lem1 **current_vertex,
t_queue **queue, t_links **buff_links, bool state);
void		memory_deleter_1(t_lem0 *st0);
void		ways_deleter(t_solution *solution);
void		rooms_deleter(t_lem0 *st0);
// end of gtapioca's functions

#endif
