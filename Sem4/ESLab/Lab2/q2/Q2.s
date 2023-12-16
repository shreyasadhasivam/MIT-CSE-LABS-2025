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


	LDR R0,=N1
	LDR R1,=N2
	LDR R2,[R0]
	LDR R3,[R1]
	LDR R4 ,=DST
	MOV R5,#4
	MOV R6,#0 ;CARRY COUNT
UP	ADDS R2,R3
	ADC R6,#0
	STR R2,[R4],#4
	LDR R2,[R0,#4]! ;loads R2 with the word pointed at R0+4 and updates pointer by adding 4 to R0
	LDR R3,[R1,#4]!
	SUBS R5,#1
	BNE UP
	STR R6,[R4]
STOP B STOP
	
N1 DCD 4,3,2,1
N2 DCD 10,0,0,1
	AREA mydata, DATA, READWRITE
DST DCD 0
	END