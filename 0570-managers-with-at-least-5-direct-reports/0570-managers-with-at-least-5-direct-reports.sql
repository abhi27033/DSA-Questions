# SELECT name 
# FROM Employee 
# WHERE id IN (
#     SELECT managerId 
#     FROM Employee 
#     GROUP BY managerId 
#     HAVING COUNT(managerId) >= 5
# );
select name from Employee where id in (select managerId from Employee group by ManagerId having count(ManagerId)>=5);