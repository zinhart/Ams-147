function retval = compute_factorial(n)
if(n > 1)
retval = n *compute_factorial(n - 1);
else
retval = 1;
endif
#retval = hw1.compute_factorial(n);
endfunction