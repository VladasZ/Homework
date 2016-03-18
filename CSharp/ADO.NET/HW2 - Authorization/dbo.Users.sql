CREATE TABLE [dbo].[Users]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [userName] VARCHAR(50) NULL, 
    [password] VARCHAR(10) NULL, 
    [firstName] VARCHAR(10) NULL, 
    [lastName] VARCHAR(10) NULL, 
    [photoURL] VARCHAR(10) NULL
)
