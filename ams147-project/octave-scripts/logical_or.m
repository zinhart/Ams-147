function targets = logical_or(inputs)
  assert(length(inputs) == 2);
  x = inputs(1);
  y = inputs(2);
  assert( (x == 0 | x == 1) & (y == 0 | y == 1),"x and y can only be values of 0 or 1\n" ); #non-short circuit
  targets = ternary( (x == 0 & y == 0), 0, 1);
endfunction