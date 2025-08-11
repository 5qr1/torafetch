// this project only includes support for the OpenBSD operating system
// the reason for this is because this project was intended as "an introductory to C" than something i want to spend more than a day on
// which would have been the case if i continued with the plan of supporting every linux distro and bsd variant with colored logos

// this will probably change in the future, but i have no desire to "finish" this project as of now
 
#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

const char *hostname() {
    static char hostname[255];
    gethostname(hostname, sizeof(hostname));
    return hostname;
}

const char *getDesktop() {
    char *wm = getenv("XDG_CURRENT_DESKTOP"); 
    if(wm == NULL) return "unkown";
    return wm;
}

const char *getShell() {
    char *shell = getenv("SHELL");
    if(shell == NULL) return "unkown";
    return shell;
}

const char *getTerm() {
    char *term = getenv("TERM");
    if(term == NULL) return "unkown";
    return term; // im starting to see a pattern here....
}

int main() {
    struct utsname uts;
    uname(&uts);
    printf("\033[33m      _____     \033[0m %s@%s\n",  getlogin(), hostname());
    printf("\033[33m    \\-     -/\033[0m  \033[33m  os    \033[0m%s\n", uts.sysname);
    printf("\033[33m \\_/         \\\033[0m  \033[33m sh    \033[0m%s\n", getShell());
    printf("\033[33m |        \033[36m0\033[33m \033[36m0\033[33m |\033[0m  \033[33mwm  \033[0m  %s\n", getDesktop());
    printf("\033[33m |_  <   )  3 )\033[0m  \033[33mterm  \033[0m%s\n", getTerm());
    printf("\033[33m / \\         /\033[0m\n");
    printf("\033[33m    /-_____-\\\n \033[0m");
}