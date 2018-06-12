//
// Created by 高建 on 2018/4/13.
//

#include "compilint_02.h"

char Scanin[300], Scanout[300];

FILE *fin , *fout;

int G_main(){
    int es = 0;
//    printf("input your out file name :\n");
//    scanf("%s", &Scanout);

    es = TESTparse();
    if(es == 0)
        printf("Grammatical Analysis Success!");
    else
        printf("Grammatical Analysis Error!");


    return 0;
}