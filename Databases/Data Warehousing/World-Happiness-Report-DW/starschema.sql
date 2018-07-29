create database datawarehouse;

use datawarehouse;

/* Create fact table */
create table FactHappiness(
	Happiness_ID bigint primary key identity,
	Year_ID int,
	Country_ID int,
	Happiness_Rank int,
	Happiness_Score float,
	Economy_GDP_per_Capita float,
	Family float,
	Health_Life_Expectancy float,
	Freedom float,
	Trust_Government_Corruption float,
	Generosity float,
	Dystopia_Residual float
);

/* Create dimension tables */
create table DimCountry(
	Country_ID int primary key identity,
	Country varchar(100),
	Region varchar(100)
);

create table DimYear(
	Year_ID int primary key identity,
	Year int
);

/* Add relationships between the fact table and dimension tables */
alter table FactHappiness
add constraint FK_Year_ID
foreign key (Year_ID)
references DimYear(Year_ID);

alter table FactHappiness
add constraint FK_Country_ID
foreign key (Country_ID)
references DimCountry(Country_ID);
