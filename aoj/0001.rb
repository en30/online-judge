require 'set'

set = []

while line = STDIN.gets
  set << line.chomp.to_i
end

set.sort!

3.times { puts set.pop }
