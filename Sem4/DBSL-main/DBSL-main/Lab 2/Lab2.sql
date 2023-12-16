 1.
 create table Employee(
    EmpNo NUMBER(5) PRIMARY KEY,
    EmpName VARCHAR(50) NOT NULL,
    Gender VARCHAR(2) NOT NULL CHECK(Gender='F' OR Gender='M'),
    Salary NUMBER(10) NOT NULL,
    Address VARCHAR(50) NOT NULL,
   DNo NUMBER(10));
  
  2.
   create table Department(
   DeptNo NUMBER(10) PRIMARY KEY,
   DeptName VARCHAR(50) UNIQUE,
   Location VARCHAR(50));
  
  3.
  alter table Employee add constraint FK_DNO FOREIGN KEY(DNO) references Department(DeptNo);
  
  4.
   insert into Department values(1,'Development','karnatka');
   insert into Department values(2,'operations','karnatka');
    insert into Department values(3,'administration','karnatka');
	
	insert into Employee values(1,'Emp1','F',10000,'Manipal',1);

1 row created.

SQL> insert into Employee values(2,'Emp2','M',10000,'Manipal',2);

1 row created.

SQL> insert into Employee values(3,'Emp3','F',10000,'Manipal',3);

5.
insert into Employee values(4,'Emp4','N',10000,'Manipal',5);
insert into Employee values(4,'Emp4','N',10000,'Manipal',5)
*
ERROR at line 1:
ORA-02290: check constraint (F04.SYS_C0016074) violated

insert into department values(1,'Development','assam');
insert into department values(1,'Development','assam')
*
ERROR at line 1:
ORA-00001: unique constraint (F04.SYS_C0016054) violated

6.
 insert into department values(4,'Devops', 'assam');

1 row created.

delete from department where deptno in (Select DNO from employee
  2  group by Dno
  3  having count(*)>1);

0 rows deleted.
7.
> alter table employee drop constraint FK_DNO;

Table altered.

SQL> alter table employee add constraint FK_DNO FOREIGN KEY(DNO) references Department(DeptNo) ON DELETE CASCADE;

8.

 alter table Employee modify(SALARY DEFAULT 10000);

Table altered.

SQL> insert into Employee values(101,'Emp4','F',DEFAULT,'Manipal',3);

1 row created.

9.---List all Students with names and their department names.---

 select Name,Dept_Name from Student;

NAME                 DEPT_NAME
-------------------- --------------------
Zhang                Comp. Sci.
Shankar              Comp. Sci.
Brandt               History
Chavez               Finance
Peltier              Physics
Levy                 Physics
Williams             Comp. Sci.
Sanchez              Music
Snow                 Physics
Brown                Comp. Sci.
Aoi                  Elec. Eng.

NAME                 DEPT_NAME
-------------------- --------------------
Bourikas             Elec. Eng.
Tanaka               Biology

13 rows selected.

10.---10. List all instructors in CSE department---

 select name from instructor
  2  where dept_name = 'Comp. Sci.';

NAME
--------------------
Srinivasan
Katz
Brandt

11.--. Find the names of courses in CSE department which have 3 credits.---

 select title from course
  2  where dept_name='Comp. Sci.' and credits=3;

TITLE
--------------------------------------------------
Robotics
Image Processing
Database System Concepts

13.---List all the instructors whose salary is in between 40000 and 90000.---


select name from instructor
  2  where salary between 40000 and 90000;

NAME
--------------------
Srinivasan
Wu
Mozart
El Said
Gold
Katz
Califieri
Singh
Crick
Kim

10 rows selected.

18.---Find the names of all instructors whose department name includes the substring
‘ch’. ---

select name from instructor where dept_name like '%ch%';
no rows selected

19.--List the student names along with the length of the student names--

 select name,length(name) from student;

NAME                 LENGTH(NAME)
-------------------- ------------
Zhang                           5
Shankar                         7
Brandt                          6
Chavez                          6
Peltier                         7
Levy                            4
Williams                        8
Sanchez                         7
Snow                            4
Brown                           5
Aoi                             3

NAME                 LENGTH(NAME)
-------------------- ------------
Bourikas                        8
Tanaka                          6

13 rows selected.

20.--List the department names and 3 characters from 3rd position of each department name--
select SUBSTR(dept_name,3,3) from department;

SUBSTR(DEPT_
------------
olo
mp.
ec.
nan
sto
sic
ysi

7 rows selected.

21.---List the instructor names in upper case---

select UPPER(Name) from instructor;

UPPER(NAME)
--------------------
SRINIVASAN
WU
MOZART
EINSTEIN
EL SAID
GOLD
KATZ
CALIFIERI
SINGH
CRICK
BRANDT

UPPER(NAME)
--------------------
KIM

12 rows selected.

22.---Replace NULL with value1(say 0) for a column in any of the table ---

 select
  2  NVL(Building, 'bldg1')
  3  from section;

NVL(BUILDING,'B
---------------
Painter
Painter
Packard
Packard
Taylor
Taylor
Watson
Watson
Taylor
Taylor
Taylor

NVL(BUILDING,'B
---------------
Packard
Painter
Packard
Watson

15 rows selected.

23.--- Display the salary and salary/3 rounded to nearest hundred from Instructor.--
  select salary, ROUND(Salary/3,-2) as new_salary
  2  from instructor;

    SALARY NEW_SALARY
---------- ----------
     65000      21700
     90000      30000
     40000      13300
     95000      31700
     60000      20000
     87000      29000
     75000      25000
     62000      20700
     80000      26700
     72000      24000
     92000      30700

    SALARY NEW_SALARY
---------- ----------
     80000      26700

12 rows selected.
24. --Display the birth date of all the employees in the following format:
 ‘DD-MON-YYYY’
 ‘DD-MON-YY’
 ‘DD-MM-YY’---

select to_char(DOB,'DD-MON-YYYY') from employee;

TO_CHAR(DOB,'DD-MON-
--------------------
03-MAR-2003
02-MAR-2003
02-JAN-2003

select to_char(DOB,'DD-MON-YY') from employee;

TO_CHAR(DOB,'DD-MO
------------------
03-MAR-03
02-MAR-03
02-JAN-03

select to_char(DOB,'DD-MM-YY') from employee;

TO_CHAR(
--------
03-03-03
02-03-03
02-01-03


25. List the employee names and the year (fully spelled out) in which they are born
 ‘YEAR’
 ‘Year’
 ‘year’

select empname, to_char(DOB, 'YEAR') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'YEAR')
------------------------------------------
Emp1
TWO THOUSAND THREE

Emp2
TWO THOUSAND THREE

Emp3
TWO THOUSAND THREE

select empname, to_char(DOB, 'Year') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'YEAR')
------------------------------------------
Emp1
Two Thousand Three

Emp2
Two Thousand Three

Emp3
Two Thousand Three

 select empname, to_char(DOB, 'year') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'YEAR')
------------------------------------------
Emp1
two thousand three

Emp2
two thousand three

Emp3
two thousand three

26. List the employee names and the day of the week (fully spelled out) in which they are
born
 ‘DAY’

 ‘Day’

select empname, to_char(DOB, 'DAY') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'DAY')
------------------------------------
Emp1
MONDAY

Emp2
SUNDAY

Emp3
THURSDAY


SQL> select empname, to_char(DOB, 'Day') from employee;

EMPNAME
--------------------------------------------------
TO_CHAR(DOB,'DAY')
------------------------------------
Emp1
Monday

Emp2
Sunday

Emp3
Thursday


27. List the employee names and the month(fully spelled out) in which they are born
 ‘MONTH’
 ‘Month’

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

