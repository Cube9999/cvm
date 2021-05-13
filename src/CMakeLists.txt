cmake_minimum_required(VERSION 3.10)

project(cvm)

# Set the standard to C99, Yes this is bad practice but no one's gonna use something that isn't gcc anyway
set(CMAKE_C_FLAGS "-std=c99")

add_executable(cvm main.c instruction.h opcodes.h stack.h vm.c vm.h vmstatus.h stack.c 
			   bytecode.h bytecode.c)