#!/usr/bin/env cascada

var {exec} = import("io")

# Calling `exec` will run a child process, wait
# for it to return, and return a Process object.
# A Process object extends Stream<String>.
#
# The "|" operator can be used to pipe stdout from
# one process into another's stdin. Both processes's
# stderr will be aggregated.

fn unique_extensions =>
  exec("find . -type f")
    | exec("basename")
    | distinct
    | map(fn s => split(s)[1])
    | concat(",")

fn unique_extension_count -> count(unique_extensions())

var count = unique_extension_count()
print("There are " + count + "unique extensions.")
