%{
extern int yylex();
extern FILE* yyin;
%}

%token CASCADA_TOKEN_ARROW "->"
%token CASCADA_TOKEN_COLON ":"
%token CASCADA_TOKEN_COMMA ","
%token CASCADA_TOKEN_LBRACKET "["
%token CASCADA_TOKEN_RBRACKET "]"
%token CASCADA_TOKEN_LCURLY "{"
%token CASCADA_TOKEN_RCURLY "}"
%token CASCADA_TOKEN_LPAREN "("
%token CASCADA_TOKEN_RPAREN ")"
%token CASCADA_TOKEN_OP_EQUALS "="
%token CASCADA_TOKEN_OP_MULT "*"
%token CASCADA_TOKEN_OP_DIV "/"
%token CASCADA_TOKEN_OP_MOD "%"
%token CASCADA_TOKEN_OP_PLUS "+"
%token CASCADA_TOKEN_OP_MINUS "-"
%token CASCADA_TOKEN_ELSE "else"
%token CASCADA_TOKEN_FINAL "final"
%token CASCADA_TOKEN_IF "if"
%token CASCADA_TOKEN_RETURN "return"
%token CASCADA_TOKEN_THEN "then"
%token CASCADA_TOKEN_VAR "var"
%token CASCADA_TOKEN_BOOL "bool literal"
%token CASCADA_TOKEN_HEX "hex literal"
%token CASCADA_TOKEN_NUMBER "decimal literal"
%token CASCADA_TOKEN_DOUBLE_QUOTE '"'
%token CASCADA_TOKEN_SINGLE_QUOTE "'"
%token CASCADA_TOKEN_ID "identifier"
%token CASCADA_TOKEN_ESCAPED_QUOTE "escaped quote"
%token CASCADA_TOKEN_STRING_HEX_ESCAPE "hex escape"
%token CASCADA_TOKEN_STRING_UNI_ESCAPE "unicode escape"
%token CASCADA_TOKEN_STRING_TEXT "plain text"

%%

expr:
  CASCADA_TOKEN_LPAREN expr CASCADA_TOKEN_RPAREN { $$ = $1; }
  | 
;
