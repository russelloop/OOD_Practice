

#include "compiling_01.h"


char Scanin[300], Scanout[300];
FILE * fin, * fout;

int main() {
    int es = 0;
    es = TESTscan();
    if(es > 0)
        printf("error ! ! ! fuck it ! \n");
    else
        printf("success!! fuck it!! \n");
    G_main();

    return 0;
}