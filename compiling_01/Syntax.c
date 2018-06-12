
#include "compilint_02.h"

/*
 * 语法分析器
 * Switch-case
 * 错误分析处理
 *
 */
char token[20], token1[40]; 		//to save the id and name
extern char Scanout[300];			//the lexical result
char Writeout[300];                //name of output file
FILE *fp, *fout;
char ScansyOut[300];

// 语法分析
//
int TESTparse(){
    int es = 0;
    strcpy(Writeout, Scanout);
    Writeout[3] = '\0';
    strcat(Writeout, "_syn.txt");     //rename
    if ((fp = fopen(Scanout, "r")) == NULL){
        printf("open file error fuck it !!!\n");
        es = 10;
    }
    if((fout = fopen(Writeout, "w")) == NULL){
        printf("open file error fuck it !!!\n");
        es = 10;
    }
    if(es == 0)
        es = program();
    printf("the result of the grammar\n");
    // es to mark the error
    fclose(fp);
    return(es);
}
//program -> <declaration_list><statement_list>
//
int program(){
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    // check first char
    if(strcmp(token, "{")) {
        //出错时跳过一个字符
        fprintf(fout, "ERROR ! -------------missing the '{'\n");
    }else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
    }
    // check the declaration
    es = declaration_list();

    // check the statement
    es = statement_list();

    // check the last char
    if(strcmp(token, "}")){
        es = 2;
        fprintf(fout, "ERROR ! -------------missing the '}'\n");
    }else{
        fprintf(fout, "%s\t%s\n", token, token1);
    }
    return es;
}
//declaration_list -> {declaration_stat}
//
int declaration_list(){
    fprintf(fout, "|-------------declaration_list-------------|\n");
    /*int es = 0;
    while(strcmp(token, "int") == 0){
        es = declaration_stat();
    }
    return es;*/
    int es;
    do {
        es = declaration_stat();
    }while(strcmp(token, "int") == 0 || strcmp(token, "double") == 0 || strcmp(token, "float") == 0);

    return(es);
}
//declaration_stat -> int ID;
//
int declaration_stat(){
    int es = 0;
    // print the int
    fprintf(fout, "%s\t%s\n", token, token1);
    fscanf(fp, "%s %s\n", &token, &token1);
    // if miss id and ;
    if(strcmp(token, "int") == 0){
        fprintf(fout, "ERROR ! -------------missing the object\n");
        return 0;
    }
    // if missing id
    if(strcmp(token, "ID")){
        fprintf(fout, "ERROR ! -------------missing the 'ID'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
    }
    // if missing ;
    if(strcmp(token, ";")){
        if(strcmp(token, "int") == 0 || strcmp(token, "double") == 0 || strcmp(token, "float") == 0){
            fprintf(fout, "ERROR ! -------------missing the ';'\n");
        }
        else{
            fprintf(fout, "ERROR ! -------------undefined character %s\n", token);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
    }else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
    }

    return es;
}
//<statement_list> -> {<statement>}
//
int statement_list(){
    int es = 0;
    while(strcmp(token, "}")){
        es = statement();
    }
    return es;
}
// <statement> -> <if_stat> | <while_stat> | <for_stat> | <compound_stat> | <expression_stat>
//
int statement(){
    int es = 0;
    // you can add what you want in here
        if (es == 0 && strcmp(token, "if") == 0) {
            es = if_stat();
        }
        if (es == 0 && strcmp(token, "while") == 0) {
            es = while_stat();
        }
        if (es == 0 && strcmp(token, "for") == 0) {
            es = for_stat();
        }
        if (es == 0 && strcmp(token, "write") == 0) {
            es = write_stat();
        }
        if (es == 0 && strcmp(token, "read") == 0) {
            es = read_stat();
        }
        if (es == 0 && strcmp(token, "switch") == 0) {
            es = switch_stat();
        }
        if (es == 0 && strcmp(token, "break") == 0) {
            es = break_stat();
        }
        // compound_stat
        if (es == 0 && strcmp(token, "{") == 0) {
            es = compound_stat();
        }
        // expression_stat
        if (es == 0 && strcmp(token, "ID") == 0 || strcmp(token, "NUM") == 0 || strcmp(token, "(") == 0) {
            es = expression_stat();
        }
    return es;
}
//if_stat -> if(<expression>) <statement> [else<statement>]
//
int if_stat(){
    fprintf(fout, "|------------------if_stat-----------------|\n");
    fprintf(fout, "%s\t%s\n", token, token1);
    int es = 0;
    fscanf(fp, "%s %s \n" , &token,&token1);
    //loss the (
    if(strcmp(token, "(")){
        if(strcmp(token, "ID") == 0){
            fprintf(fout, "ERROR ! -------------missing the '('\n");
        }
        else{
            fprintf(fout, "ERROR ! -------------undefined character %s\n", token);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }
    es = expression();
    // loss the )
    if(strcmp(token, ")")){
        if(strcmp(token, "{") == 0){
            fprintf(fout, "ERROR ! -------------missing the ')'\n");
        }
        else{
            fprintf(fout, "ERROR ! -------------undefined character %s\n", token);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }
    es = statement();
    if(strcmp(token, "else") == 0){
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
        es = statement();
    }

    return es;
}
// <while_stat> -> while(<expr>) <statement>
//
int while_stat(){
    fprintf(fout, "|----------------while_stat----------------|\n");
    int es = 0;
    fprintf(fout, "%s\t%s\n", token, token1);
    fscanf(fp, "%s %s \n" , &token,&token1);
    // loss the (
    if(strcmp(token, "(")){
        fprintf(fout, "ERROR ! -------------missing the '('\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    es = expression();

    // loss the )
    if(strcmp(token, ")")){
        fprintf(fout, "ERROR ! -------------missing the ')'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    //fprintf(fout, "%s\t%s\n", token, token1);
    es = statement();
    return es;
}
// <for_stat> -> for(<expression> ; <expression> ; <expression> ) <statement>
//
int for_stat(){
    fprintf(fout, "|-----------------for_stat-----------------|\n");
    int es = 0;
    fprintf(fout, "%s\t%s\n", token, token1);
    fscanf(fp, "%s %s \n" , &token,&token1);

    // loss the (
    if(strcmp(token, "(")){
        fprintf(fout, "ERROR ! -------------missing the '('\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    es = expression();

    // loss the ;
    if(strcmp(token, ";")){
        fprintf(fout, "ERROR ! -------------missing the ';'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    es = expression();
    // loss the ;
    if(strcmp(token, ";")){
        fprintf(fout, "ERROR ! -------------missing the ';'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    es = expression();
    // loss the )
    if(strcmp(token, ")")){
        fprintf(fout, "ERROR ! -------------missing the ')'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    es = statement();

    return es;
}
//<write_stat> -> write <expression>
//
int write_stat(){
    fprintf(fout, "|----------write_stat----------|\n");
    fprintf(fout, "%s\t%s\n", token, token1);
    int es = 0;
    fscanf(fp, "%s %s \n" , &token,&token1);
    es = expression();
    // loss the ;
    if(strcmp(token, ";")){
        fprintf(fout, "ERROR ! -------------missing the ')'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }
    return es;
}
//<read_stat> -> read ID
//
int read_stat(){
    fprintf(fout, "|----------read_stat-----------|\n");
    fprintf(fout, "%s\t%s\n", token, token1);
    int es = 0;
    fscanf(fp, "%s %s \n" , &token,&token1);
    // loss the ID
    if(strcmp(token, "ID")){
        fprintf(fout, "ERROR ! -------------missing the object\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    // loss the ;
    if(strcmp(token , ";")){
        fprintf(fout, "ERROR ! -------------missing the ';'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }
    return es;
}
// <compound_stat> -> {<statement_list>}
//
int compound_stat() {
    fprintf(fout, "%s\t%s\n", token, token1);
    int es = 0;
    fscanf(fp, "%s %s\n", &token, &token1);
    es = statement_list();
    fprintf(fout, "%s\t%s\n", token, token1);
    fscanf(fp, "%s %s \n" , &token,&token1);
    return es;
}
//<expression_stat> -> <expression>; | ;
//
int expression_stat() {
    int es = 0;
    // null
    if(strcmp(token, ";") == 0){
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
        return es;
    }
    // expression
    es = expression();
    // check the ;
    if(es == 0 && strcmp(token, ";") == 0){
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
        return es;
    }
    else {
        // loss the ;
        fprintf(fout, "ERROR ! -------------missing the ';'\n");
    }
}
//<expression>-> ID=<bool_expr> | <bool_expr>
//表达式 -> 标识符 = 布尔表达式 | 布尔表达式
int expression(){
    int es = 0;
    // mark the file location
    int fileadd;
    char token2[20], token3[40];
    //char token4[20], token5[40];
    if (strcmp(token, "ID") == 0){
        // write forward to check =
        fileadd = ftell(fp);
        fscanf(fp, "%s %s\n", &token2, &token3);
        // ok it's a ID = bool
        if(strcmp(token2, "=") == 0 ){
            fprintf(fout, "%s\t%s\n", token, token1);
            fprintf(fout, "%s\t%s\n", token2, token3);
            fscanf(fp, "%s %s\n", &token, &token1);
            //fprintf(fout, "%s\t%s\n", token, token1);
            es = bool_expr();
        }
        // oh it just a bool
        else{
            fseek(fp, fileadd, 0);
            //fprintf(fout, "%s\t%s\n", token, token1);
            es = bool_expr();
            if(es > 0)
                return es;
        }
    }
    else
        es = bool_expr();
    return es;
}
//<bool_expr> -> <additive_expr> | <additive_expr> (> | < | >= | <= | == | !=) <additive_expr>
//
int bool_expr(){
    int es = 0;
    es = additive_expr();
    if( strcmp(token, ">") == 0 || strcmp(token, ">=") == 0 ||
        strcmp(token, "<") == 0 || strcmp(token, "<=") == 0 ||
    strcmp(token, "==") == 0 || strcmp(token, "!=") == 0 )
    {
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
        //fprintf(fout, "%s\t%s\n", token, token1);
        es = additive_expr();
    }
    return es;
}
//<additive_expr> -> <term> {(+ | -) <term>}
//
int additive_expr(){
    int es = 0;
    es = term();
    if (es > 0)
        return es;
    while(strcmp(token, "+") == 0 || strcmp(token, "-") == 0){
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n",&token, &token1);
        //fprintf(fout, "%s\t%s\n", token, token1);
        es = term();
    }
    return es;
}
//<term> -> <factor> {(* | /) <factor>}
// we choose <term> and <factor> to make the mupil first
int term(){
    int es = 0;
    es = factor();
    while(strcmp(token, "*") == 0 || strcmp(token, "/") == 0){
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
        //fprintf(fout, "%s\t%s\n", token, token1);
        es = factor();
        if(es > 0)
            return es;
    }
    return es;
}
// <factor> -> (<expression>) | ID | NUM
//
int factor(){
    int es = 0;
    // it's a expression
    if(strcmp(token, "(") == 0){
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
        //fprintf(fout, "%s\t%s\n", token, token1);
        es = expression();

        if(strcmp(token, ")")){
            fprintf(fout, "ERROR ! -------------missing the ')'\n");
        } else{
            fprintf(fout, "%s\t%s\n", token, token1);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
    }
    //or it's ID or NUM
    else{
        if(strcmp(token, "-") == 0){                     //analyse negative number
            fprintf(fout, "%s\t%s\n", token, token1);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
        if(strcmp(token, "ID") == 0 || strcmp(token, "NUM") == 0){
            fprintf(fout, "%s\t%s\n", token, token1);
            fscanf(fp, "%s %s\n", &token, &token1);
            //fprintf(fout, "%s\t%s\n", token, token1);
            return es;
        }
        else{
            // loss the object
            fprintf(fout, "ERROR ! -------------missing the object\n");
            es = 7;
            return es;
        }
    }
    return es;
}
// <switch_stat> -> switch(ID){<case_stat>}
//
int switch_stat(){
    fprintf(fout, "|----------------switch_stat---------------|\n");
    int es = 0;
    fprintf(fout, "%s\t%s\n", token, token1);
    fscanf(fp, "%s %s \n" , &token,&token1);

    // check the '('
    if(strcmp(token, "(")){
        fprintf(fout, "ERROR ! -------------missing the '('\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }
    // check the ID
    if(strcmp(token, "ID")){
        fprintf(fout, "ERROR ! -------------missing the object\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    // check the ')'
    if(strcmp(token, ")")){
        fprintf(fout, "ERROR ! -------------missing the ')'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }

    // check the '{'
    if(strcmp(token, "{")) {
        fprintf(fout, "ERROR ! -------------missing the '{'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
    }

    while(strcmp(token, "}")){
        es = case_stat();
    }

    if(strcmp(token, "}")){
        fprintf(fout, "ERROR ! -------------missing the '}'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s\n", &token, &token1);
    }
    return es;
}
//
//
int case_stat(){
    int es = 0;
    fprintf(fout, "%s\t%s\n", token, token1);
    if(strcmp(token, "case") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        if(strcmp(token, "NUM")){
            fprintf(fout, "ERROR ! -------------missing the object\n");
        } else{
            fprintf(fout, "%s\t%s\n", token, token1);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
        if(strcmp(token, ":")){
            fprintf(fout, "ERROR ! -------------missing the ':'\n");
        } else{
            fprintf(fout, "%s\t%s\n", token, token1);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
        es = statement();
    }
    else if (strcmp(token, "default") == 0){
        fscanf(fp, "%s %s\n", &token, &token1);
        if(strcmp(token, ":")){
            fprintf(fout, "ERROR ! -------------missing the ':'\n");
        } else{
            fprintf(fout, "%s\t%s\n", token, token1);
            fscanf(fp, "%s %s\n", &token, &token1);
        }
        es = statement();
    } else{
        fprintf(fout, "ERROR ! -------------missing the object\n");
    }

    return es;
}
//
//
int break_stat(){
    fprintf(fout, "|----------break_stat----------|\n");
    int es = 0;
    fprintf(fout, "%s\t%s\n", token, token1);
    fscanf(fp, "%s %s \n" , &token,&token1);
    if(strcmp(token, ";")){
        fprintf(fout, "ERROR ! -------------missing the ';'\n");
    } else{
        fprintf(fout, "%s\t%s\n", token, token1);
        fscanf(fp, "%s %s \n" , &token,&token1);
    }
    return es;
}
