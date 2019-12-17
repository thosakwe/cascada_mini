#!/usr/bin/cascada -F

import Elf

var elf = Elf.parse <>

for elf.symbols {
  if @.type eq Elf.Types.FUNC {
    elf.replace @, blob \
      0xa, 0xb, 0xd
  }
}