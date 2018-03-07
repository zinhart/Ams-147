function retval = ternary (expr, true_val, false_val)
  if (expr)
    retval = true_val;
  else
    retval = false_val;
  endif
endfunction