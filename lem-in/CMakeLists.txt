cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

add_executable(lem_in src/main.c includes/lem_in.h src/lem_atoi.c src/lem_split.c src/move_ants_1.c src/lem_in_bfs_expand.c src/lem_in_bfs.c)

target_link_libraries(lem_in /Users/gtristan/CLionProjects/libft/libft.a)
target_link_libraries(lem_in /Users/gtristan/CLionProjects/ft_printf/libftprintf.a)