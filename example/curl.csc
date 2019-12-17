#!/usr/bin/env cascada -F

# Runs `curl`, then prints the HREF of every <a href="..."></a>.

import Html

var dom = `curl "http://example.com"` |> Html.read

dom.querySelector "a[href]"
  |> \print "HREF: " @.attributes.href