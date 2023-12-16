
%{
    #include "q3.tab.h"
%}

%%
[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}
[a-z A-Z]+ {return ID;}
[\t]+ ;
\n {return 0;}
.    {return yytext[0];}
%%
int yywrap(){}