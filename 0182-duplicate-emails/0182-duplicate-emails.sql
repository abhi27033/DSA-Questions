# Write your MySQL query statement below
select distinct(p.email) as Email from Person p inner join Person s on p.email=s.email and p.id!=s.id;
