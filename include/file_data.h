#pragma once

#include <stdio.h>

long size_file(FILE* file_read);
char* create_buffer(FILE* file_read);
int n_string(char* commands_buffer, long size_command);