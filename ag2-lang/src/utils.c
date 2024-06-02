#include "ag2lang.h"

int agperror(char *errmsg)
{
    printf("ag2: error: %s\n", errmsg);
    return FAILURE;
}
