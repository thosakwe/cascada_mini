#!/usr/bin/env cascada

fn add_two(x) => x + 2

fn add_or_sub_two(x, sub=False) {
  if (sub)
    return x - 2
  else
    return add_two(x)
}