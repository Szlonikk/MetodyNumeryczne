set terminal svg
set output 'output.svg'
set logscale y 10
set xlabel "iteracje"
set ylabel "blad"

plot 'jacobi.txt' lt 7 lw 2 w l,'gaus.txt' lt 6 lw 2 w l

