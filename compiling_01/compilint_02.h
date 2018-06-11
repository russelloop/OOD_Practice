//
// Created by 高建 on 2018/4/13.
//

#ifndef COMPILING_01_COMPILINT_02_H
#define COMPILING_01_COMPILINT_02_H

#endif //COMPILING_01_COMPILINT_02_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int TESTparse();
int program();
int declaration_list();
int declaration_stat();
int statement_list();
int statement();
int if_stat();
int while_stat();
int for_stat();
int write_stat();
int read_stat();
int compound_stat();
int expression_stat();
int expression();
int bool_expr();
int additive_expr();
int term();
int factor();
