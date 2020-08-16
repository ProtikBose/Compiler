b2 dw ?
i2 dw ?
i2 dw ?
i2 dw ?
a3 dw ?
a3 dw ?
b4 dw ?
tempo02 dw ?
mov ax, 0
mov b2, ax
mov ax, 0
mov i2, ax
 L4:
 mov ax, i
cmp ax, 4
jl L0
mov tempo0, 0
jmp L1
L0:
mov tempo0, 1
L1:
 mov ax , tempo02
 cmp ax , 0
 je L5
 mov ax, 3
mov a3, ax
L2:
 mov ax , a3
sub ax , 1
mov a3 , ax
mov ax , a--
cmp ax , 0
je L3
 mov ax , b4
add ax , 1
mov b4 , ax
jmp L2
L3:
 mov ax , i2
add ax , 1
mov i2 , ax
 jmp L4
 L5:

