27. --List the employee names and the month(fully spelled out) in which they are born
 ‘MONTH’
 ‘Month’
---
 select empname,to_char(DOB, 'MONTH') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'MONTH')
------------------------------------
Emp1
MARCH

Emp2
MARCH

Emp3
JANUARY

select empname,to_char(DOB, 'Month') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'MONTH')
------------------------------------
Emp1
March

Emp2
March

Emp3
January