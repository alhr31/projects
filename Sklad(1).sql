/*
Created: 27.11.2018
Modified: 28.11.2018
Model: Logical model
Database: MS SQL Server 2014
*/


-- Create tables section -------------------------------------------------

-- Table Ed Izm

CREATE TABLE [Ed Izm]
(
 [ID Ed Izm] Int IDENTITY(1,1) NOT NULL,
 [Ed Izm] Varchar(15) NOT NULL
)
go

-- Add keys for table Ed Izm

ALTER TABLE [Ed Izm] ADD CONSTRAINT [Unique_Identifier1] PRIMARY KEY ([ID Ed Izm])
go

-- Table Postavshik

CREATE TABLE [Postavshik]
(
 [ID Postavshika] Int IDENTITY(1,1) NOT NULL,
 [Name P] Varchar(100) NOT NULL,
 [Adres P] Varchar(100) NOT NULL,
 [Number TL P] Varchar(14) NOT NULL
)
go

-- Add keys for table Postavshik

ALTER TABLE [Postavshik] ADD CONSTRAINT [Unique_Identifier2] PRIMARY KEY ([ID Postavshika])
go

-- Table Postavka

CREATE TABLE [Postavka]
(
 [ID Postavki] Int IDENTITY(1,1) NOT NULL,
 [Prise P] Float NOT NULL,
 [Count P] Int NOT NULL,
 [Data P] Varchar(30) NOT NULL,
 [Summa P] Float NOT NULL,
 [ID Tovara] Int NOT NULL,
 [ID Ed Izm] Int NOT NULL,
 [ID Postavshika] Int NOT NULL
)
go

-- Add keys for table Postavka

ALTER TABLE [Postavka] ADD CONSTRAINT [Unique_Identifier3] PRIMARY KEY ([ID Postavki],[ID Tovara],[ID Ed Izm],[ID Postavshika])
go

-- Table Tovar

CREATE TABLE [Tovar]
(
 [ID Tovara] Int IDENTITY(1,1) NOT NULL,
 [Name] Varchar(30) NOT NULL,
 [ID Ed Izm] Int NOT NULL
)
go

-- Add keys for table Tovar

ALTER TABLE [Tovar] ADD CONSTRAINT [Unique_Identifier4] PRIMARY KEY ([ID Tovara],[ID Ed Izm])
go

-- Table Klienti

CREATE TABLE [Klienti]
(
 [ID Klienta] Int IDENTITY(1,1) NOT NULL,
 [Name PR] Varchar(100) NOT NULL,
 [Adres PR] Varchar(100) NOT NULL,
 [Number TL PR] Varchar(14) NOT NULL
)
go

-- Add keys for table Klienti

ALTER TABLE [Klienti] ADD CONSTRAINT [Unique_Identifier5] PRIMARY KEY ([ID Klienta])
go

-- Table Sklad

CREATE TABLE [Sklad]
(
 [ID Tovara Na Sklade] Int IDENTITY(1,1) NOT NULL,
 [Count Na Sklade] Int NOT NULL,
 [ID Tovara] Int NOT NULL,
 [ID Ed Izm] Int NOT NULL
)
go

-- Add keys for table Sklad

ALTER TABLE [Sklad] ADD CONSTRAINT [Unique_Identifier6] PRIMARY KEY ([ID Tovara Na Sklade],[ID Tovara],[ID Ed Izm])
go

-- Table Prodaji

CREATE TABLE [Prodaji]
(
 [ID Prodaji] Int IDENTITY(1,1) NOT NULL,
 [Prise PR] Float NOT NULL,
 [Count PR] Int NOT NULL,
 [Data PR] Varchar(30) NOT NULL,
 [Summa PR] Float NOT NULL,
 [ID Tovara] Int NOT NULL,
 [ID Ed Izm] Int NOT NULL,
 [ID Klienta] Int NOT NULL
)
go

-- Add keys for table Prodaji

ALTER TABLE [Prodaji] ADD CONSTRAINT [Unique_Identifier7] PRIMARY KEY ([ID Prodaji],[ID Tovara],[ID Ed Izm],[ID Klienta])
go

-- Create foreign keys (relationships) section ------------------------------------------------- 


ALTER TABLE [Tovar] ADD CONSTRAINT [Relationship1] FOREIGN KEY ([ID Ed Izm]) REFERENCES [Ed Izm] ([ID Ed Izm]) ON UPDATE CASCADE ON DELETE CASCADE
go


ALTER TABLE [Sklad] ADD CONSTRAINT [Relationship2] FOREIGN KEY ([ID Tovara], [ID Ed Izm]) REFERENCES [Tovar] ([ID Tovara], [ID Ed Izm]) ON UPDATE CASCADE ON DELETE NO ACTION
go


ALTER TABLE [Postavka] ADD CONSTRAINT [Relationship3] FOREIGN KEY ([ID Tovara], [ID Ed Izm]) REFERENCES [Tovar] ([ID Tovara], [ID Ed Izm]) ON UPDATE CASCADE ON DELETE NO ACTION
go


ALTER TABLE [Prodaji] ADD CONSTRAINT [Relationship4] FOREIGN KEY ([ID Tovara], [ID Ed Izm]) REFERENCES [Tovar] ([ID Tovara], [ID Ed Izm]) ON UPDATE CASCADE ON DELETE NO ACTION
go


ALTER TABLE [Prodaji] ADD CONSTRAINT [Relationship5] FOREIGN KEY ([ID Klienta]) REFERENCES [Klienti] ([ID Klienta]) ON UPDATE CASCADE ON DELETE CASCADE
go


ALTER TABLE [Postavka] ADD CONSTRAINT [Relationship6] FOREIGN KEY ([ID Postavshika]) REFERENCES [Postavshik] ([ID Postavshika]) ON UPDATE CASCADE ON DELETE CASCADE
go
INSERT INTO [Ed Izm] ([Ed Izm]) Values ('кг')
INSERT INTO [Ed Izm] ([Ed Izm]) Values ('шт')
INSERT INTO [Ed Izm] ([Ed Izm]) Values ('л')
INSERT INTO [Ed Izm] ([Ed Izm]) Values ('м')
