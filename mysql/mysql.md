MySQL入门很简单
==============

## SQL - Structured Query Language	结构化查询语言（Page 5）

1.	DDL - Data Definition Language	数据定义语言

	a)	CREATE	创建数据库、创建表、创建视图
	b)	ALTER	修改表的定义、修改视图的定义
	c)	DROP	删除数据库、删除表、删除视图

2.	DML - Data Manipulation Language	数据操作语言

	a)	INSERT	插入数据
	b)	SELECT	查询数据
	c)	UPDATE	更新数据
	d)	DELETE	删除数据

3.	DCL - Data Control Language		数据控制语言

	a)	GRANT	添加权限
	b)	REVOKE	收回权限

## MySQL数据类型介绍（Page 50）

1.	整形类型 （标准SQL：SMALLINT、INTEGER）AUTO_INCREMENT 自增长

    a)	TINYINT			1字节
    b)	SMALLINT		2字节
    c)	MEDIUMINT		3字节
    d)	INT、INTEGER	4字节
    e)	BIGINT			8字节

2.	浮点、定点数类型

    a)	FLOAT			4字节
    b)	DOUBLE			8字节
    c)	DECIMAL(M,D)	M+2字节
    d)	DEC(M,D)		M+2字节

3.	日期和时间类型

    a)	YEAR			1字节
    b)	DATE			4字节
    c)	TIME			3字节
    d)	DATETIME		8字节
    e)	TIMESTAMP		4字节

4.	字符串类型

    a)	CHAR
    b)	VARCHAR
    c)	TINYTEXT
    d)	TEXT
    e)	MEDIUMTEXT
    f)	LONGTEXT
    g)	EMUN
    h)	SET

5.	二进制数据类型

    a)	BINARY(M)
    b)	VARBINARY(M)
    c)	BIT(M)
    d)	TINYBLOB
    e)	BLOB
    f)	MEDIUMBLOB
    g)	LONGBLOB

## 数据库的操作

```sql
CREATE DATABASE dbname;
DROP DATABASE dbname;
SHOW DATABASES;
```

## 数据库的存储引擎 SHOW ENGINGS\G  SHOS VARIABLES LIKE ‘xxx%’（Page 70）

1.	InnoDB存储引擎

InnoDB 是MySQL数据库的一种存储引擎。InnoDB给MySQL的表提供了事物、回滚、奔溃修复能力和多版本冰法控制的事物安全。MySQL第一个提供外键约束的表引擎。
InnoDB存储引擎中支持自动增长列AUTO_INCREMENT。自动增长列的值不能为空，且必须唯一。MySQL中规定自增长列必须为主键。
InnoDB存储引擎中支持外键（FOREIGEN KEY）。外键所在的表为字表，外键所依赖的表为父表。父表中被字表外键关联的字段必须为主键。当删除、更新父表的某条信息是，字表也必须有相应的改变。
InnoDB存储引擎中个， 创建的表的表结构存储在.frm文件中。数据和索引存储在innodb_data_home_dir和innodb_data_file_path定义的表空间中。
InnoDB存储引擎的优势在于提供了良好的事物管理、崩溃修复能力和并发控制。缺点是其读写效率稍差，占用数据空间相对较大。

2.	MyISAM存储引擎

MyISAM存储引擎是MySQL中常见的存储引擎，曾是MySQL的默认存储引擎。MyISAM存储赢钱是基于ISAM存储引擎发展起来的。MyISAM添加了很多有用的扩展。
MyISAM存储引擎的表存储成3个文件。文件的名字和表名相同。扩展名包括frm、MYD和MYI。其中，frm为扩展名的文件存储表的结构；MYD为扩展名的文件存储数据，其实是MYData的缩写，MYI为扩展名的文件存储存储索引，其是MYIndex的缩写。
基于MyISAM存储引擎的表支持3种不同格式的存储格式。包括镜头型、动态型和压缩型。其中静态型为默认的存储格式，其字段描述是固定长度的；动态型包含变长字段，记录长度不是固定的；压缩型需要使用myisampack工具创建，占用磁盘空间较小。
MyISAM存储引擎的优势在于占用空间小，处理速度快。缺点是不支持事物的完整性和并发性。

