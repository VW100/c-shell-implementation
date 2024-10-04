#include "headers.h"
#include "log.h"
#include "commands.h"

char prev_dir[MAX_COMMAND_LENGTH] = "";
char home_dir[MAX_COMMAND_LENGTH] = "";
char hostname[MAX_COMMAND_LENGTH] = "";
char prev_dir_1[MAX_COMMAND_LENGTH]="";
char user[1000];

int main() {
     char command[MAX_COMMAND_LENGTH];
     char *commands[1000];
    char log[MAX_LOG_SIZE][MAX_COMMAND_LENGTH];
    int log_count = 0;

    // Set the current directory as the home directory
    if (getcwd(home_dir, sizeof(home_dir)) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    strcpy(prev_dir,home_dir);
    strcpy(prev_dir_1,home_dir);
    // Get the system's hostname
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }
    struct passwd *pw = getpwuid(getuid());
    strcpy(user, pw->pw_name);
    // Initialize the shell and load previous logs
    load_log(log, &log_count);

    while (1) { int num_commands = 0;
        shell_prompt();
        // Read the command from the user
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }
        command[strcspn(command, "\n")] = '\0';
        //  printf("Initial command: %s\n", command);
        char *cmd = strtok(command, ";");
         while (cmd != NULL && num_commands < 1000) {
        // Create and copy the current command to new_command
        char *new_command = malloc(strlen(cmd) + 1);
        if (new_command == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(new_command, cmd);

        // Trim whitespace from new_command
        trim_whitespace(new_command);

        // Store the trimmed command in the commands array
        commands[num_commands++] = new_command;

        // Get the next command
        cmd = strtok(NULL, ";");
    }
        // while (cmd != NULL) {
        //     // Trim whitespace and execute the command
        //     char trimmed_cmd[MAX_COMMAND_LENGTH];
        //     strncpy(trimmed_cmd, cmd, MAX_COMMAND_LENGTH - 1);
        //     trimmed_cmd[MAX_COMMAND_LENGTH - 1] = '\0';
        //     trim_whitespace(trimmed_cmd);
        //     execute_command(trimmed_cmd, log, &log_count);

        //     cmd = strtok(NULL, ";");
        // }
        //  printf("%d\n",num_commands);
    // Iterate through the commands array and execute each command
    for (int i = 0; i < num_commands; i++) {
        // printf("Processing command: '%s'\n", commands[i]);
        execute_command(commands[i],log,&log_count);

        // Free the allocated memory for the command
        free(commands[i]);
    }
       
    }

    return 0;
}
// Update 2024-08-22
// Update 2024-08-23
// Update 2024-08-24
// Update 2024-08-25
// Update 2024-08-26
// Update 2024-08-27
// Update 2024-08-28
// Update 2024-08-29
// Update 2024-08-30
// Update 2024-08-31
// Update 2024-09-01
// Update 2024-09-02
// Update 2024-09-03
// Update 2024-09-04
// Update 2024-09-05
// Update 2024-09-06
// Update 2024-09-07
// Update 2024-09-08
// Update 2024-09-09
// Update 2024-09-10
// Update 2024-09-11
// Update 2024-09-12
// Update 2024-09-13
// Update 2024-09-14
// Update 2024-09-15
// Update 2024-09-16
// Update 2024-09-17
// Update 2024-09-18
// Update 2024-09-19
// Update 2024-09-20
// Update 2024-09-21
// Update 2024-09-22
// Update 2024-09-23
// Update 2024-09-24
// Update 2024-09-25
// Update 2024-09-26
// Update 2024-09-27
// Update 2024-09-28
// Update 2024-09-29
// Update 2024-09-30
// Update 2024-10-01
// Update 2024-10-02
// Update 2024-10-03
// Update 2024-10-04
// Update 2024-10-05
// Update 2024-10-06
// Update 2024-10-07
// Update 2024-10-08
// Update 2024-10-09
// Update 2024-10-10
// Update 2024-10-11
// Update 2024-10-12
// Update 2024-10-13
// Update 2024-10-14
// Update 2024-10-15
// Update 2024-10-16
// Update 2024-10-17
// Update 2024-10-18
// Update 2024-10-19
// Update 2024-10-20
// Update 2024-08-22: Improving shell implementation
// Update 2024-08-23: Improving shell implementation
// Update 2024-08-24: Improving shell implementation
// Update 2024-08-25: Improving shell implementation
// Update 2024-08-26: Improving shell implementation
// Update 2024-08-27: Improving shell implementation
// Update 2024-08-28: Improving shell implementation
// Update 2024-08-29: Improving shell implementation
// Update 2024-08-30: Improving shell implementation
// Update 2024-08-31: Improving shell implementation
// Update 2024-09-01: Improving shell implementation
// Update 2024-09-02: Improving shell implementation
// Update 2024-09-03: Improving shell implementation
// Update 2024-09-04: Improving shell implementation
// Update 2024-09-05: Improving shell implementation
// Update 2024-09-06: Improving shell implementation
// Update 2024-09-07: Improving shell implementation
// Update 2024-09-08: Improving shell implementation
// Update 2024-09-09: Improving shell implementation
// Update 2024-09-10: Improving shell implementation
// Update 2024-09-11: Improving shell implementation
// Update 2024-09-12: Improving shell implementation
// Update 2024-09-13: Improving shell implementation
// Update 2024-09-14: Improving shell implementation
// Update 2024-09-15: Improving shell implementation
// Update 2024-09-16: Improving shell implementation
// Update 2024-09-17: Improving shell implementation
// Update 2024-09-18: Improving shell implementation
// Update 2024-09-19: Improving shell implementation
// Update 2024-09-20: Improving shell implementation
// Update 2024-09-21: Improving shell implementation
// Update 2024-09-22: Improving shell implementation
// Update 2024-09-23: Improving shell implementation
// Update 2024-09-24: Improving shell implementation
// Update 2024-09-25: Improving shell implementation
// Update 2024-09-26: Improving shell implementation
// Update 2024-09-27: Improving shell implementation
// Update 2024-09-28: Improving shell implementation
// Update 2024-09-29: Improving shell implementation
// Update 2024-09-30: Improving shell implementation
// Update 2024-10-01: Improving shell implementation
// Update 2024-10-02: Improving shell implementation
// Update 2024-10-03: Improving shell implementation
// Update 2024-10-04: Improving shell implementation
// Update 2024-10-05: Improving shell implementation
// Update 2024-10-06: Improving shell implementation
// Update 2024-10-07: Improving shell implementation
// Update 2024-10-08: Improving shell implementation
// Update 2024-10-09: Improving shell implementation
// Update 2024-10-10: Improving shell implementation
// Update 2024-10-11: Improving shell implementation
// Update 2024-10-12: Improving shell implementation
// Update 2024-10-13: Improving shell implementation
// Update 2024-10-14: Improving shell implementation
// Update 2024-10-15: Improving shell implementation
// Update 2024-10-16: Improving shell implementation
// Update 2024-10-17: Improving shell implementation
// Update 2024-10-18: Improving shell implementation
// Update 2024-10-19: Improving shell implementation
// Update 2024-10-20: Improving shell implementation
// Update 2024-08-22: Improving shell implementation
// Update 2024-08-23: Improving shell implementation
// Update 2024-08-24: Improving shell implementation
// Update 2024-08-25: Improving shell implementation
// Update 2024-08-26: Improving shell implementation
// Update 2024-08-27: Improving shell implementation
// Update 2024-08-28: Improving shell implementation
// Update 2024-08-29: Improving shell implementation
// Update 2024-08-30: Improving shell implementation
// Update 2024-08-31: Improving shell implementation
// Update 2024-09-01: Improving shell implementation
// Update 2024-09-02: Improving shell implementation
// Update 2024-09-03: Improving shell implementation
// Update 2024-09-04: Improving shell implementation
// Update 2024-09-05: Improving shell implementation
// Update 2024-09-06: Improving shell implementation
// Update 2024-09-07: Improving shell implementation
// Update 2024-09-08: Improving shell implementation
// Update 2024-09-09: Improving shell implementation
// Update 2024-09-10: Improving shell implementation
// Update 2024-09-11: Improving shell implementation
// Update 2024-09-12: Improving shell implementation
// Update 2024-09-13: Improving shell implementation
// Update 2024-09-14: Improving shell implementation
// Update 2024-09-15: Improving shell implementation
// Update 2024-09-16: Improving shell implementation
// Update 2024-09-17: Improving shell implementation
// Update 2024-09-18: Improving shell implementation
// Update 2024-09-19: Improving shell implementation
// Update 2024-09-20: Improving shell implementation
// Update 2024-09-21: Improving shell implementation
// Update 2024-09-22: Improving shell implementation
// Update 2024-09-23: Improving shell implementation
// Update 2024-09-24: Improving shell implementation
// Update 2024-09-25: Improving shell implementation
// Update 2024-09-26: Improving shell implementation
// Update 2024-09-27: Improving shell implementation
// Update 2024-09-28: Improving shell implementation
// Update 2024-09-29: Improving shell implementation
// Update 2024-09-30: Improving shell implementation
// Update 2024-10-01: Improving shell implementation
// Update 2024-10-02: Improving shell implementation
// Update 2024-10-03: Improving shell implementation
// Update 2024-10-04: Improving shell implementation
// Update 2024-10-05: Improving shell implementation
// Update 2024-10-06: Improving shell implementation
// Update 2024-10-07: Improving shell implementation
// Update 2024-10-08: Improving shell implementation
// Update 2024-10-09: Improving shell implementation
// Update 2024-10-10: Improving shell implementation
// Update 2024-10-11: Improving shell implementation
// Update 2024-10-12: Improving shell implementation
// Update 2024-10-13: Improving shell implementation
// Update 2024-10-14: Improving shell implementation
// Update 2024-10-15: Improving shell implementation
// Update 2024-10-16: Improving shell implementation
// Update 2024-10-17: Improving shell implementation
// Update 2024-10-18: Improving shell implementation
// Update 2024-10-19: Improving shell implementation
// Update 2024-10-20: Improving shell implementation
// Update 2024-08-22: Adding new shell features
// Update 2024-08-23: Adding new shell features
// Update 2024-08-24: Adding new shell features
// Update 2024-08-25: Adding new shell features
// Update 2024-08-26: Adding new shell features
// Update 2024-08-27: Adding new shell features
// Update 2024-08-28: Adding new shell features
// Update 2024-08-29: Adding new shell features
// Update 2024-08-30: Adding new shell features
// Update 2024-08-31: Adding new shell features
// Update 2024-09-01: Adding new shell features
// Update 2024-09-02: Adding new shell features
// Update 2024-09-03: Adding new shell features
// Update 2024-09-04: Adding new shell features
// Update 2024-09-05: Adding new shell features
// Update 2024-09-06: Adding new shell features
// Update 2024-09-07: Adding new shell features
// Update 2024-09-08: Adding new shell features
// Update 2024-09-09: Adding new shell features
// Update 2024-09-10: Adding new shell features
// Update 2024-09-11: Adding new shell features
// Update 2024-09-12: Adding new shell features
// Update 2024-09-13: Adding new shell features
// Update 2024-09-14: Adding new shell features
// Update 2024-09-15: Adding new shell features
// Update 2024-09-16: Adding new shell features
// Update 2024-09-17: Adding new shell features
// Update 2024-09-18: Adding new shell features
// Update 2024-09-19: Adding new shell features
// Update 2024-09-20: Adding new shell features
// Update 2024-09-21: Adding new shell features
// Update 2024-09-22: Adding new shell features
// Update 2024-09-23: Adding new shell features
// Update 2024-09-24: Adding new shell features
// Update 2024-09-25: Adding new shell features
// Update 2024-09-26: Adding new shell features
// Update 2024-09-27: Adding new shell features
// Update 2024-09-28: Adding new shell features
// Update 2024-09-29: Adding new shell features
// Update 2024-09-30: Adding new shell features
// Update 2024-10-01: Adding new shell features
// Update 2024-10-02: Adding new shell features
// Update 2024-10-03: Adding new shell features
// Update 2024-10-04: Adding new shell features
// Update 2024-10-05: Adding new shell features
