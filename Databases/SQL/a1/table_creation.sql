create table customer(
	no int,
	Customer_ID int,
	Country varchar(2),
	Gender varchar(1),
	Personal_ID int,
	Customer_Name varchar(50),
	Customer_FirstName varchar(25),
	Customer_LastName varchar(25),
	Birth_Date DATE,
	Customer_Address varchar(50),
	Street_ID bigint,
	Street_Number int,
	Customer_Type_ID int
);

create table employee_addresses(
	no int,
	Employee_ID int,
	Employee_Name varchar(50),
	Street_ID bigint,
	Street_Number int,
	Street_Name varchar(50),
	City varchar(50),
	State varchar(2),
	Postal_Code int,
	Country varchar(2)
);

create table employee_donations(
	no int,
	Employee_ID int,
	Qtr1 smallint,
	Qtr2 smallint,
	Qtr3 smallint,
	Qtr4 smallint,
	Recipients varchar(200),
	Paid_By varchar(30)
);

create table employee_payroll(
	no int,
	Employee_ID int,
	Employee_Gender varchar(1),
	Salary int,
	Birth_Date date,
	Employee_Hire_Date date,
	Employee_Term_Date date,
	Marital_Status varchar(1),
	Dependents smallint
);

create table order_fact(
	no int,
	Customer_ID int,
	Employee_ID bigint,
	Street_ID bigint,
	Order_Date date,
	Delivery_Date date,
	Order_ID bigint,
	Order_Type smallint,
	Product_ID bigint,
	Quantity smallint,
	Total_Retail_Price float,
	CostPrice_Per_Unit float,
	Discount varchar(3)
);

create table product_dim(
	no int,
	Product_ID bigint,
	Product_Line varchar(50),
	Product_Category varchar(50),
	Product_Group varchar(50),
	Product_Name varchar(100),
	Supplier_Country varchar(2),
	Supplier_Name varchar(50),
	Supplier_ID int
);

create table staff(
	no int,
	Employee_ID int,
	Start_Date date,
	End_Date date,
	Job_Title varchar(50),
	Salary decimal(7, 2),
	Gender varchar(1),
	Birth_Date date,
	Emp_Hire_Date date,
	Emp_Term_Date date,
	Manager_ID int
);
