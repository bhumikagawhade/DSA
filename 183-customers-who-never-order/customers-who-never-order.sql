# Write your MySQL query statement below
SELECT Name AS Customers
FROM Customers as c
LEFT JOIN 
orders as o 
ON c.id = o.customerID
where o.customerID IS NULL;
