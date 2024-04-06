with t1 as (select c.id as id, c.name as name from Customers c inner join Orders o on c.id=o.customerId)
select c.name as Customers from Customers c left join t1 on c.id=t1.id where t1.id is null; 