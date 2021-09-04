# GRAFICA CUATRO GRAFICAS EN UNA VENTANA
# l@rry
#set term corel
set output  "fourier.eps"

set autoscale
set grid
set style data lines

#------------- Graf 1 ----------------
set title "Function No.4"
#unset label
set xlabel   "muestras"
set ylabel   "x(n)"
plot  "fourier.txt"
unset xlabel
unset ylabel
unset title

pause -1


#