%token WORD
%token ASSIGNMENT_WORD
%token NAME
%token NEWLINE
%token IO_NUMBER
%token AND_IF
%token OR_IF
%token DSEMI
%token DLESS
%token DGREAT
%token LESSAND
%token GREATAND
%token LESSGREAT
%token DLESSDASH
%token CLOBBER
%token IF
%token THEN
%token ELSE
%token ELIF
%token FI
%token DO
%token DONE
%token CASE
%token ESAC
%token WHILE
%token UNTIL
%token FOR
%token LBRACE
%token RBRACE
%token BANG
%token IN
%token AND
%token SEMICOLON

%%

command:
  p = option(cmd_arg);
  w = option(WORD);
  s = list(cmd_arg)
  {
    Ast.Command(p, w, s)
  }

cmd_arg:
  | r = io_redirect { Ast.CommandRedirect r }
  | w = WORD { Ast.CommandArg w }

io_redirect:
  | n = option(IO_NUMBER); f = io_file { Ast.RedirectTo(n, f) }
  | n = option(IO_NUMBER); h = io_here { Ast.RedirectFrom(n, h) }

io_file:
  | LESS; w = word { Ast.FromFile }
  | LESSAND; w = word { Ast.FromDescriptor }
  | GREAT; w = word { Ast.ToFile }
  | GREATAND; w = word { Ast.ToFileDescriptor }
  | DGREAT; w = word { Ast.AppendToFile }
  | LESSGREAT; w = word { Ast.ReadWriteFile }
  | CLOBBER; w = word { Ast.ClobberFile }

io_here:
  | DLESS; w = word
  | DLESSDASH; w = word { Ast.IoHere w }

linebreak:
  list(NEWLINE) { () }

separator:
  | AND
  | SEMICOLON
  | list(NEWLINE) { () }

sequential_sep:
  | SEMICOLON; linebreak
  | list(NEWLINE) { () }
