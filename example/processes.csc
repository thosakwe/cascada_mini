#!/usr/bin/env cascada

# Cascada is, first and foremost, a shell. All programs available
# in the PATH are imported into Cascada as top-level functions, for convenience.
#
# Cascada's syntax requires string arguments to be wrapped in quotes.
# The invocation of such a function returns a Process value.
chmod "-f" "u+r" "file.txt"

# However, you can use a shell literal to invoke commands, without
# strings.
#
# A shell literal also evaluates to a Process value, and supports interpolations.
let filename = "file.txt"
let pChmod = $(chmod -f u+r $filename)

# In addition, you can also use backticks:
`chmod -f u+r file.txt`

# You can use the `exitCode` function to get the exit code of a Process.
# It has the signature:
# val exitCode: Process -> num

match (exitCode pChmod) as code with
    0 -> echo "chmod was a success!"
    | _ -> echo "chmod terminated with exit code $code"


# You can also get the stdout or stderr of a process, using these functions:
# val stdout: Process -> InStream
# val stderr: Process -> InStream

let pPrintf = printf 'a\nb\nc'

# Print each line...
lines (stdout pPrintf)
    |> each echo

# You can also write to a process's stdin.
# val stdin: Process -> OutStream

let catInput = new InStream
let pCat = spawn ~stdin: catInput

# You can pipe processes into one another.
let charCount = $(echo hey | wc -c)
                    |> stdout 
                    |> text
                    |> parseNum
