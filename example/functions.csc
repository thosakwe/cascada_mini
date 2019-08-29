#!/usr/bin/env cascada

fn add_two(x) -> x + 2

fn add_or_sub_two(x, sub=False) {
  if (sub) then
    x - 2
  else
    add_two(x)
}