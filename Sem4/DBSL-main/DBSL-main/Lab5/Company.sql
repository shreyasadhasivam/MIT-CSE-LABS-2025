CREATE DATABASE COMPANY;-- It creates a new database
USE COMPANY;            -- It selects the database

-- It creates a table named EMPLOYEE
CREATE TABLE EMPLOYEE
(
    Fname     VARCHAR(15) NOT NULL,
    Minit     CHAR, 
    Lname     VARCHAR(15) NOT NULL,
    Ssn       CHAR(9)     NOT NULL,
    Bdate     DATE,
    Address   VARCHAR(30),
    Sex       CHAR,
    Salary    DECIMAL(10,2),
    Super_ssn CHAR(9),
    Dno       INT         NOT NULL,
    PRIMARY KEY (Ssn)    
);

-- The following script creates a new table named DEPARTMENT
CREATE TABLE DEPARTMENT
(
    Dname          VARCHAR(15) NOT NULL,
    Dnumber        INT         NOT NULL,
    Mgr_ssn        CHAR(9)     NOT NULL,
    Mgr_start_date DATE,
    PRIMARY KEY (Dnumber),
    UNIQUE (Dname),
    FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE1(Ssn)
);

-- The following script creates a new table named DEPT_LOCATIONS
CREATE TABLE DEPT_LOCATIONS
(
    Dnumber   INT         NOT NULL,
    Dlocation VARCHAR(15) NOT NULL,
    PRIMARY KEY (Dnumber, Dlocation),
    FOREIGN key (Dnumber) REFERENCES DEPARTMENT1 (Dnumber)
);

-- The following script creates a new table named PROJECT
CREATE TABLE PROJECT
(
    Pname     VARCHAR(15) NOT NULL,
    Pnumber   INT         NOT NULL,
    Plocation VARCHAR(15),
    Dnum      INT         NOT NULL,
    PRIMARY KEY(Pnumber),
    UNIQUE(Pname),
    FOREIGN KEY(Dnum) REFERENCES EDEPARTMENT(Dnumber)
);

-- The following script creates a new table named WORKS_ON
CREATE TABLE WORKS_ON
(
    Essn  CHAR(9)      NOT NULL,
    Pno   INT          NOT NULL,
    Hours DECIMAL(3,1) NOT NULL,
    PRIMARY KEY(Essn, Pno),
    FOREIGN KEY(Essn) REFERENCES EMPLOYEE(Ssn),
    FOREIGN KEY(Pno)  REFERENCES PROJECT(Pnumber)
);

-- The following script creates a new table named DEPENDENT
CREATE TABLE DEPENDENT
(
    Essn           CHAR(9)     NOT NULL,
    Dependent_name VARCHAR(15) NOT NULL,
    Sex            CHAR,
    Bdate          DATE,
    Relationship   VARCHAR(8),
    PRIMARY KEY(Essn, Dependent_name),
    FOREIGN KEY(Essn) REFERENCES EMPLOYEE(Ssn)
);

-- **********************************************************************************************
-- INSERT operations

-- The following script adds a new tuple to the EMPLOYEE relation
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES ('Richard', 'K', 'Marini', '653298653', '30-dec-1962', '98 Oak Forest, Katy, TX', 'M', 37000, '653298653', 4);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('John', 'B', 'Smith', '123456789', '09-jan-1965', '731 Fondren, Houston, TX', 'M', 30000, '333445555', 5);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('Franklin', 'T', 'Wong', '333445555', '08-dec-1965', '638 Voss, Houston, TX', 'M', 40000, '888665555', 5);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('Alicia', 'J', 'Zelaya', '999887777', '19-jan-1968', '3321 Castle, Spring, TX', 'F', 25000, '987654321', 4);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('Jennifer', 'S', 'Wallace', '987654321', '20-jun-1941', '291 Berry, Bellaire, TX', 'F', 43000, '888665555', 4);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('Ramesh', 'K', 'Narayan', '666884444', '15-sep-1962', '975 Fire Oak, Humble, TX', 'M', 38000, '333445555', 5);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('Joyce', 'A', 'English', '453453453', '31-jul-1972', '5631 Rice, Houston, TX', 'F', 25000, '333445555', 5);
 INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES       ('Ahmad', 'V', 'Jabbar', '987987987', '29-mar-1969', '980 Dallas, Houston, TX', 'M', 25000, '987654321', 4);
INSERT INTO EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) 
VALUES        ('James', 'E', 'Borg', '888665555', '10-nov-1937', '450 Stone, Houston, TX', 'M', 55000, NULL, 4);


