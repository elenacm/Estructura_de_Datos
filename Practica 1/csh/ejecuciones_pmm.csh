#!/bin/csh
@ inicio = 100
@ fin = 1000
@ incremento = 50
set ejecutable = producto
set salida = tiempo_producto.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i ` >> $salida
  @ i += $incremento
end
