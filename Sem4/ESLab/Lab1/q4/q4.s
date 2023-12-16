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
	
	LDR R0, =SRC ;load address of src into r0
	LDR R1, =DST ; load address of dest into r1
	ADD R0, #36
	MOV R5, #10; placing 5 in r5
up  LDR R3, [R0] ;load data in src into r2
	STR R3, [R1], #4 ;load data in dest into r3
	
	SUB R0, #4 ;reducing 5
	SUBS R5, #1
	BNE up
	
STOP
	B STOP

SRC DCD 1,2,3,4,5,6,7,8,9,10
	AREA mydata, DATA, READWRITE

DST DCD 0
	END