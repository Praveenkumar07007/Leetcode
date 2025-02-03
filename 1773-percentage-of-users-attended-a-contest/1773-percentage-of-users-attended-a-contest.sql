# Write your MySQL query statement below
select B.contest_id, round((count(A.user_id)/(select count(*) from Users))*100,2) as percentage 
from Users as A
Join
Register as B
on A.user_id=B.user_id
group by B.contest_id
order by percentage DESC, B.contest_id ASC;