# Write your MySQL query statement belowi INT

select s1.score, (select count(distinct(s2.score)) from Scores s2 where s2.score>=s1.score) as 'Rank'
from Scores s1
Order by score DESC 