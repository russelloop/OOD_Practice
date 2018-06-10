/*
 @author root
 @ v1.0.0
    + Base Outline
    + Progress ID
    + Progress Keyword "if", "else", "for", "while", "do", "int", "read", "write"
    + Progress NUM
    + Progress Singleword "+-*(){};.:"
    + Progress Doubleword "><=!"
    + Progress comments like /**\/
 @ v1.0.1
    + Progress comments like //
    ~ Progress more Keyword like "double"
    ~ Progress more Keyword like "switch"
*/

#include <stdio.h>
#include <ctype.h>
#include <mem.h>

//Define a reserved word table
#define keywordSum 8
char *keyword[keywordSum] = {"if", "else", "for", "while", "do", "int", "read", "write"};
//Define single demarcation
char singleword[50] =  "+-*(){};.:";
//Define double demarcation 's first char
char doubleword[10]="><=!";
extern char Scanin[300], Scanout[300];
//to receives the name of I/O files (defined in test_main.c)
extern FILE *fin, *fout;    //pointer that point at I/O files (defined in test_main.c)
int TESTscan(){             //Lexical Analysis Function
    char ch, token[40];     //ch is for each char that read in, token is for word that pick out
    int es = 0, j, n;       //es is error code (0 means no error)
    //j, n are temp var
    printf("Please enter the name of the original program (Route Included): ");
    scanf("%s", Scanin);
    printf("Please enter the name of the output file (Route Included): ");
    scanf("%s", Scanout);
    if((fin = fopen(Scanin, "r")) == NULL){
        printf("\nERROR: FAIL TO OPEN THE INPUT FILE.\n");
        return(1);
    }
    if((fout = fopen(Scanout, "w")) == NULL){
        printf("\nERROR: FAIL TO OPEN THE OUTPUT FILE.");
        return(2);
    }
    printf("************* Lexical Analyse Result *************\n");
    ch = getc(fin);
    while(ch != EOF){
        while(ch == ' ' || ch == '\n' || ch == '\t')
            ch = getc (fin);
        if(isalpha(ch)){                            //if it is an alphabet
            token[0] = ch;
            j = 1;
            ch = getc(fin);
            while (isalnum(ch)){                        //if it is a combinatorial identifier
                token[j++] = ch;
                ch = getc(fin);
            }
            token[j] = '\0';                            //else end the identifier

            //*******Reserved-word check*******
            n = 0;
            while((n < keywordSum) && strcmp(token, keyword[n]))
                n++;
            if(n >= keywordSum)                         //not reserved-word
                fprintf(fout, "%s\t%s\n", "ID", token); //output identifier
            else                                        //is reserved-word
                fprintf(fout, "%s\t%s\n", token, token);//output reserved-word
        }else if(isdigit(ch)){                      //processing digits
            token[0] = ch;
            j = 1;
            ch = getc(fin);                         //get next token
            while(isdigit(ch)){                     //if get digits then combine then into an integer
                token[j++] = ch;
                ch = getc(fin);
            }
            token[j] = '\0';                        //end digits combination
            fprintf(fout, "%s\t%s\n", "NUM", token);//output integer
        }else if(strchr(singleword, ch) > 0){       //process single-delimiter
            token[0] = ch;
            token[1] = '\0';
            ch = getc(fin);
            fprintf(fout, "%s\t%s\n", token, token);//out put single-delimiter
        }else if(strchr(doubleword, ch) > 0){//process double-delimiter
            token[0] = ch;
            ch = getc(fin);
            if(ch == '='){                             //if next is '='
                token[1] = ch;                          //combine the double-delimiter
                token[2] = '\0';
                ch = getc(fin);
            }else                                     //else is single-delimiter
                token[1] = '\0';
            fprintf(fout, "%s\t%s\n", token, token);
        }else if(ch == '/'){                          //progress comments
            ch = getc(fin);
            if(ch == '*'){                                  //if is '*' , start progress multi-line comments
                char ch1;
                ch1 = getc(fin);
                do{
                    ch = ch1;
                    ch1 = getc(fin);                        //delete comments
                }while((ch != '*' || ch1 != '/') && ch1 != EOF);    //until meet '*/' or EOF
                ch = getc(fin);
            }else if(ch == '/'){                            //if is another '/', start progress single-line comments
                char ch1;
                ch1 = getc(fin);                            //delete comments
                do{
                    ch = ch1;
                    ch1 = getc(fin);
                }while((ch1 != '\n') && ch1 != EOF);        //until line ends
                ch = getc(fin);
            }else{                                          //else progress it as a single-delimiter
                token[0] = '/';
                token[1] = '\0';
                fprintf(fout, "%s\t%s\n", token, token);
            }
        }else{
            token[0] = ch;
            token[1] = '\0';
            ch = getc(fin);
            es = 3;                                         //set error code
            fprintf(fout, "%s\t%s\n", "ERROR", token);      //output error token
        }
    }
    fclose(fin);
    fclose(fout);
    return(es);
};