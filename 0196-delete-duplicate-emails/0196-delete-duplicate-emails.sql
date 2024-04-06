# Write your MySQL query statement below
delete p from Person p inner join Person pp on p.email=pp.email where p.id>pp.id and p.email=pp.email;