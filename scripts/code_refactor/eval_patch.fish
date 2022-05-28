#!/usr/bin/env fish

set source_file $argv[2]
set cocci $argv[1]

echo cocci: $cocci
echo source: $source_file

spatch -cocci_file $cocci $source_file | patch $source_file -
