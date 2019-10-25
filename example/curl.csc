#!/usr/bin/env cascada

open Curl
open Html

let res = await Curl.get_url "http://example.com" in
let doc = Html.parse (Curl.response_text res) in
let title = Html.element_text (Html.querySelector doc "#title") in
print "Title: ";
println title
