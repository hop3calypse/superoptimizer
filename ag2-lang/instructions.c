#include "ag2lang.h"

int cmd_load(program_t *program, uint8_t *values)
{
    program->registers[0] = values[0];
    return SUCCESS;
}

int cmd_swap(program_t *program, uint8_t *values)
{
    uint8_t tmp = program->registers[values[0]];

    program->registers[values[0]] = program->registers[values[1]];
    program->registers[values[1]] = tmp;
    return SUCCESS;
}

int cmd_cmem(program_t *program, uint8_t *values)
{
    uint8_t nb = 0;

    for (uint8_t i = 0; i < REGISTERS_NB; i++)
        if (program->registers[i] == 0)
            nb++;
    program->registers[values[0]] = nb;
    return SUCCESS;
}

int cmd_inc(program_t *program, uint8_t *values)
{
    if (program->registers[values[0]] < UINT8_MAX) {
        program->registers[values[0]] += 1;
        return SUCCESS;
    }
    return FAILURE;
}

int cmd_xor(program_t *program, uint8_t *values)
{
    program->registers[values[0]] =
        program->registers[values[0]] ^ program->registers[values[1]];
    return SUCCESS;
}
