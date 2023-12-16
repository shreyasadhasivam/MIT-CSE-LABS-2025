		AREA RESET, DATA, READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler


		LDR R0,=NUM
		LDR R3,=RESULT
		LDRB R1,[R0]
		AND R2,R1,#0x0F ; mask upper 4 bits
		CMP R2,#09;compare digit with 0
		BLS DOWN1;if it is lower than jump to label
		ADD R2,#07;else add 7 to num
DOWN1
		ADD R2,#0x30;add 30 to num
		STRB R2,[R3]
		AND R4,R1,#0xF0;mask second digit
		LSR R4,#04; shift right by 4
		CMP R4,#09
		BLS DOWN2
		ADD R4, #07
		
DOWN2
		ADD R4,#0x30 ; ascii value of second digit
		STRB R4,[R3,#01]
STOP B STOP

NUM DCD 0x000000FF
		AREA mydata,DATA, READWRITE
RESULT DCD 0
	
		END
