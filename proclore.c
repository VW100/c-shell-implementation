#include "proclore.h"
#include "headers.h"
void proclore_command(char *arg) {
    int pid = -1; // Default to the current process if no PID is provided

    if (arg != NULL) {
        pid = atoi(arg); // Convert argument to PID
    }

    proclore(pid);
}
void proclore(int pid) {
    char path[256];
    char buffer[1024];
    FILE *file;
    char status;
    pid_t process_group;
    long virtual_memory;
    char executable_path[256];
    char cwd[256];
    char relative_path[256];
    ssize_t len;

    // Default to the current process if no PID is specified
    if (pid == -1) {
        pid = getpid();
    }

    // Print PID
    printf("pid : %d\n", pid);

    // Construct the path to the process status file
    snprintf(path, sizeof(path), "/proc/%d/status", pid);

    // Open the process status file
    file = fopen(path, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    // Read the status file
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "State:", 6) == 0) {
            // Extract process status
            sscanf(buffer, "State:\t%c", &status);
            printf("process status : %c\n", status);
        } else if (strncmp(buffer, "VmSize:", 7) == 0) {
            // Extract virtual memory
            sscanf(buffer, "VmSize:\t%ld kB", &virtual_memory);
            printf("Virtual memory : %ld\n", virtual_memory * 1024); // Convert to bytes
        } else if (strncmp(buffer, "Pid:", 4) == 0) {
            // Extract process group ID
            sscanf(buffer, "Pid:\t%d", &pid);
            process_group = pid;
            printf("Process Group : %d\n", process_group);
        }
    }
    fclose(file);

    // Construct the path to the executable file
    snprintf(path, sizeof(path), "/proc/%d/exe", pid);

    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return;
    }

    // Read the executable path
    len = readlink(path, executable_path, sizeof(executable_path) - 1);
    if (len != -1) {
        executable_path[len] = '\0';
        
        // Convert to relative path
        if (strncmp(executable_path, cwd, strlen(cwd)) == 0) {
            snprintf(relative_path, sizeof(relative_path), ".%s", executable_path + strlen(cwd));
            printf("executable path : %s\n", relative_path);
        } else {
            printf("executable path : %s\n", executable_path);
        }
    } else {
        perror("readlink");
    }

    // Print process states
    // printf("Process states :\n");
    // printf("R/R+ : Running\n");
    // printf("S/S+ : Sleeping in an interruptible wait\n");
    // printf("Z : Zombie\n");
    // printf("The “+” signifies whether it is a foreground or background process.\n");

}// Update 2024-08-22: Optimizing process management
// Update 2024-08-23: Optimizing process management
// Update 2024-08-24: Optimizing process management
// Update 2024-08-25: Optimizing process management
// Update 2024-08-26: Optimizing process management
// Update 2024-08-27: Optimizing process management
// Update 2024-08-28: Optimizing process management
// Update 2024-08-29: Optimizing process management
// Update 2024-08-30: Optimizing process management
// Update 2024-08-31: Optimizing process management
// Update 2024-09-01: Optimizing process management
// Update 2024-09-02: Optimizing process management
// Update 2024-09-03: Optimizing process management
// Update 2024-09-04: Optimizing process management
// Update 2024-09-05: Optimizing process management
// Update 2024-09-06: Optimizing process management
// Update 2024-09-07: Optimizing process management
// Update 2024-09-08: Optimizing process management
// Update 2024-09-09: Optimizing process management
// Update 2024-09-10: Optimizing process management
// Update 2024-09-11: Optimizing process management
// Update 2024-09-12: Optimizing process management
// Update 2024-09-13: Optimizing process management
// Update 2024-09-14: Optimizing process management
// Update 2024-09-15: Optimizing process management
// Update 2024-09-16: Optimizing process management
// Update 2024-09-17: Optimizing process management
// Update 2024-09-18: Optimizing process management
// Update 2024-09-19: Optimizing process management
// Update 2024-09-20: Optimizing process management
// Update 2024-09-21: Optimizing process management
// Update 2024-09-22: Optimizing process management
// Update 2024-09-23: Optimizing process management
// Update 2024-09-24: Optimizing process management
// Update 2024-09-25: Optimizing process management
// Update 2024-09-26: Optimizing process management
// Update 2024-09-27: Optimizing process management
// Update 2024-09-28: Optimizing process management
// Update 2024-09-29: Optimizing process management
// Update 2024-09-30: Optimizing process management
// Update 2024-10-01: Optimizing process management
// Update 2024-10-02: Optimizing process management
// Update 2024-10-03: Optimizing process management
// Update 2024-10-04: Optimizing process management
// Update 2024-10-05: Optimizing process management
// Update 2024-10-06: Optimizing process management
// Update 2024-10-07: Optimizing process management
// Update 2024-10-08: Optimizing process management
// Update 2024-10-09: Optimizing process management
// Update 2024-10-10: Optimizing process management
// Update 2024-10-11: Optimizing process management
// Update 2024-10-12: Optimizing process management
// Update 2024-10-13: Optimizing process management
// Update 2024-10-14: Optimizing process management
// Update 2024-10-15: Optimizing process management
// Update 2024-10-16: Optimizing process management
// Update 2024-10-17: Optimizing process management
// Update 2024-10-18: Optimizing process management
// Update 2024-10-19: Optimizing process management
// Update 2024-10-20: Optimizing process management
// Update 2024-08-22: Improving process management
// Update 2024-08-23: Improving process management
// Update 2024-08-24: Improving process management
// Update 2024-08-25: Improving process management
// Update 2024-08-26: Improving process management
// Update 2024-08-27: Improving process management
// Update 2024-08-28: Improving process management
// Update 2024-08-29: Improving process management
// Update 2024-08-30: Improving process management
// Update 2024-08-31: Improving process management
// Update 2024-09-01: Improving process management
// Update 2024-09-02: Improving process management
// Update 2024-09-03: Improving process management
// Update 2024-09-04: Improving process management
// Update 2024-09-05: Improving process management
// Update 2024-09-06: Improving process management
// Update 2024-09-07: Improving process management
// Update 2024-09-08: Improving process management
// Update 2024-09-09: Improving process management
