# Write your MySQL query statement below

 select employee_id ,
 CASE
    when employee_id%2<>0 and name not Like 'M%' then salary
    else 0
 end
 as bonus from Employees