3.	MEMORY存储引擎

MEMORY存储引擎是MySQL中的一类特殊的存储引擎。器使用存储在内存中的内容来创建表，而且所有数据也放在内存当中。
每个基于MEMORY存储引擎的表实际对应一个磁盘文件。该文件的文件名于表名相同，类型为frm类型。该文件中只存储表的结构。其数据文件，都是存储在内存中。这样有利于数据的快速处理，提高整个表的处理效率。
MEMORY存储赢钱默认使用哈希（HASH）索引。其速度比使用B型树（BTREE）索引快。
MEMORY表的大小是受限制的。表的大小主要取决于两个参数，分别是max_rows和max_heap_table_size。其中max_heap_table_size的大小默认为16MB，可以按需要进行扩大。因此，其存在于内存中的特性，这类表的处理速度非常快。但是，其数据容易丢失，生命周期短。


## 创建表 (Page 79)

1.	创建表 	CREATE TABLE (首先要选择数据库 use database)

    a)	PRIMARY KEY		主键
    b)	FOREIGN KEY		外键
    c)	NOT NULL 			不为空
    d)	UNIQUE				值唯一
    e)	AUTO_INCREMENT		自增
    f)	DEFAULT				默认值

```sql
CREATE TABLE example0(  id 		INT,
                        name	VARCHAR(20),
                        sex 	BOOLEAN);
```

2.	表的主键

主键是表的一个特殊字段。该字段能唯一地标识该表中的每一条信息。
主键的主要目的是帮助MySQL最快速查到表中的某条信息。主键必须瞒住的条件是主键必须是唯一的，表中任意两条记录的主键字段值不恩呢该相同；主键的值是非空值。主键可以是单一字段，也可以是多个字段的组合。

a)	单子段主键

```sql
CREATE TABLE example1(  stu_id		INT PRIMARY KEY,
						stu_name	VARCHAR(20),
						stu_sex		BOOLEAN);
```

b)	多字段主键

```sql
CRRATE TABLE example2(  stu_id		INT,
						course_id	INT,
						grade		FLOAT,
						PRIMARY KEY(stu_id, course_id));
```

3.	表的外键

外键是表的一个特殊字段。如果字段sno是个表A的属性，且依赖于表B的主键。那么，称表B为父表，表A为子表，sno为表A的外键。通过sno字段将父表B和子表A建立关联关系。设置表的外键指在创建表设置某个字段为外键。
设置外键的原则就是必须依赖于数据库中已经存在的父表的主键；外键可以为空值。
外键的作用就是建立该表于其父表的关联关系。父表中删除某条信息时，子表中与之对应的信息也必须有相应的改变。例如，stu_id是student表的主键，stu_id是grade表的外键。当stu_id为‘123’同学退学了，需要从student表中删除该学生的信息。那么，grade表中stu_id为‘123’的所有信息也应该同时删除。这样可以保证信息的完整性。

```sql
CREATE TABLE example3(  id			INT PRIMARY KEY,
						stu_id 		INT,
						course_id	INT,
					CONSTRAINT c_fk FOREIGN KEY(stu_id, course_id)
						REFERENCES	example2(stu_id, course_id));
```

4.	表的非空约束

非空性是指字段的值不能为空值（NULL）。非空约束将保证所有记录中该字段都有值。如果用户新插入的记录中，该字段为空值，则数据库系统会报错。

```sql
CREATE TABLE example4(  id		INT NOT NULL PRIMARY KEY,
						name 	VARCHAR(20) NOT NULL,
						stu_id	INT,
						CONSTRAINT d_fk FOREIGN KEY(stu_id)
						REFEFENCES example1(stu_id));
```

5.	表的唯一约束

唯一性是指所有记录中该字段的值不能重复出现。设置表的唯一性约束是指在创建表时，为表的某些特殊字段加上UNIQUE约束条件。唯一性约束将保证所有记录中该字段的值不能重复出现。

```sql
CREATE TABLE example5(  id		INT PRIMARY KEY,
						stu_id	INT UNIQUE,
						name 	VARCHAR(20) NOT NULL);
```

