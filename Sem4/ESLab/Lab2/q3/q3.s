	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
		
		DCD 0X10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler

Reset_Handler

		LDR R0, =VAL1
		LDR R1,[R0]
		LDR R2, =VAL2
		LDR R3,[R2]
		; MOV R5, #0
		SUBS R6, R1,R3
		
		LDR R7,= RESULT
		STR R6,[R7]
STOP 	B STOP

VAL1 	DCD 10
VAL2 	DCD 3
	

		AREA mydata, DATA, READWRITE
	
RESULT DCD 0
	END
		