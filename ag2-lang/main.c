#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1
#define LINK_AG2_DOCS "https://github.com/hugo-hamet/superoptimizer/tree/main/ag2-lang/"

int help(char *cmd)
{
    printf(
        "Usage: %s file\n"
        "Compiles an AG2 file (.at) in the current directory.\n\n"
        "Find documentation in the \e]8;;%s\e\\AG2-lang repository\e]8;;\e\\.\n",
        cmd, LINK_AG2_DOCS
    );
    return SUCCESS;
}

int main(int ac, char *argv[])
{
    if (ac != 2)
        return FAILURE;
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        return help(*argv);
    if (!strcmp(&argv[1][strlen(argv[1]) - 3], ".at"))
        return SUCCESS;
    return FAILURE;
}
