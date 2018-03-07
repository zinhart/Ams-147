function target = logical_nor(x,y)
  assert( (x == 0 | x == 1) & (y == 0 | y == 1),"x and y can only be values of 0 or 1\n" ); #non-short circuit
  target = ternary( (x == 0 & y == 0), 1, 0);
endfunction