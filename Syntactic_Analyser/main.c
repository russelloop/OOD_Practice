#include <stdio.h>
#include <ctype.h>
extern int TESTscan();
extern int TESTparse();
char Scanin[300], Scanout[300];
FILE * fin, * fout;

int main() {
    int es = 0;
    es = TESTscan();
    if(es > 0)
        printf("ERROR: LEXICAL ANALYSE HAS FAILED.");
    else
        printf("LEXICAL ANALYSE SUCCESSFULLY.\n");
    if(es == 0){
        es = TESTparse();
        if(es == 0)
            printf("SYNTACTIC ANALYSE SUCCESSFULLY.\n");
        else
            printf("ERROR: SYNTACTIC ANALYSE HAS FAILED.");
    }
    return 0;
}