#include "ag2lang.h"

const
instrution_t INSTRUCTIONS[INSTRUCTIONS_NB] = {
    { CODE_LOAD,    "LOAD", &cmd_load,  1,  { T_VAL } },
    { CODE_SWAP,    "SWAP", &cmd_swap,  2,  { T_MEM, T_MEM } },
    { CODE_CMEM,    "CMEM", &cmd_cmem,  1,  { T_MEM } },
    { CODE_INC,     "INC",  &cmd_inc,   1,  { T_MEM } },
    { CODE_XOR,     "XOR",  &cmd_xor,   2,  { T_MEM, T_MEM } }
};

static
program_t *init_program(char *filename)
{
    program_t *program = malloc(sizeof(program_t));

    if (program == NULL)
        return NULL;
    program->fp = fopen(filename, "r");
    if (program->fp == NULL)
        return free(program), NULL;
    for (uint8_t i = 0; i < REGISTERS_NB; i++)
        program->registers[i] = 0;
    return program;
}

static
void dump(program_t *program)
{
    printf(
        "[ %u, %u, %u, %u, %u, %u, %u, %u ]\n",
        program->registers[0], program->registers[1],
        program->registers[2], program->registers[3],
        program->registers[4], program->registers[5],
        program->registers[6], program->registers[7]
    );
}

static
int get_uchar(char *line, uint8_t *args, uint8_t argindex)
{
    uint8_t value = 0;

    for (; *line && *line != ' ' && *line != '\n'; line++) {
        if (!isdigit(*line) || (value * 10) + *line - '0' > UINT8_MAX)
            return FAILURE;
        value = (value * 10) + *line - '0';
    }
    args[argindex] = value;
    return SUCCESS;
}

void parse_line(char *line, int *index, uint8_t *args)
{
    for (int i = 0; i < INSTRUCTIONS_NB; i++)
        if (strncmp(line, SSTR_UNPACK(INSTRUCTIONS[i].mnemonic)) == SUCCESS)
            *index = i;
    if (*index == -1)
        return;
    for (uint8_t i = 0; i < INSTRUCTIONS[*index].nb_args; i++) {
        for (; *line && *line != ' '; line++);
        line++;
        if (get_uchar(line, args, i) == FAILURE) {
            *index = -1;
            return;
        }
    }
}

int execute_instructions(program_t *program)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int instruction_index = -1;
    uint8_t *args = calloc(MAX_ARGS_NB, sizeof(uint8_t));

    if (args == NULL)
        return FAILURE;
    while ((read = getline(&line, &len, program->fp)) != -1) {
        parse_line(line, &instruction_index, args);
        if (instruction_index == -1)
            return FAILURE;
        if (INSTRUCTIONS[instruction_index].func(program, args) == FAILURE)
            return FAILURE;
    }
    if (line)
        free(line);
    free(args);
    return SUCCESS;
}

int execute(char *filename)
{
    program_t *program = init_program(filename);
    int status = SUCCESS;

    if (program == NULL)
        return FAILURE;
    status = execute_instructions(program);
    if (status == SUCCESS)
        dump(program);
    fclose(program->fp);
    free(program);
    return status;
}
