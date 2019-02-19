Aux		DCD		0x7f800000, 0x007fffff, 0x7fffffff
		;R0		-> x
		;R1		-> y
		;R11		-> parameter for each subroutine except sum & hell (those take x & y)
		;R12		-> aux
		ldr		R0, =0x40900000	;number x
		ldr		R1, =0xc0700000	;number y
		ldr		R12, =Aux		;aux array
		bl		hell
		b		done

sign		ldr		R10, [R12, #8]		;load mask for filtering sign bit
		mvn		R10, R10			;negate the element
		and		R11, R11, R10		;filter the sign bit
		lsr		R11, R11, #31		;format
		mov		PC, LR

exp		ldr		R10, [R12, #4]		;load mask for filtering the exponent bits
		mvn		R10, R10		;negate the element
		and		R11, R11, R10		;filter the exponent bits
		lsl		R11, R11, #1		;format
		lsr		R11, R11, #24		;format
		add		R11, R11, #-127	;convert from excess-127
		mov		PC, LR

mant		ldr		R10, [R12, #0]		;load mask for filtering the mantisse bits
		mvn		R10, R10		;negate the element
		and		R11, R11, R10		;filter the mantisse bits
		lsl		R11, R11, #9
		lsr		R11, R11, #9
		add		R11, R11, #0x800000
		mov		PC, LR

sum		ldr		R10, [R12, #8]		;load element to remove the sign bit
		ands		R11, R0, R10		;remove sign bit
		moveq		R3, R1			;if x is 0 return y
		moveq		PC, LR
		ands		R11, R1, R10		;remove sign bit
		moveq		R3, R0			;if y is 0 return x
		moveq		PC, LR

		;store	LR
		mov		R9, LR

		;get		mantisses
		mov		R11, R0
		bl		mant
		mov		R3, R11	;x mantisse

		mov		R11, R1
		bl		mant
		mov		R4, R11	;y mantisse

		;get		exponents
		mov		R11, R0
		bl		exp
		mov		R5, R11	;x exponent

		mov		R11, R1
		bl		exp		;y exponent
		mov		R6, R11

		;get		signs
		mov		R11, R0
		bl		sign
		mov		R7, R11	;x sign

		mov		R11, R1
		bl		sign
		mov		R8, R11	;y sign

		;give lr his value back
		mov		LR, R9
		;mantisses	to exponent 0
		cmp		R5, R6
		beq		wut
		bhi		hit	; exp(x)>exp(y)
		b		miss ; exp(x)<exp(y)

hit		mov		R10 , R5
		sub		R5, R5, R6
		lsr		R4, R4, R5 ; align y mantisse
		b		wut
miss		mov		R10, R6
		sub		R5, R6, R5
		lsr		R3, R3, R5 ;align x mantisse
		b		wut

		;compare mantisses
wut		cmp		R3, R4
		mov		R9, R8
		movhi		R9, R7 ;if |y|>|x| final sign = sign(y) else sign(x)

		;cases of addition
		cmp		R7, R8	;compare signs
		beq		equal
		bhi		revsub
		b		normsub

equal		add		R3, R3, R4
		b		continue

revsub		rsb		R3, R3, R4
		b		continue

normsub		sub		R3, R3, R4
		b		continue

continue	ldr		R11, =0xff800000 ;mask to adjust mantisse
		lsl		R3, R3, R10
		mov		R5, #0	;final exp
loop		and		R10, R3, R11
		lsr		R10, R10, #23
		cmp		R10, #1
		beq		finalsum
		bhi		wow
		b		WoW

		;normalize for positive exponent
wow		add		R5, R5, #1
		lsr		R10, R10, #1
		lsr		R3, R3, #1
		b		loop
		;normalize for negative exponent
WoW		add		R5, R5, #-1
		lsl		R10, R10, #1
		lsl		R3, R3, #1

finalsum	mvn		R11, R11	;mask to filter mantisse
		and		R3, R3, R11 	;final mantisse
		
		lsl		R9, R9, #31 ;final sign
		add		R3, R3, R9 ;add it to final result
		
		add		R5, R5, #127 ;coded exp
		lsl		R5, R5, #23
		add		R3, R3, R5   ;add exp

		mov		PC, LR

		;discover by yourself
hell		mov		R2, LR
		mov		R11, R1
		bl		sign
		cmp		R11, #0
		beq		helpme
		b		killme

		;i'm done
helpme		add		R1, R1, #0x80000000
		b		dead

killme		sub		R1, R1, #0x80000000
		b		dead

dead		bl		sum
		mov		LR, R2
		mov		PC, LR

done		end
