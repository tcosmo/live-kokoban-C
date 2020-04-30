/* Responsible for loading a set of Worlds in memory from a file. */

#ifndef DEF_LEVELS_FILE_H
#define DEF_LEVELS_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "global.h"
#include "world.h"

World* load_worlds_from_file(const char* file_path, int* nb_worlds);

#endif