.code
gcd: 
sub esp, 4
mov edi, 8
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov eax, 0; calculate int ExpConst 
push eax
pop ebx
pop eax
cmp eax, ebx
mov eax, 0
sete al
cmp eax, 1
je __CG__label0 
jmp __CG__label1
__CG__label0:
mov edi, 4
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov edi, 12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax; assign
jmp __CG__label2
__CG__label1: 
push eax
mov edi, 4
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
mov edi, 8
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
pop ebx
pop eax
xor edx, edx
idiv ebx
mov eax,edx
push eax
mov edi, 8
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
push eax
push ecx
mov ecx, esp
call gcd
pop ecx
pop eax
pop eax
pop eax
push eax
mov edi, 12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax; assign
__CG__label2: 
add esp, 4
ret
main PROC
mov ecx, esp
sub esp, 12
push eax
mov eax, 24; calculate int ExpConst 
push eax
mov eax, 36; calculate int ExpConst 
push eax
push ecx
mov ecx, esp
call gcd
pop ecx
pop eax
pop eax
pop eax
push eax
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pop eax
mov [esi-0], eax; assign
mov edi, -12
mov esi, ecx
add esi, edi
mov eax, [esi]; calculate ExpId 
pusha
invoke printf,offset lb_write_int, eax
popa
add esp, 12
main ENDP
END main
