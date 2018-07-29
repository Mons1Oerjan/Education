select Employee_ID, Recipients, (Qtr1 + Qtr2 + Qtr3 + Qtr4) as Total
from employee_donations
where (Qtr1 + Qtr2 + Qtr3 + Qtr4) > 90;
