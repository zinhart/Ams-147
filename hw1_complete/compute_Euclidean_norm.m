function retval = compute_Euclidean_norm(v)
sum = 0
for i = 1 : size(v)
sum += v(i) * v(i);
endfor
retval = sqrt(sum);
if( (norm(v) != retval) )
disp(norm(v));
disp(retval);
error("WTF"- compute_Euclidean_norm);
endif
endfunction