//
// Created by reaso on 2018/5/22.
//

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int TESTparse();
//Syntactic Analyser
int program();
//program ::={<declaration_list><statement_list>}
int declaration_list();
//<declaration_list> ::= {<declaration_stat}
int declaration_stat();
//<declaration_stat> ::= int ID
int statement_list();
//<statement_list> ::= {<statement>}
int statement();
//<statement> ::= <if_stat> | <while_stat> | <for_stat> | <compound_stat> | <expression_stat>
int if_stat();
//<if_stat> ::= if(<expr>)<statement>[else<statement>]
int while_stat();
//<while_stat> ::= while(<expr>)<statement>
int for_stat();
//<for_stat> ::= for(<expr>, <expr>, <expr>)<statement>
int switch_stat();
//<switch_stat> ::= switch(<expr>){<case_stat>}
int case_stat();
//<case_stat> :: = case<factor>:<expression>
int break_stat();
//<break_stat> ::= break;
int write_stat();
//<write_stat> ::= write<expression>
int read_stat();
//<read_stat> ::= read ID
int compound_stat();
//<compound_stat> ::= {<statement_list>}
int expression_stat();
//<expression_stat> ::=<expression>
int expression();
//<expr> ::= ID = <bool_expr> | <bool_expr>
int bool_expr();
//<bool_expr> ::= <additive_expr> | <additive_expr> (> | < | >= | <= | == | !=)<additive_expr>
int additive_expr();
//<additive_expr> ::= <term>{(+ | -)<term>}
int term();
//<term> ::= <factor>{(* | /)<factor>}
int factor();
//<factor> ::= (<expression>) | ID | NUM

char token[20], token1[40];
extern char Scanout[300];
char Writeout[300];
FILE * fp;
FILE * fout;

//Syntactic Analyser
int TESTparse(){
    int es = 0;
    strcpy(Writeout, Scanout);
    Writeout[5] = '\0';
    strcat(Writeout, "_sa.txt");     //rename
    if((fp = fopen(Scanout,"r")) == NULL){
        printf("\nERROR: FAIL TO OPERN %s \n", Scanout);
        es = 10;
    }
    if((fout = fopen(Writeout, "w")) == NULL){
        printf("\nERROR: FAIL TO CREATE %s \n", Writeout);
        es = 10;
    }

    if(es == 0)
        es = program();
    printf("************* Syntactic Analyse Result *************\n");
    switch(es){
        case 0: printf("\n"); break;
        case 10: printf("\nERROR: FAIL TO OPERN %s\n", Scanout); break;
        case 1: printf("Missing { \n"); break;
        case 2: printf("Missing } \n"); break;
        case 3: printf("Missing Identifier\n"); break;
        case 4: printf("Missing Semicolon\n"); break;
        case 5: printf("Missing (\n"); break;
        case 6: printf("Missing )\n"); break;
        case 7: printf("Missing Operate Number\n"); break;
        case 8: printf("Missing : \n"); break;
    }
    fclose(fp);
    return(es);
}

//program ::={<declaration_list><statement_list>}
int program(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if (strcmp(token, "{")){			//if is "{"
        es = 1;
        return(es);
    }
    /*fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);*/
    es = declaration_list();
    if(es > 0)
        return(es);
    es = statement_list();
    if(es > 0)
        return(es);
    if(strcmp(token, "}")){
        es = 2;
        return(es);
    }
    return(es);
}

//<declaration_list> ::= {<declaration_stat}
int declaration_list(){
    int es, n = 0;
/*    while(strcmp(token, "int") == 0){
        es = declaration_stat();
        if(es > 0)
            return(es);
    }*/
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    do {
        es = declaration_stat();
        if(es > 0)
            return (es);
    }while(strcmp(token, "int") == 0 || strcmp(token, "double") == 0 || strcmp(token, "float") == 0);
    return(es);
}

//<declaration_stat> ::= int ID
int declaration_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);

    if(strcmp(token, "ID"))
        return(es = 3);				//not rest

    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);

    if(strcmp(token, ";"))
        return(es = 4);

    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    return (es);
}

//<statement_list> ::= {<statement>}
int statement_list(){
    int es = 0;
    while(strcmp(token, "}")){
        es = statement();
        if(es > 0)
            return (es);
    }
}

//<statement> ::= <if_stat> | <while_stat> | <for_stat> | <compound_stat> | <expression_stat>
int statement(){
    int es = 0;
    if(es == 0 && strcmp(token, "if") == 0)
        es = if_stat();
    if(es == 0 && strcmp(token, "while") == 0)
        es = while_stat();
    if(es == 0 && strcmp(token, "for") == 0)
        es = for_stat();
    if(es == 0 && strcmp(token, "read") == 0)
        es = read_stat();
    if(es == 0 && strcmp(token, "write") == 0)
        es = write_stat();
    if(es == 0 && strcmp(token, "switch") == 0)
        es = switch_stat();
    if(es == 0 && strcmp(token, "case") == 0)
        es = case_stat();
    if(es == 0 && strcmp(token, "{") == 0)
        es = compound_stat();
    if(es == 0 && strcmp(token, "ID") == 0 || strcmp(token, "NUM") == 0)
        es = expression_stat();
    if(es == 0 && strcmp(token, "break") == 0)
        es = break_stat();
    return (es);
}

//<if_stat> ::= if(<expr>)<statement>[else<statement>]
int if_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, "("))
        return (es = 5);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if (es > 0)
        return (es);
    if(strcmp(token, ")"))
        return (es = 6);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = statement();
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);    //push in one more
    if(es > 0)
        return (es);
    if(strcmp(token, "eles") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);
        es = statement();
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);    //push in one more
        if(es > 0)
            return (es);
    }
    return (es);
}

