---1.union
 SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009
  2  UNION
  3  SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;

COURSE_I
--------
CS-101
CS-315
CS-319
CS-347
FIN-201
HIS-351
MU-199
PHY-101

8 rows selected.

--2.
 SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009
  2  INTERSECT
  3  SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;

COURSE_I
--------
CS-101

--3.
> SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009
  2  MINUS
  3  SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;

COURSE_I
--------
CS-347
PHY-101

--4.
select course_id from course
  2  minus
  3  select course_id from takes;

COURSE_I
--------
BIO-399
--5.
 select distinct course_id from takes where semester ='Fall' and year = 2009 and
  2  course_id in
  3  (select course_id from takes where semester ='Spring' and year = 2010);

COURSE_I
--------
CS-101

--6.

 SELECT COUNT(UNIQUE takes.id) FROM takes WHERE takes.course_id IN (SELECT teaches.course_id FROM teaches WHERE teaches.ID = '10101');

COUNT(UNIQUETAKES.ID)
---------------------
                    6
					
--7. 
 select distinct course_id from takes where semester ='Fall' and year = 2009 and
  2  course_id not in
  3  (select course_id from takes where semester ='Spring' and year = 2010);

COURSE_I
--------
CS-347
PHY-101