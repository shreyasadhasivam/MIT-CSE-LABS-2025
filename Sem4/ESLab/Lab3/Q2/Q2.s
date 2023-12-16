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

		LDR R1, =NUM
		LDR R2, =RESULT
		
		LDR R3,[R1]

		MLA R4,R3,R3,R3
		LSR R4,#1
		STR R4,[R2]
		
STOP 	B STOP

NUM DCD 10
		AREA mydata, DATA,READWRITE
RESULT DCD 0
		END