-- The following script adds a new tuple to the DEPARTMENT relation
INSERT INTO EDEPARTMENT
VALUES ('Research', 5, '333445555', '22-may-1988');
   INSERT INTO EDEPARTMENT
VALUES    ('Administration', 4, '987654321', '01-jan-1995');
INSERT INTO EDEPARTMENT
VALUES       ('Headquarters', 1, '888665555', '19-jun-1981');

-- The following script adds a new tuple to the DEPT_LOCATIONS relation
INSERT INTO DEPT_LOCATIONS
VALUES (1, 'Houston');
INSERT INTO DEPT_LOCATIONS
VALUES       (4, 'Stafford');
INSERT INTO DEPT_LOCATIONS
VALUES       (5, 'Bellaire');
INSERT INTO DEPT_LOCATIONS
VALUES       (5, 'Sugarland');
INSERT INTO DEPT_LOCATIONS
VALUES       (5, 'Houston');

-- The following script adds a new tuple to the PROJECT relation
INSERT INTO PROJECT
VALUES ('ProductX', 1,' Bellaire', 5);
INSERT INTO PROJECT
VALUES       ('ProductY', 2, 'Sugarland', 5);
INSERT INTO PROJECT
VALUES       ('ProductZ', 3, 'Houston', 5);
INSERT INTO PROJECT
VALUES       ('Computerization', 10, 'Stafford', 4);
INSERT INTO PROJECT
VALUES       ('Reorganization', 20, 'Houston', 1);
INSERT INTO PROJECT
VALUES       ('Newbenefits', 30, 'Starfford', 4);

-- The following script adds a new tuple to the WORKS_ON relation
INSERT INTO WORKS_ON 
VALUES ('123456789', 1, 32.5);
INSERT INTO WORKS_ON 
VALUES       ('123456789', 2, 7.5);
INSERT INTO WORKS_ON 
VALUES       ('666884444', 3, 40.0);
 INSERT INTO WORKS_ON 
VALUES      ('453453453', 1, 20.0);
 INSERT INTO WORKS_ON 
VALUES      ('453453453', 2, 20.0);
  INSERT INTO WORKS_ON 
VALUES     ('333445555', 2, 10.0);
INSERT INTO WORKS_ON 
VALUES       ('333445555', 3, 10.0);
  INSERT INTO WORKS_ON 
VALUES     ('333445555', 10, 10.0);
INSERT INTO WORKS_ON 
VALUES       ('333445555', 20, 10.0);
INSERT INTO WORKS_ON 
VALUES       ('999887777', 30, 30.0);
INSERT INTO WORKS_ON 
VALUES       ('999887777', 10, 10.0);
INSERT INTO WORKS_ON 
VALUES       ('987987987', 10, 35.0);
INSERT INTO WORKS_ON 
VALUES       ('987987987', 30, 5.0);
 INSERT INTO WORKS_ON 
VALUES      ('987654321', 30, 20.0);
INSERT INTO WORKS_ON 
VALUES       ('987654321', 20, 15.0);
 INSERT INTO WORKS_ON 
VALUES      ('888665555', 20, 0);

-- The following script adds a new tuple to the DEPENDENT relation
INSERT INTO DEPENDENT
VALUES ('333445555', 'Alice', 'F', '05-apr-1986', 'Daughter');
  INSERT INTO DEPENDENT
VALUES     ('333445555', 'Theodore', 'M', '25-oct-1983', 'Son');
 INSERT INTO DEPENDENT
VALUES      ('333445555', 'Joy', 'F', '03-may-1958', 'Spouse');
  INSERT INTO DEPENDENT
VALUES     ('987654321', 'Abner', 'M', '28-feb-1942', 'Spouse');
     INSERT INTO DEPENDENT
VALUES  ('123456789', 'Michael', 'M', '04-jan-1988', 'Son');
   INSERT INTO DEPENDENT
VALUES    ('123456789', 'Alice', 'F', '30-dec-1988', 'Daughter');
 INSERT INTO DEPENDENT
VALUES      ('123456789', 'Elizabeth', 'F', '05-may-1967', 'Spouse');

-- *********************************************************************************************************
-- Basic queries to test the tables

SELECT * FROM EMPLOYEE;
SELECT * FROM DEPARTMENT;
SELECT * FROM DEPT_LOCATIONS;
SELECT * FROM PROJECT;
SELECT * FROM WORKS_ON;
SELECT * FROM DEPENDENT;