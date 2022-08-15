# Write your MySQL query statement below
# select d.name as Department ,e1.name as Employee , max(e1.salary) from Employee e1  left join Department d on e1.departmentId=d.id group by departmentId order by d.name

select d.name as Department ,e1.name as Employee , e1.salary from Employee e1  left join
Department d on e1.departmentId=d.id where (e1.departmentId , e1.salary) in
(select departmentId,max(salary) from Employee group by DepartmentId)