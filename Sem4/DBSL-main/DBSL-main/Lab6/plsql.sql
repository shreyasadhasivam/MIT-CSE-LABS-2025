----1. Write a PL/SQL block to display the GPA of given student.
declare
        RNumber StudentTable.RollNo%Type;
		stu_gpa StudentTable.GPA%Type;
begin
        RNumber := &Number;
        select GPA into stu_gpa from StudentTable where RollNo=RNumber;
		
		dbms_output.put_line('GPA is: '|| TO_CHAR(stu_gpa));
end;
/

Enter value for number: 2
old   5:         RNumber := &Number;
new   5:         RNumber := 2;
GPA is: 6.5

PL/SQL procedure successfully completed.
----2. Write a PL/SQL block to display the letter grade(0-4: F; 4-5: E; 5-6: D; 6-7: C;
---7-8: B; 8-9: A; 9-10: A+} of given student.

declare
		
		stu_gpa StudentTable.GPA%Type;
		RNumber StudentTable.RollNo%Type;
		
begin
		RNumber := &Number;
		
		select GPA into stu_gpa from StudentTable where RollNo=RNumber;
		if stu_gpa > 0 and stu_gpa<=4 THEN
			DBMS_OUTPUT.PUT_LINE('F');
		ELSIF stu_gpa>4 and stu_gpa<=5 THEN
			DBMS_OUTPUT.PUT_LINE('E');
		ELSIF stu_gpa >5 and stu_gpa<=6 THEN
			DBMS_OUTPUT.PUT_LINE('D');
		ELSIF stu_gpa>6 and stu_gpa<=7 THEN
			DBMS_OUTPUT.PUT_LINE('C');
		ELSIF stu_gpa>7 and stu_gpa <=8 THEN
			DBMS_OUTPUT.PUT_LINE('B');
		ELSIF stu_gpa>8 and stu_gpa<=9 THEN
			DBMS_OUTPUT.PUT_LINE('A');
		ELSIF stu_gpa>9 and stu_gpa<=10 THEN
			DBMS_OUTPUT.PUT_LINE('A+');
		END IF;
END;
/

Enter value for number: 5
old   7: RNumber := &Number;
new   7: RNumber := 5;
A+

PL/SQL procedure successfully completed.

----3. Input the date of issue and date of return for a book. Calculate and display the fine
--with the appropriate message using a PL/SQL block. The fine is charged as per
--the table 8.1:
--Late period Fine
--7 days NIL
--8 – 15 days Rs.1/day
--16 - 30 days Rs. 2/ day
--After 30 days Rs. 5.00
--Table 8.1

declare

		DofI date;
		DofR date;
		Days Numeric(5);
		Fine Numeric(10);
		
begin
    DofI := TO_DATE('&DateOfIssue','DD-MM-YY');
    DofR := TO_DATE('&DateOfReturn','DD-MM-YY');
	Days := (DofR - DofI);
	
	IF Days <=7 THEN
		Fine := 0;
	ELSIF Days >8 and Days <=15 THEN
		Fine := (Days-7) *1;
	ELSIF Days>16 and Days <=30 THEN
		Fine := 0+ ((Days-7)*1)+ ((Days-15)*2);
	ELSIF Days >30 THEN
		Fine := 0+ ((Days-7)*1)+ ((Days-15)*2) +((Days-30)*5);
	END IF;
	
	dbms_output.put_line('Fine to be paid is: '||TO_CHAR(Fine));
END;
/

Enter value for dateofissue: 1-3-2023
old   9:     DofI := TO_DATE('&DateOfIssue','DD-MM-YY');
new   9:     DofI := TO_DATE('1-3-2023','DD-MM-YY');
Enter value for dateofreturn: 25-3-2023
old  10:     DofR := TO_DATE('&DateOfReturn','DD-MM-YY');
new  10:     DofR := TO_DATE('25-3-2023','DD-MM-YY');
Fine to be paid is: 35

PL/SQL procedure successfully completed.

---4. Write a PL/SQL block to print the letter grade of all the students(RollNo: 1 - 5).

declare
		stu_gpa StudentTable.GPA%TYPE;
		RNo StudentTable.RollNo%TYPE;
		
		
begin
		RNo := 1;
		LOOP			
			
			select GPA into stu_gpa from StudentTable where RollNo=RNo;
			if stu_gpa > 0 and stu_gpa<=4 THEN
				DBMS_OUTPUT.PUT_LINE('F');
			ELSIF stu_gpa>4 and stu_gpa<=5 THEN
				DBMS_OUTPUT.PUT_LINE('E');
			ELSIF stu_gpa >5 and stu_gpa<=6 THEN
				DBMS_OUTPUT.PUT_LINE('D');
			ELSIF stu_gpa>6 and stu_gpa<=7 THEN
				DBMS_OUTPUT.PUT_LINE('C');
			ELSIF stu_gpa>7 and stu_gpa <=8 THEN
				DBMS_OUTPUT.PUT_LINE('B');
			ELSIF stu_gpa>8 and stu_gpa<=9 THEN
				DBMS_OUTPUT.PUT_LINE('A');
			ELSE
				DBMS_OUTPUT.PUT_LINE('A+');
			END IF;
			RNo := RNo +1;
			IF RNo>5 THEN EXIT;
				END IF;
		END LOOP;
END;
/
				
D
C
F
B
A+

PL/SQL procedure successfully completed.

----5.5. Alter StudentTable by appending an additional column LetterGrade Varchar2(2).
---Then write a PL/SQL block to update the table with letter grade of each student.

