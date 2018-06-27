reset
#set yrange[0:3]
set yrange[2.7:2.8]
#set xrange[0:1.1]
set xrange[0.99:1.01]
set xlabel 't'
set ylabel 'x'
plot exp(x) title "exp x"
replot "0.100000-data.txt" using 1:2 with lines title "h=0.1"
replot "0.010000-data.txt" using 1:2 with lines title "h=0.01"
replot "0.001000-data.txt" using 1:2 with lines title "h=0.001"
replot "0.000100-data.txt" using 1:2 with lines title "h=0.0001"
replot "0.000010-data.txt" using 1:2 with lines title "h=0.00001"
replot "0.000001-data.txt" using 1:2 with lines title "h=0.000001"
replot "0.0000001-data.txt" using 1:2 with lines title "h=0.0000001"
replot "0.00000001-data.txt" using 1:2 with lines title "h=0.00000001"
