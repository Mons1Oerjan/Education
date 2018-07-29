select c.Customer_Name as Name, count(o.Customer_ID) as Purchases
from product_dim as p
inner join order_fact as o on p.Product_ID = o.Product_ID
inner join customer as c on o.Customer_ID = c.Customer_ID
where 
	o.Employee_ID = 99999999 and 
	c.Country != p.Supplier_Country and
	(c.Country = 'US' or c.Country = 'AU')
group by o.Customer_ID, Customer_Name
order by Purchases desc, Name asc;
