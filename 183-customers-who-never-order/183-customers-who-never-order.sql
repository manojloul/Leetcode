# Write your MySQL query statement below

select Customers.name as Customers from Customers
where Customers.id not In(
 select customerId from Orders
)