6.	设置表的属性自动增加
AUTO_INCREMENT是MySQL数据库中一个特殊的约束条件。其主要用于为表中插入的新纪录自动深处唯一的ID。一个表只能有一个字段使用AUTO_INCREMENT约束，且该字段必须为主键的一部分。AUTO_INCREAMENT约束的字段可以是任何整数类型。默认情况下，该字段是从1开始自增。

```sql
CREATE TABLE example6(  id		INT PRIMARY KEY AUTO_INCREAMENT,
						stu_id	INT UNIQUE,
						name 	VARCHAR(20) NOT NULL);
```

7.	设置表的默认值
在创建表的时候可以指定表中字段的默认值。如果插入一条新的记录没有为这个字段赋值，那么数据库系统会自动为这个字段插入默认值。默认值是通过DEFAULT关键字来设置的。

```sql
CREATE TABLE example7(  int		INT PRIAMRY KEY AUTO_INCREMENT,
						stu_id	INT UNIQUE,
						name 	VARCHAR(20) NOT NULL,
						English VARCHAR(20) DEFAULT ‘zero’,
						Math	FLOAT DEFALUT 0,
						Computer FLOAT DEFAULT 0);
```

## 看查表的结构（Page 82）

1.	DESCRIBE / DESC 看查表的基本结构
2.	SHOW CREATE TABLE 看查表的详细结构

## 修改表 (Page 85)

1.	修改表名	

```sql
ALTER TABLE 旧表名 RENAME 新表名 \g
```

2.	修改字段的数据类型

```sql
ALTER TABLE 表名 MODIFY 属性名 数据类型 \g
```

3.	修改字段名

```sql
ALTER TABLE 表名 CHANGE 旧属性名 新属性名 新数据类型 \g
```

4.	增加字段

```sql
ALTER TALBE 表名 ADD 属1 类型 [完整类型] [FIRST | AFTER 属2];
```

> a)	添加无完整性约束条件的字段
> 
> ```sql
> ALTER TABLE user ADD phone VARCHAR(20);
> ```
> 
> b)	添加有完整性约束条件的字段
> 
> ```sql
> ALTER TABLE user ADD age INT(4) NOT NULL;
> ```
> 
> c)	表的第一个位置添加字段 （FIRST）
> 
> ```sql
> ALTER TABLE user ADD num INT(8) PRIMARY KEY FIRST;
> ```
> 
> d)	表的指定位置之后添加字段
> 
> ```sql
> ALTER TALBE user ADD address VARCHAR(30) NOT NULL AFTER phone;
> ```

5.	删除字段

```sql
ALTER TABLE user DROP id;
```

6.	修改字段的排列位置

```sql
ALTER TABLE user MODIFY sex TINYINT(1) AFTER age;
```

7.	更改表的存储引擎

```sql
ALTER TABLE 表名 ENGINE=存储引擎;
```

8.	删除表的外键约束

```sql
ALTER TABLE 表名 DROP FOREIGN KEY 外键名;
```

## 删除表（Page 98）

1.	删除没有被关联的普通表

```sql
DROP TABLE 表名;
```

2.	删除被其他表关联的父表

> a)	先删除外键约束，然后再删除表
> b)	先删除子表，然后再删除父表


## 索引简介（Page 112）

索引由数据库表中的一列或多列组合而成，其作用是提高对表中数据的查询速度。

1.	索引的含义和特点

索引是创建在表上的，是对数据库表中的一列或多列的值进行排序的一种数据结构。索引可以提高查询速度。
通过索引，查询数据是可以不必读取完记录的所有信息，而只是查询所有列。否则，数据库系统将读取每条记录的所有信息进行匹配。
不同的存储引擎定义了每个表的最大索引数和最大索引长度。所有存储引擎对每个表至少支持16个索引， 总索引长度至少为256字节。有些存储引擎支持更多的索引数和更大的索引长度。索引由两种存储类型，包括B型树（BTREE）索引和哈希（HASH）索引。InnoDB和MyISAM存储索引支持BTREE索引，MEMORY存储引擎支持HASH索引和BTREE索引，默认为前者。
索引可以提高查询速度，但是会影响插入记录的速度。因为，向有索引的表中插入数据时，数据库系统会按照索引进行排序。这样就降低了插入记录的速度，插入大量的数据时影响更加明显，这种情况下，最好的办法是先删除表中的索引，然后插入数据，插入完成后，再创建索引。

