parser grammar CascadaParser;

expr:
    ID #IdExpr
    | str #StrExpr
    | expr DOT ID #MemberExpr
    | target=expr PAREN_L argList PAREN_R #CallExpr
    ;//PAREN_L ID PAREN_R #ParenExpr
//;

str:
    ENTER_STR_DQ dblStrPart* EXIT_STR_DQ #DblStr
;

dblStrPart:
    ID_INTERP_DQ #DblStrIdInterpPart
    | ENTER_EXPR_INTERP_DQ expr PAREN_R #DblStrExprInterpPart
    | ESCAPED_PERCENT_DQ #DblEscapedPercentPart
    | ESCAPED_QUOTE_DQ #DblEscapedQuotePart
    | TEXT_DQ #DblTextPart
;

argList:
     (expr COMMA)* expr  #SimpleArgList
    |  (namedArg COMMA)* namedArg #NamedArtList
    |  (expr COMMA)* expr COMMA (namedArg COMMA)* namedArg  #MixedArgList
;

namedArg: name=ID COLON expr;

