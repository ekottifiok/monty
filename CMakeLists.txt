cmake_minimum_required(VERSION 3.16)
project(monty)

include_directories(.)

add_executable(
    monty
    monty.c
    add_user_input.c
    parse_read.c
    read_file.c
    remove_whitespace.c
    free_all_info.c
    execute_command.c
)