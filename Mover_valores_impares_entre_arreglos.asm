
.model small
.stack
.data

    arreglo db "12345678908765",'$'
    impares db "",'$'
    
.code
mov ax,@data
mov ds,ax
xor ax,ax
xor bx,bx
xor si,si
xor di,di

leo:
mov al,arreglo[si]; leo los elementos que hay en ARREGLO
cmp al,'$'
je fin
mov bl,al  ; guardo el valor en un registro auxiliar para enmascarar el valor
and bl,01h ; SALVO EL b0 para saber si es par o impar
cmp bl,00h ; comparo para saber si es par
je par 
mov impares[di],al; guardo el valor que lei anteriormente
inc di
mov impares[di],"$" ; guardo el nuevo final de arreglo
par: 
inc si
jmp leo
fin:
mov ah,4ch
int 21h










