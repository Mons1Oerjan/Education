select Employee_ID, Salary, (Salary + Salary * 0.04) as Bonus
into bonus
from employee_payroll;
