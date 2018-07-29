select p.Product_ID, p.Product_Name, sum(o.Quantity) as Total_Sold
from product_dim as p
inner join order_fact as o on p.Product_ID = o.Product_ID
group by p.Product_ID, p.Product_Name
order by Total_Sold desc, p.Product_Name asc;
