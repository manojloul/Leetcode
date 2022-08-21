# Write your MySQL query statement below
select name from SalesPerson where name not in(
select s.name from SalesPerson s where
s.sales_id in ( select o.sales_id from Orders o where o.com_id in 
             (select c.com_id from Company c where c.name = "RED")))