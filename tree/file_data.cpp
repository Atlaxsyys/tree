#include <assert.h>
#include <stdlib.h>

#include "file_data.h"

long size_commands(FILE* file_read)
{
    assert(file_read);

    fseek(file_read, 0, SEEK_END);
    long size_file = ftell(file_read);
    fseek(file_read, 0, SEEK_SET);

    return size_file;
}

char* create_buffer(FILE* file_read)
{
    assert(file_read);

    long size_file = size_commands(file_read);

    char* commands_buffer = (char*) calloc((size_t) size_file + 1, sizeof(char));

    fread(commands_buffer, sizeof(char), (size_t) size_file + 1, file_read);
    rewind(file_read);

    return commands_buffer;
}

int n_string(char* commands_buffer, long size_command)
{
    assert(commands_buffer);

    int counter_string = 0;

    for (int i = 0; i < size_command; i++)
    {
        if (commands_buffer[i] == '\n')
        {
            counter_string++;
        }
    }

    return counter_string + 1;
}