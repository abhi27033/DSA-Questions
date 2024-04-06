# Write your MySQL query statement below
select ww.id as Id from Weather w inner join Weather ww on datediff(ww.recordDate,w.recordDate)=1 where w.temperature<ww.temperature;