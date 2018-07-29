select
	Country,
	count(Customer_ID) as Total_Customers,
	count(case when Gender = 'M' then 1 end) as Total_Male_Customers,
	count(case when Gender = 'F' then 1 end) as Total_Female_Customers,
	convert(
		decimal(5, 2),
		(100 * convert(float, count(case when Gender = 'M' then 1 end)) / convert(float, count(Customer_ID))))
	as Percent_Male_Customers
from customer
group by Country
order by Country asc;
