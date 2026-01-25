#include "run_config.h"

#include "stdio.h"
#include "stdlib.h"

RunConfig* run_config_create_from_command_line_args(int argc, const char** argv) {
    RunConfig* new_run_config = malloc(sizeof(RunConfig));

    switch (argc)
    {
    case 2:
        /* code */
        break;
    
    default:
        printf("Use -h to print help");
        exit(1);
    }
    
    return new_run_config;
}

void run_config_print(RunConfig* rc) {
    printf("RunConfig:");
    printf("    target_dir: %s", rc->target_dir);
    printf("    target_string: %s", rc->target_string);
}