2.	索引的分类

> a)	普通索引
> 
> 在创建普通索引时，不附加任何限制条件。这类索引可以创建在任何数据类型中，其值是否唯一和非空由字段本身的完整性约束条件决定。简历索引以后，查询时可以通过索引进行查询。
> 
> b)	唯一性索引
> 
> 使用UNIQUE参数可以设置索引为唯一性索引。在创建唯一性索引时，限制该索引的值必须是唯一的。主键就是一种特殊的唯一性索引。
> c)	全文索引
> 
> 使用FULLTEXT参数可以设置索引为全文索引。全文索引只能创建在CHAR，VARCHAR	或TEXT类型字段上。查询数据量较大的字符串类型的字段时，使用全文索引可以提高查询速度。
> 
> d)	单列索引
> 
> 在表中的单个字段上创建索引。单列索引只根据该字段进行索引。单列索引可以是普通索引，也可以是唯一性所以，还可以是全文索引。只要保证该索引只是对应一个字段即可。
> 
> e)	多列索引
> 
> 多列索引是在表的多个字段上创建索引。该索引指向创建时对应的多个字段，可以通过这几个字段进行查询。但是，只有查询条件中使用了这些字段中的第一个字段时，索引才会被引用。
> 
> f)	空间索引
> 
> 使用SPATIAL参数可以设置索引为空间索引。空间索引只能建立在空间数据类型上，这样可以提高系统获取空间数据的效率。MySQL中的空间数据类型包括GEOMETRY和POINT、LINESTRING和POLYGON等。目前只有MyISAM存储支持空间索引。这类索引很少用到。

3.	索引的设计原则

> a)	选择唯一性索引
> b)	为经常需要排序、分组和联合操作的字段建立索引
> c)	为常作为查询条件的字段建立索引
> d)	限制索引数目
> e)	尽量使用数据量少的索引
> f)	尽量使用前缀来索引
> g)	删除不再使用或者很少使用的索引

## 创建表时创建索引（Page 115）

1.	创建普通索引

```sql
CREATE TABLE index1(id		INT,
					name	VARCHAR(20),
					sex 	BOOLEAN,
					INDEX(id));
```

2.	创建唯一性索引

```sql
CREATE TABLE index2(id		INT UNIQUE,
					name 	VARCHAR(20),
					UNIQUE INDEX index2_id (id ASC));
```
这里的id字段可以没有进行唯一性约束，也可以在该字段上成功创建唯一索引。但是可能达不到提高查询速度的效果。

3.	创建全文索引

```sql
CREATE TABLE index3(id		INT,
					info	VARCHAR(20),
					FULLTEXT INDEX index3_info(info))ENGINE=MyISAM;
```

4.	创建单列索引

```sql
CREATE TABLE index4(id			INT,
					subject		VARCHAR(30),
					INDEX index4_st(subject(10)));
```

5.	创建多列索引

```sql
CREATE TABLE index5(id			INT,
					name		VARCHAR(20),
					sex			CHAR(4),
					INDEX index5_ns(name, sex));
```

6.	创建空间索引(GEOMETRY, POINT, LINESTRING and POLYGON)

```sql
CREATE TABLE index6(id			INT,
					space		GEOMETRY NOT NULL,
					SPATIAL INDEX index6_sp(space))ENGINE=MyISAM;
```

## 在已经存在的表上创建索引（Page 119）

1.	创建普通索引

```sql
CREATE INDEX index7_id ON example0(id);
```

2.	创建唯一性索引

```sql
CREATE UNIQUE INDEX index8_id ON index8(course_id);
```

3.	创建全文索引

```sql
CREATE FULLTEXT INDEX index9_info ON index9(info);
```

4.	创建单列索引

```sql
CREATE INDEX index10_addr ON index10(address(4));
```

5.	创建多列索引

