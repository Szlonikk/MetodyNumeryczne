set term pngcairo
set output 'output.png'
set xlabel "Liczba iteracji"
set ylabel "Czas (nanosekundy)"

plot 'dane.txt' lt 7 lw 2 w l

