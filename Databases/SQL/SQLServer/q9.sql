select 
	s.Employee_ID,
	trainee.Employee_Name,
	s.Job_Title,
	s.Manager_ID,
	worker.Employee_Name as Manager_Name
from staff as s
inner join employee_addresses as trainee on s.Employee_ID = trainee.Employee_ID
inner join employee_addresses as worker on s.Manager_ID = worker.Employee_ID
where s.Job_Title like 'Trainee'
order by s.Employee_ID;
