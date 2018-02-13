function [z0,iter,res,his] = chord_method(fun,a,b,tol,Nmax)
z0 = (a + b) / 2;
dx = 1;
q = (fun(b) - fun(a)) / (b - a);
his = q;
iter = 1;
while dx > tol && iter < Nmax
z1 = z0 - fun(z0) / q;
dx = abs(z1 -z0);;
z0 = z1;
his = [his z0];
iter = iter + 1;
endwhile
res = abs(fun(z0));
endfunction