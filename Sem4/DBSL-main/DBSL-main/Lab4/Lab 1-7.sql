--Group By:
--1. Find the number of students in each course.
 select count(id), course_id from takes group by course_id;

 COUNT(ID) COURSE_I
---------- --------
         1 FIN-201
         2 CS-190
         1 MU-199
         7 CS-101
         1 HIS-351
         2 CS-319
         2 CS-347
         1 PHY-101
         1 EE-181
         2 CS-315
         1 BIO-101

 COUNT(ID) COURSE_I
---------- --------
         1 BIO-301

12 rows selected.
--2. Find those departments where the average number of students are greater than 10.
select dept_name, count(distinct id)
  2  from department natural join course c, takes t
  3  where t.course_id= c.course_id
  4  group by dept_name
  5  having count(distinct id) >10;

no rows selected

--3. Find the total number of courses in each department.
 select dept_name, count(distinct course_id) as No_of_courses
  2  from course
  3  group by dept_name;

DEPT_NAME            NO_OF_COURSES
-------------------- -------------
Comp. Sci.                       5
Biology                          3
History                          1
Elec. Eng.                       1
Finance                          1
Music                            1
Physics                          1

7 rows selected.
--4. Find the names and average salaries of all departments whose average salary is
--greater than 42000.
select dept_name, avg(salary)
  2  from instructor
  3  group by dept_name
  4  having avg(salary)>42000;

DEPT_NAME            AVG(SALARY)
-------------------- -----------
Comp. Sci.            77333.3333
Biology                    72000
History                    61000
Finance                    85000
Elec. Eng.                 80000
Physics                    91000

6 rows selected.
--5. Find the enrolment of each section that was offered in Spring 2009.
select count(id), sec_id from section natural join takes where semester = 'Spring' and year = 2009 group by sec_id;

 COUNT(ID) SEC_ID
---------- --------
         2 2
         1 1
--Ordering the display of Tuples (Use ORDER BY ASC/DESC):

--6. List all the courses with prerequisite courses, then display course id in increasing
--order.
 select course_id, prereq_id from prereq order by course_id;

COURSE_I PREREQ_I
-------- --------
BIO-301  BIO-101
BIO-399  BIO-101
CS-190   CS-101
CS-315   CS-101
CS-319   CS-101
CS-347   CS-101
EE-181   PHY-101

7 rows selected.
--7. Display the details of instructors sorting the salary in decreasing order. 
selselect * from instructor order by salary desc;

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
22222 Einstein             Physics                   95000
83821 Brandt               Comp. Sci.                92000
12121 Wu                   Finance                   90000
33456 Gold                 Physics                   87000
98345 Kim                  Elec. Eng.                80000
76543 Singh                Finance                   80000
45565 Katz                 Comp. Sci.                75000
76766 Crick                Biology                   72000
10101 Srinivasan           Comp. Sci.                65000
58583 Califieri            History                   62000
32343 El Said              History                   60000

ID    NAME                 DEPT_NAME                SALARY
----- -------------------- -------------------- ----------
15151 Mozart               Music                     40000

12 rows selected.