declare
			RNo studenttable.RollNo%TYPE;
			stu_gpa studenttable.GPA%TYPE;
begin 
		RNo :=1;
		WHILE RNo<6
		  LOOP
			select GPA into stu_gpa from StudentTable where RollNo=RNo;
			if stu_gpa > 0 and stu_gpa<=4 THEN
				update studenttable set lettergrade ='F' where RollNo=RNo;
			ELSIF stu_gpa>4 and stu_gpa<=5 THEN
				update studenttable set lettergrade ='E' where RollNo=RNo;
			ELSIF stu_gpa >5 and stu_gpa<=6 THEN
				update studenttable set lettergrade ='D' where RollNo=RNo;
			ELSIF stu_gpa>6 and stu_gpa<=7 THEN
				update studenttable set lettergrade ='C' where RollNo=RNo;
			ELSIF stu_gpa>7 and stu_gpa <=8 THEN
				update studenttable set lettergrade ='B' where RollNo=RNo;
			ELSIF stu_gpa>8 and stu_gpa<=9 THEN
				update studenttable set lettergrade ='A' where RollNo=RNo;
			ELSE
				update studenttable set lettergrade ='A+' where RollNo=RNo;
			END IF;
			
			RNo := RNo +1;
		  END LOOP;
END;
/

PL/SQL procedure successfully completed.

SQL> select * from studenttable;

    ROLLNO        GPA LE
---------- ---------- --
         1        5.8 D
         2        6.5 C
         3        3.4 F
         4        7.8 B
         5        9.5 A+


----6. Write a PL/SQL block to find the student with max. GPA without using aggregate
---function.

declare
		RNo studenttable.RollNo%TYPE;
		stu_gpa studenttable.GPA%TYPE;
		Max_gpa float;
		

begin
		RNo := 1;
		Max_gpa :=0;
		select gpa into stu_gpa from studenttable  where RollNo= RNo;
		for Rno in 1..5 
		LOOP
			if stu_gpa > Max_gpa then 
				Max_gpa := stu_gpa;
			end if;
		end loop;
	
		dbms_output.put_line('Max GPA''s roll number: ' || TO_CHAR(RNo) || ' and GPA is: '||TO_CHAR(max_gpa));
end;
/
		
Max GPA''s roll number: 1 and GPA is: 5.8

PL/SQL procedure successfully completed.

---7. Implement lab exercise 4 using GOTO. 
declare 
	stu_gpa StudentTable.GPA%TYPE;
		RNo StudentTable.RollNo%TYPE;
		g char(2);
begin
		RNo := 1;
		LOOP
			select GPA into stu_gpa from StudentTable where RollNo=RNo;
			if stu_gpa > 0 and stu_gpa<=4 THEN
				g := 'F';
				goto output;
			ELSIF stu_gpa>4 and stu_gpa<=5 THEN
				g := 'E';
				goto output;
			ELSIF stu_gpa >5 and stu_gpa<=6 THEN
				g := 'D';
				goto output;
			ELSIF stu_gpa>6 and stu_gpa<=7 THEN
				g := 'C';
				goto output;
			ELSIF stu_gpa>7 and stu_gpa <=8 THEN
				g := 'B';
				goto output;
			ELSIF stu_gpa>8 and stu_gpa<=9 THEN
				g := 'A';
				goto output;
			ELSE
				g := 'A+';
				goto output;
			END IF;
			<<output>>
				dbms_output.put_line('Grade is: ' ||g);
			RNo := RNo +1;
			IF RNo>5 THEN EXIT;
				END IF;
			
		END LOOP;
		
END;
/
Grade is: D
Grade is: C
Grade is: F
Grade is: B
Grade is: A+

PL/SQL procedure successfully completed.

---9. Extend lab exercise 5 to validate the GPA value used to find letter grade. If it is
--outside the range, 0 – 10, display an error message, ‘Out of Range’ via an
--exception handler.

declare
			OutOfRange EXCEPTION;
			RNo studenttable.RollNo%TYPE;
			stu_gpa studenttable.GPA%TYPE;
begin 
		RNo :=1;
		WHILE RNo<6
		  LOOP
			select GPA into stu_gpa from StudentTable where RollNo=RNo;
			if stu_gpa > 0 and stu_gpa<=4 THEN
				update studenttable set lettergrade ='F' where RollNo=RNo;
			ELSIF stu_gpa>4 and stu_gpa<=5 THEN
				update studenttable set lettergrade ='E' where RollNo=RNo;
			ELSIF stu_gpa >5 and stu_gpa<=6 THEN
				update studenttable set lettergrade ='D' where RollNo=RNo;
			ELSIF stu_gpa>6 and stu_gpa<=7 THEN
				update studenttable set lettergrade ='C' where RollNo=RNo;
			ELSIF stu_gpa>7 and stu_gpa <=8 THEN
				update studenttable set lettergrade ='B' where RollNo=RNo;
			ELSIF stu_gpa>8 and stu_gpa<=9 THEN
				update studenttable set lettergrade ='A' where RollNo=RNo;
			ELSIF stu_gpa>9 and stu_gpa <=10 THEN
				update studenttable set lettergrade ='A+' where RollNo=RNo;
			ELSE
				RAISE OutOfRange;
			END IF;
				RNo := RNo +1;
		  END LOOP;
EXCEPTION 
				WHEN OutOfRange THEN 
					dbms_output.put_line('Out of Range');
				WHEN OTHERS THEN
					dbms_output.put_line('Error');
					
END;
/

			
PL/SQL procedure successfully completed.

