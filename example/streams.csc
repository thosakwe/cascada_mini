#!/usr/bin/env cascada -F

# There is no such thing as a "list" or "array" in Cascada.
# Any collection of items is a "stream." Streams are usually
# processed by "mapping" them through functions (which are applied)
# to each item in the stream, OR "piping" them into a "sink," which
# is a function or object that waits for the stream to be "complete,"
# and then performs some aggregate action on all items.
#
# Piping actions are considered destructive, and prevent a stream from
# being re-used, as they only run after it is complete.

# The pipeline operator ("|>") comes in handy here.

# For example, here's a stream of 5 natural numbers, mapped into
# a function that doubles them:

[1, 2, 3, 4, 5]
  |> \@ * 2

# Opening a file creates a stream. Here's how to capitalize every line
# in a file, and then print each:

open "myfile.txt" "r"
  |> lines
  |> to_upper
  |> print
