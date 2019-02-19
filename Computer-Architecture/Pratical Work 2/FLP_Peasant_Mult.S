Aux	  DCD		0x7f800000, 0x007fffff, 0x7fffffff
          ;R0		-> x
          ;R1		-> y
          ;R11		-> parameter for each subroutine except sum & hell (those take x & y)
          ;R12		-> aux
          ldr		R0, =0x42040000	;number x
          ldr		R1, =0xc0380000	;number y
          ldr		R12, =Aux			;aux array
          bl		mult
          b		done
		
sign	  ldr		R10, [R12, #8]		;load mask for filtering sign bit
          mvn		R10, R10			;negate the element
          and		R11, R11, R10		;filter the sign bit
          lsr		R11, R11, #31		;format
          mov		PC, LR
		
exp	  ldr		R10, [R12, #4]		;load mask for filtering the exponent bits
          mvn		R10, R10			;negate the element
          and		R11, R11, R10		;filter the exponent bits
          lsl		R11, R11, #1		;format
          lsr		R11, R11, #24		;format
          add		R11, R11, #-127	;convert from excess-127
          mov		PC, LR
		
mant	  ldr		R10, [R12, #0]		;load mask for filtering the mantisse bits
          mvn		R10, R10			;negate the element
          and		R11, R11, R10		;filter the mantisse bits
          lsl		R11, R11, #9
          lsr		R11, R11, #9
          add		R11, R11, #0x800000
          mov		PC, LR
		
mult	  lsls		R11, R0, #1
          beq		done
          lsls		R11, R1, #1
          beq		done

          mov		R2, LR ;store LR

          mov		R11, R0
          bl		exp
          mov		R3, R11
          mov		R11, R1
          bl		exp
          add		R3, R3, R11 ;R3->final expoent

          mov		R11, R0
          bl		sign
          mov		R4, R11
          mov		R11, R1
          bl		sign
          eor		R4, R4, R11 ;R4->final sign

          mov		R11, R0
          bl		mant
          mov		R5, R11 ;R5->x mant
          mov		R11, R1
          bl		mant
          mov		R6, R11 ;R6->y mant

          mov		LR, R2
		
	 ;reduce mantisses
loop	  ands		R11, R5, #1
          bne		continue
          ands		R11, R6, #1
          bne		continue
          add		R7, R7, #1
          lsr		R5, R5, #1
          lsr		R6, R6, #1
          b		loop

compare	  cmp		R5, R6 ;performance
	  bcs		continue
	  mov		R11, R5
  	  mov		R5, R6
	  mov		R6, R11
		
continue  ands		R11, R5, #1
          addne	  	R8, R8, R6
          cmp		R5, #1
          beq		norm
          add		R7, R7, #-1
          lsr		R5, R5, #1
          lsl		R6, R6, #1
          b		continue
		
norm	  lsl		R8, R8, R7
	  ldr		R12, =0xff800000
repeat    and		R11, R8, R12
	  lsr		R11, R11, #23
          cmp		R11, #1
          beq		bob
          bhi		shrink
          b		grow
		
shrink	  add		R3, R3, #1
	  lsr		R8, R8, #1
	  b		repeat
		
grow	  add		R3, R3, #-1
          lsl		R8, R8, #1
	  b		repeat
		
bob	  mvn		R12, R12
     	  and		R8, R8, R12
			
          add		R3, R3, #127
          lsl		R3, R3, #23
          add		R8, R8, R3

          lsl		R4, R4, #31
          add		R8, R8, R4

          mov		PC, LR
			
done	  end
