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
		
		LDR R1,=N1
		LDR R2,=N2
		LDR R3,=QUOTIENT
		LDR R6,=REM
		MOV R0,#0; counter
		LDR R4,[R1] 
		LDR R5,[R2]
UP		CMP R4,R5;when n1<n2, carry will clear
		BCC STORE ; branch if carry clear
		
		SUB R4,R5 ;subtracting ;5-2 = 3; 3-2 =1
		ADD R0,#1 ;incrementing counter
		BNE UP

STORE 	STR R0,[R3],#4 ; storing in quotient
		STR R4,[R6] ;storing in rem
STOP	B STOP

N1 DCD 5
N2 DCD 2
		AREA mydata, DATA, READWRITE
			
QUOTIENT DCD 0
REM 	 DCD 0
		END