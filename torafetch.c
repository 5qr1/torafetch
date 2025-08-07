// linux only

#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *strrev(char *str) { // strrev isnt included in c?
    if (str == NULL) return NULL; // if the string is nothing return NULL
    size_t len = strlen(str); // check the length of string
    if (len == 0) return str; // if its 0 return string (nothing to reverse)
    char *start = str; // first letter
    char *end = str + len - 1; // last letter
    while (start < end) {
        char temp = *start; // saves start
        *start = *end; // makes start end
        *end = temp; // makes end start
        start++; // repeats onto next character
        end--;
    }
    return str;
}

char *getDesktop() {
    char *wm = getenv("XDG_CURRENT_DESKTOP");
    return wm;
}

char *hostname() {
    static char hostname[255]; // static so it stays after the function ends
    gethostname(hostname, sizeof(hostname));
    return hostname;
}

char *getShell() {
    char *shell = getenv("SHELL");
    return shell;
}

char *getTerm() {
    char *term = getenv("TERM");
    return term; // im starting to see a pattern here....
}

char *osRelease() {
    static char buffer[255];
    FILE *pOsReleaseFile = fopen("/etc/os-release", "r"); // pointer to read /etc/os-release, where we can find the name of the distro
    fgets(buffer, 255, pOsReleaseFile); // reads the top line of /etc/os-release
    char *parsedBuffer = buffer + 6;
    char *moreParsedBuffer = strrev(parsedBuffer) + 2;  // this is a bad way of doing things lol
    return strrev(moreParsedBuffer);
    fclose(pOsReleaseFile); // closes the file
}

int main() {
    printf("%s@%s\n", getlogin(), hostname());
    printf("os    %s\n", osRelease());
    printf("wm    %s\n", getDesktop());
    printf("sh    %s\n", getShell());
    printf("term  %s\n", getTerm());
    return 0;
}