//<while_stat> ::= while(<expr>)<statement>
int while_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, "("))
        return(es = 5);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if(es > 0)
        return(es);
    if(strcmp(token, ")"))
        return (es = 6);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = statement();
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);    //push in one more
    return (es);
}

//<for_stat> ::= for(<expr>, <expr>, <expr>)<statement>
int for_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, "("))
        return (es = 5);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if(es > 0)
        return (es);
    if(strcmp(token, ";"))
        return (es = 4);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if(es > 0)
        return (es);
    if(strcmp(token, ";"))
        return (es = 4);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if(es > 0)
        return (es);
    if(strcmp(token, ")"))
        return (es = 6);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = statement();
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);    //push in one more
    return (es);
}

//<write_stat> ::= write<expression>
int write_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if(es > 0)
        return (es);
    if(strcmp(token, ";"))
        return (es = 4);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    return (es);
}

//<switch_stat> ::= switch(<expr>){<case_stat>}
int switch_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, "("))
        return(es = 5);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = expression();
    if(es > 0)
        return(es);
    if(strcmp(token, ")"))
        return (es = 6);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if (strcmp(token, "{")){
        es = 1;
        return(es);
    }
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = statement();
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    return (es);
}

//<case_stat> ::= case<factor>:<statement>
int case_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, "NUM")){
        es = 7;
        return (es);
    }
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, ":"))
        return (es = 8);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = statement();
    return (es);
}

int break_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, ";"))
        return (es = 4);
    else
        return (es);
}

//<read_stat> ::= read ID
int read_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, "ID"))
        return(es = 3);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    if(strcmp(token, ";"))
        return (es = 4);
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    return (es);
}

//<compound_stat> ::= {<statement_list>}
int compound_stat(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    fprintf(fout, "%s %s\n", token, token1);
    es = statement_list();
    return(es);
}

//<expression_stat> ::=<expression>
int expression_stat(){
    int es = 0;
    if(strcmp(token, ";") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);
        return(es);
    }
    es = expression();
    if(es > 0)
        return(es);
    if(es == 0 && strcmp(token, ";") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token,token1); // } is here
        return (es);
    }else{
        es = 4;
        return (es);
    }
}

//<expr> ::= ID = <bool_expr> | <bool_expr>
int expression(){
    int es = 0;
    int fileadd;
    char token2[20], token3[40];
    if(strcmp(token, "ID") == 0){
        fileadd = ftell(fp);                //remember file's location
        fscanf(fp, "%s %s\n", &token2, &token3);
        if(strcmp(token2, "=") == 0){
            fprintf(fout, "%s %s\n", token2, token3);
            fscanf(fp, "%s %s\n", &token, &token1);
            fprintf(fout, "%s %s\n", token, token1);
            es = bool_expr();
            if(es > 0)
                return(es);
        }else{
            fseek(fp, fileadd, 0);
            es = bool_expr();
            if(es > 0)
                return(es);
        }
    }
    return (es);
}

/*
 * <bool_expr> ::= <additive_expr> @GT
 * | <additive_expr> > <additive_expr> @LES
 * | <additive_expr> < <additive_expr> @GE
 * | <additive_expr> >= <additive_expr> @GE
 * | <additive_expr> <= <additive_expr> @LE
 * | <additive_expr> == <additive_expr> @EQ
 * | <additive_expr> != <additive_expr> @NOTEQ
 */

//<bool_expr> ::= <additive_expr> | <additive_expr> (> | < | >= | <= | == | !=)<additive_expr>
int bool_expr(){
    int es = 0;
    es = additive_expr();
    if(es > 0)
        return (es);
    if(strcmp(token, ">") == 0 | strcmp(token, ">=") == 0
       | strcmp(token, "<") == 0 | strcmp(token, "<=") == 0
       | strcmp(token, "==") == 0 | strcmp(token, "!=") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);
        es = additive_expr();
        if(es > 0)
            return (es);
    }
    return (es);
}

//<additive_expr> ::= <term>{(+ | -)<term>}
int additive_expr(){
    int es = 0;
    es = term();
    if(es > 0)
        return (es);
    while(strcmp(token, "+") == 0 || strcmp(token, "-") == 0) {
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);
        es = term();
        if (es > 0)
            return (es);
    }
    return (es);
}

//<term> ::= <factor>{(* | /)<factor>}
int term(){
    int es = 0;
    es = factor();
    if(es > 0)
        return (es);
    while(strcmp(token, "*") == 0 || strcmp(token, "/") == 0){
        fscanf(fp, "%s %s\n", &token,&token1);
        fprintf(fout, "%s %s\n", token, token1);
        es = factor();
        if(es > 0)
            return (es);
    }
    return (es);
}

//<factor> ::= (<expression>) | ID | NUM
int factor(){
    int es = 0;
    if(strcmp(token, "(") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);
        es = expression();
        if(es > 0)
            return (es);
        if(strcmp(token, ")"))
            return (es = 6);
        fscanf(fp, "%s %s\n", &token, &token1);
        fprintf(fout, "%s %s\n", token, token1);
    }else{
        if(strcmp(token, "-") == 0){                     //analyse negative number
            fscanf(fp, "%s %s\n", &token, &token1);
            fprintf(fout, "%s %s\n", token, token1);
        }
        if(strcmp(token, "ID") == 0 || strcmp(token, "NUM") == 0){
            fscanf(fp, "%s %s\n", &token, &token1);
            fprintf(fout, "%s %s\n", token, token1);
            return (es);
        }else{
            es = 7;
            return (es);
        }
    }
    return (es);
}