```sql
CREATE INDEX index11_na ON index11(name, address);
```

6.	创建空间索引

```sql
CREATE SPATIAL INDEX index12_line ON index12(line);
```

## 用ALTER TABLE语句来创建索引

1.	创建普通索引

```sql
ALTER TABLE example0 ADD INDEX index13_name(name(20));
```

2.	创建唯一性索引

```sql
ALTER TABLE index14 ADD UNIQUE INDEX index14_id(course_id);
```

3.	创建全文索引

```sql
ALTER TABLE index15 ADD FULLTEXT INDEX index15_info(info);
```

4.	创建单列索引

```sql
ALTER TABLE index16 ADD INDEX index16_addr(address(4));
```

5.	创建多列索引

```sql
ALTER TABLE index17 ADD INDEX index17_na(name, address);
```

6.	创建空间索引

```sql
ALTER TABLE index18 ADD SPATIAL INDEX index18_line(line);
```

## 删除索引（Page 123）

```sql
DROP INDEX 索引名 ON 表名;
```





## 视图（Page 131）
	视图是一种虚拟表，是从数据库中一个或多个表中导出来的表。视图还可以从已经存在的视频的基础上定义。数据库中只存放了视图的定义，而并没有存放视图中的数据。视图中的数据依赖于原来的表中的数据的。一旦表中的数据发生改变，显示在视图中的数据也会发生改变。
	MySQL的视图不支持输入参数的功能，因此交互性上有所欠缺。但对于变化不是很大的操作，使用视图可以很大程度上简化用户操作。

## 视图的作用（Page 132）

1.	使操作简单化

视图需要达到的目的就是所见即所需。视图可以简化对数据的操作。

2.	增加数据的安全性

通过视图，用户只能查询和修改指定数据。指定数据以外的信息，用户根本接触不到。使用视图之后可以将用户的权限限制到特定的行和列上。

3.	提高表的逻辑独立性

视图可以屏蔽原有表结构变化带来的影响。例如，在原有表中添加列和删除未被引用的列对视图不会造成影响。同样，如果修改了表中的某些列，可以试用修改视图来解决这些列带来的影响


## 创建视图（Page 133）

```sql
CREATE [ALGORITHM = {UNDEFINED | MERGE | TEMPTABLE}]
    VIEW 视图名 [(属性清单)]
    AS SELECT 语句
    [WITH  [CASCADED | LOCAL] CHECK OPTION];
```

* ALGORITHM	

可选参数，表示视图选择的算法。包含3个选项UNDEFINED, MERGE和TEMPTABLE。其中UNDEFINED表示MySQL将自动选择所要使用的算法；MERGE选项表示将使用视图的语句于视图定义合并起来，使得视图定义的某一部分取代语句的对应部分；TEMPTABLE选项表示将视图的结果存入临时表，然后使用临时表执行语句。

* 视图名		

创建的视图名称
	
* 属性清单	

可选参数，指定视图中各个属性名词，默认与SELECT语句查询属性相同。
	
## SELECT语句		

完整的查询语句，表示从某个表中查出某些满足条件的记录。
	
WITH CHECK OPTION
可选参数，表示更新视图时要保证在该视图的权限范围之内

* CASCADED

    可选参数，表示更新视图时要满足所有相关视图和表的条件，该参数是默认值；

* LOCAL

    表示更新视图时，要满足该视图本身的定义条件即可。

## 在表单上创建视图（Page 134）

```sql
CREATE VIEW department_view1 AS SELECT * FROM department;
CREATE VIEW department_view2(name, function, location) AS SELECT d_name, function, address FROM department;
```

## 在多表上创建视图（Page 135）

```sql
CREATE ALGORITHM=MERGE VIEW
    worker_view1(name, department, sex, age, address)
    AS SELECT name, department.d_name, sex, 2009-birthday, address
    FROM worker, department WHERE worker.d_id = department.d_id
    WITH LOCAL CHECK OPTION;
```

## 看查视图（Page 136）

```sql
DESCRIBE 视图名;
SHOW TABLE STATUS LIKE ‘表名’;
SHOW CREATE VIEW 视图名;
```
