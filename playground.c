//Don't use them! Only for compatibility
#define YY_DECL int yylex (YYSTYPE * yylval, struct YYLTYPE * yylloc)
#include <string.h>
#include <stdlib.h>
#include "util/utils.h"
extern int prog_return;
int yywrap(void);
int yylex(YYSTYPE* yylval_param, YYLTYPE* yyloc_param);
void yyerror(YYLTYPE* loc, const char * fmt, ...);
#include "axo/types.h"
#include "axo/axo_err.h"
#include "axo/axo.h"

int main(){
	axo_typ typ = (axo_typ){
		.kind=axo_simple_kind,
		.simple=alloc_str("int")
	};
	char* str = axo_typ_to_ctyp_str(typ);
	printf("%s\n", str);
	return 0;
}