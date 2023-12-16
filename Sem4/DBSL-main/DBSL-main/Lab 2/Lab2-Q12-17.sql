12.--For the student with ID 12345 (or any other value), show all course-id and title of all
--courses registered for by the student.--

  SELECT course_id,title FROM course WHERE course_id IN
  2  (SELECT course_id from takes where id=12345);

COURSE_I TITLE
-------- --------------------------------------------------
CS-101   Intro. to Computer Science
CS-190   Game Design
CS-315   Robotics
CS-347   Database System Concepts


14.--. Display the IDs of all instructors who have never taught a course.



SELECT id from instructor WHERE id NOT in
  2  (SELECT id from teaches);

ID
-----
76543
58583
33456

15. --Find the student names, course names, and the year, for all students those who have
--attended classes in room-number 303.

select name, title, takes.year from student, section, course, takes where room_number = 303 and course.course_id = section.course_id and student.id = takes.id and takes.course_id = course.course_id;

no rows selected
16.-- For all students who have opted courses in 2015, find their names and course id’s
--with the attribute course title replaced by c-name.
 select name, course_id,title as c_name from student, course where student.id in (select student.id from takes where year = 2015);

no rows selected

17. --Find the names of all instructors whose salary is greater than the salary of at least
--one instructor of CSE department and salary replaced by inst-salary
 select distinct t.name from instructor T, instructor S where T.salary>S.salary and S.dept_name='Comp. Sci.';

NAME                 INST_SALARY
-------------------- -----------
Einstein                   95000
Brandt                     92000
Gold                       87000
Singh                      80000
Wu                         90000
Katz                       75000
Crick                      72000
Kim                        80000

8 rows selected.