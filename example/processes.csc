let unique_extensions () =
  find . -type f
    | basename
    | uniq
    | awk -F "." "{ print $2 }"
    |> String.concat ","

let unique_extension_count () =
  unique_extensions ()
    | wc -c

let count = unique_extension_count ()
echo "There are $count unique extensions."
