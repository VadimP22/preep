typedef struct RunConfig {
    const char* target_dir;
    const char* target_string;
} RunConfig;

RunConfig* run_config_create_from_command_line_args(int, const char**);
void run_config_print(RunConfig*);