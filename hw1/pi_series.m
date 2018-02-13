function [P,E] = pi_series
n = 10
P = zeros(n)
E = zeros(n)
for k = 1 : n
P(k + 1) = P(k) + (1 / (16**k) ) * ( (4 / (8*k + 1)) - (2 / (8*k + 4) ) - (1 / (8*k + 5) ) - (1 / (8*k + 6) )   );
endfor
root_six = sqrt(6);
for i = 1 : n
sum = 0;
or j = 1 : 10
sum += 1 / (j*j);
E(i) = root_six * sqrt(sum);
n1 = 0
n2 = 0
endfor

#endfor
n1 = 0; 
n2 = 0;
endfunction