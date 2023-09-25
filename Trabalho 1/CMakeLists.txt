cmake_minimum_required(VERSION 3.25)
project(TrabalhoEDII C)

set(CMAKE_C_STANDARD 11)

add_executable(TrabalhoEDII main.c arvore/rubro-negra.c filmes.c)

# Define o diretório de trabalho para a pasta do projeto
set(WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
set_target_properties(TrabalhoEDII PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${WORKING_DIRECTORY}")
