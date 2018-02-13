%apply fixed point iteration theorem
function  [z0,iter,res,his] = Newton_method(fun,dfun,x0,tol,Nmax)
dx = 1;
his = x0;
iter = 1;
while dx > tol && iter < Nmax
z0 = x0 - fun(x0) / dfun(x0);
dx = abs(z0 - x0);
x0 = z0;
his = [his z0];
iter = iter + 1;
endwhile
res = abs(fun(z0));
endfunction
