cmake_minimum_required(VERSION 3.7.2)
project(sql)
add_subdirectory(sqlite)
add_subdirectory(mysql)
add_subdirectory(memcached)
add_subdirectory(redis)
add_subdirectory(mongodb)