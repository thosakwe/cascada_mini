#!/usr/bin/env cascada -F

# Prints every number in the file/stdin, doubled.

lines <>
  |> func {
        var matches = /[0-9]+/g @
        for matches {
          print (int @) * 2
        }
    }