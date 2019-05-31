{
  open Lexing
  open Parser
}

rule read =
  parse
  | word { WORD }
  | assignment_word { ASSIGNMENT_WORD }
  | name { NAME }
  | newline { NEWLINE }
  | io_number { IO_NUMBER }
  | "&&" { AND_IF }
  | "||" { OR_IF }
  | ";;" { DSEMI }
  | "<<" { DLESS }
  | ">>" { DGREAT }
  | "<&" { LESSAND }
  | ">&" { GREATAND }
  | "<>" { LESSGREAT }
  | "<<-" { DLESSDASH }
  | ">|" { CLOBBER }
  | "if" { IF }
  | "then" { THEN }
  | "else" { ELSE }
  | "elif" { ELIF }
  | "fi" { FI }
  | "do" { DO }
  | "done" { DONE }
  | "case" { CASE }
  | "esac" { ESAC }
  | "while" { WHILE }
  | "until" { UNTIL }
  | "for" { FOR }
  | '{'  { LBRACE }
  | '}'  { RBRACE }
  | '!'  { BANG }
  | "in" { IN }
