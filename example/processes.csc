#!/usr/bin/env cascada

let unique_extensions () =
  `find . -type f`
    | `basename`
    | distinct
    | map (fn s -> (split s)[1])  
    | join ","
in

let count = count (unique_extensions) in

print "There are ${count} unique extensions."
