# A verbatim string, without any escapes:
printf "Hello\nWorld"

# A string with escapes
echo "Hello\nworld"

# You can also escape the slash.
printf "Hello\\nworld"

# You can interpolate complex Cascada expressions into strings:
echo "2 + 3 = ${2 + 3}"

# Or you can also just interpolate identifiers.
let foo = "bar";
echo "Foo=$foo"
