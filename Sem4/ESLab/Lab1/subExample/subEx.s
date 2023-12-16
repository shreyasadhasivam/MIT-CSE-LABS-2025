	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA example,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler

	MOV R0,#10
	MOV R2,#3
	SUB R0,R2
STOP B STOP
	END