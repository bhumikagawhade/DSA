# Write your MySQL query statement below
select email AS Email
from Person
GROUP BY email 
HAVING COUNT(email)>1;

