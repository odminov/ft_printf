cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_CXX_STANDARD 11)

add_executable(ft_printf
        ft_itoa_base.c
        ft_printf.c
        header.h
        main.c
        parse_format.c
        parse_percent.c
        proc_base.c
        proc_int.c
        proc_ptr.c
        proc_str_chars.c
        valid.c)
