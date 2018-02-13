function [retval] = compute_matrix_times_vector(A,x)
if(ismatrix(A) && isvector(x))
disp(A * x)
N = rows(A)
for i = 1 : N
sum = 0
for j = 1 : N
sum += A(i,j) * x(j);
endfor
retval(i) = sum;
endfor

else
error("WTF matrix vector product")
endif

endfunction