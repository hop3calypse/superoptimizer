#include "ag2lang.h"

static
int help(char *cmd)
{
    printf(
        "Usage: %s file\n"
        "Executes an AG2 file (.at). Does not 'compile' anything: the README lied to you.\n"
        "The compiling version of this binary is a WIP, though.\n\n"
        "Find the documentation on the \e]8;;%s\e\\AG2-lang repository\e]8;;\e\\.\n",
        cmd, LINK_AG2_DOCS
    );
    return SUCCESS;
}

static
void settings(void)
{
    setbuf(stdout, NULL);
}

int main(int ac, char *argv[])
{
    if (ac != 2)
        return FAILURE;
    settings();
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
        return help(*argv);
    if (strlen(argv[1]) > 3 && !strcmp(&argv[1][strlen(argv[1]) - 3], ".at"))
        return execute(argv[1]);
    return FAILURE;
}
