#include "run_config.h"

#include "stdio.h"

int main(int argc, const char** argv) {
    RunConfig* run_config = run_config_create_from_command_line_args(argc, argv);
    return 0;
}
