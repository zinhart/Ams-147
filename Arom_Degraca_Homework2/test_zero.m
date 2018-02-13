function [zc,zn,ec,en,x,f] = test_zero()
tol = 1.e-15;
Nmax = 20000;
a = -0.96;
b = -0.95;
x0 = -0.95;
focp = @(x)(16*x.^5 - 20*x.^3 + 5*x);%fifth_order_chebyshev_polynomial
focpd = @(x)(80*x.^4 - 60*x.^2 + 5);%fifth_order_chebyshev_polynomial_derivative
error_calc = @(x_k, z0)( abs(x_k - z0) );%function implementing |e^(k+1) - z0|

[zc,iter_c,res_c,his_c] = chord_method(focp,a,b,tol, Nmax);% find zero
ec = error_calc(his_c, zc);%calculate error for chrod method
fprintf("zc: %d, iter_c: %d\n",zc,iter_c);

[zn,iter_n,res_n, his_n] = Newton_method(focp,focpd,x0,tol,Nmax);
en = error_calc(his_n,zn);
fprintf("zn: %d, iter_n: %d\n",zn,iter_n);


x = linspace(-1,1,1000);
f = focp(x);
%{
for i = 1 : 10
fprintf("x(%d) =%d  f(%d) = %d\n",i,x(i),i, f(i));
endfor
%}

%graph of chebyshev_polynomial figure 1 with domain [-1,1]
focp_domain = f;%[-1:0.01:1]; 
figure(1);
plot(focp_domain,focp(focp_domain));
grid on,axis equal;
%%{
%graph of convergence histories figure 2
figure(2);
hold on;
%legend('red is the chord method','blue is newtons meth

semilogy(ec,'r');
semilogy(en,'b');
hold off;

figure(3);
hold on;
loglog(ec(1:end - 1), ec(2:end),'r');
loglog(en(1:end - 1), en(2:end),'b');
hold off;
%%}
endfunction
