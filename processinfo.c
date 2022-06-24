#include <libproc.h>
#include <stdio.h>
#include <string.h>

void find_pids(const char *name)
{
    pid_t pids[2048];
    int bytes = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
    int n_proc = bytes / sizeof(pids[0]);
    for (int i = 0; i < n_proc; i++) {
        struct proc_bsdinfo proc;
        int st = proc_pidinfo(pids[i], PROC_PIDTBSDINFO, 0,
                             &proc, PROC_PIDTBSDINFO_SIZE);
        if (st == PROC_PIDTBSDINFO_SIZE) {
            if (strcmp(name, proc.pbi_name) == 0) {
                /* Process PID */
                printf("%d [%s] [%s]\n", pids[i], proc.pbi_comm, proc.pbi_name);                
            }
        }       
    }
}


int main()
{
    find_pids("bash");
    return 0;
}
