# Write your MySQL query statement below
SELECT uni.unique_id, n.name
FROM Employees n
LEFT JOIN EmployeeUNI uni
ON uni.id=n.id;