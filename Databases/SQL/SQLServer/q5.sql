select Country, City, count(Employee_ID) as Number_Of_Employees
from employee_addresses
group by Country, City
order by Country, City asc;
