lexer grammar CascadaLexer;

// Misc.
SINGLE_LINE_COMMENT: ('#'|'//') (~'\n')* -> skip;
MULTI_LINE_COMMENT: '/*' (MULTI_LINE_COMMENT | .)*? '*/' -> skip;
WS : [ \r\t\n]+ -> skip;

// Symbols
COLON: ':';
COMMA: ',';
CURLY_L: '{';
CURLY_R: '}';
DOT: '.';
PAREN_L: '(' -> pushMode(DEFAULT_MODE);
PAREN_R: ')' -> popMode;

// Values
ENTER_STR_DQ: '"' -> pushMode(STR_DQ);
ID: [A-Za-z_][A-Za-z0-9_]*;

mode STR_DQ;

ID_INTERP_DQ: '%'[A-Za-z_][A-Za-z0-9_]*;
ENTER_EXPR_INTERP_DQ: '%(' -> pushMode(DEFAULT_MODE);
ESCAPED_PERCENT_DQ: '\\%';
ESCAPED_QUOTE_DQ: '\\"';
TEXT_DQ: ~('%'|'\n'|'"')+;
EXIT_STR_DQ: '"' -> popMode;