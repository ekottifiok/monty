cmake_minimum_required(VERSION 3.16)
project(monty)

include_directories(.)

add_executable(
    monty
    monty.c
    add_user_input.c
    read_file.c
    remove_whitespace.c
    free_all_info.c
    execute_command.c
    get_builtin_function.c
    string_functions1.c
    string_functions2.c
    builtin_functions1.c
    builtin_functions2.c
    builtin_functions3.c
)