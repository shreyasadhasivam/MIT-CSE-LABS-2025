SQL> select bdate, address from employee
  2  where fname ='John' and minit='B' and lname ='Smith';

BDATE     ADDRESS
--------- ------------------------------
09-JAN-65 731 Fondren, Houston, TX

SQL> select fname,minit,lname, address
  2  from employee E, edepartment D
  3  where E.ssn = D.mgr_ssn and DNAME ='Research';

FNAME           M LNAME           ADDRESS
--------------- - --------------- ------------------------------
Franklin        T Wong            638 Voss, Houston, TX

----------Q3--------------
SQL> select distinct salary
  2  from employee;

    SALARY
----------
     55000
     37000
     38000
     30000
     40000
     43000
     25000

7 rows selected.
-------------------------Q4-------------------------
