cmake_minimum_required(VERSION 3.25)
project(TRABALHO C)

set(CMAKE_C_STANDARD 11)
include_directories(.)
include_directories(arvore_bm arvore_rn)

add_executable(TRABALHO main.c filmes.c arvore_bm/arvore_bm.c arvore_avl/avl.c)