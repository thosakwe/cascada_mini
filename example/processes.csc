#!/usr/bin/env cascada -F

func unique_extensions {
  ls({recursive: true})
    |> .extension
    |> unique
}

var exts = unique_extensions ()

print "There are " (count exts)  " unique extensions."
