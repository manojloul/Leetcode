# Write your MySQL query statement below
# select s1.salary as SecondHighestSalary from Employee s1
# where 2=(select count(s2.salary) from Employee s2 where s2.salary>=s1.salary)

Select Max(salary) as SecondHighestSalary from Employee
where salary NOT IN (select Max(salary) from Employee)