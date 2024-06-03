#ifndef AG2_LANG_H
    #define AG2_LANG_H

    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <inttypes.h>

    #define LINK_AG2_DOCS "https://github.com/hugo-hamet/superoptimizer/tree/main/ag2-lang/"
    #define SSTR_UNPACK(str) str, strlen(str)

    #define ERR_CMD_UNKNOWN "Instruction does not exist."
    #define ERR_ARG_NOT_NUMBER "Argument is not a number."
    #define ERR_ARG_OVERFLOW "Argument is too big (> int16)."
    #define ERR_ARG_TYPE "Argument does not have the correct typing."

    #define SUCCESS 0
    #define FAILURE 1

    #define REGISTERS_NB 8
    #define MAX_ARGS_NB 2

    #define T_MEM 1
    #define T_VAL 2

enum instructions_code {
    CODE_LOAD   = 0x01,
    CODE_SWAP   = 0x02,
    CODE_CMEM   = 0x03,
    CODE_INC    = 0x04,
    CODE_XOR    = 0x05,
    INSTRUCTIONS_NB = 5
};

typedef struct program_s {
    FILE *fp;
    char *line;
    uint8_t registers[REGISTERS_NB];
} program_t;

typedef struct instruction_s {
    char hexcode;
    char *mnemonic;
    int (*func)(program_t *program, uint8_t *values);
    int nb_args;
    uint8_t arg_types[MAX_ARGS_NB];
} instrution_t;

/*   EXECUTION   */
int execute(char *filename);

/*   UTILITIES   */
int agperror(char *errmsg);

/*   INSTRUCTIONS   */
int cmd_load(program_t *program, uint8_t *values);
int cmd_swap(program_t *program, uint8_t *values);
int cmd_cmem(program_t *program, uint8_t *values);
int cmd_inc(program_t *program, uint8_t *values);
int cmd_xor(program_t *program, uint8_t *values);

#endif
