# Notes
---
- Consider the following relation and FDs:
    1. Movie (title, year, studioName, president, presAddr)
    2. title, year -> studioName
    3. studioName -> president
    4. president -> presAddr

**Key**: {title, year}

***S1***:
title, year -> studioName

S1 is in BNCF

---

***S2***: studioName -> president

R1: studioName -> president

**key**: {studioName}

R2: studioName -> title, year, presAddr

FD:
  1. title, year -> studioName
  2. studioName-> presAddr

---

***S3***: president -> presAddr

---
Movie(title, year, studioName, president, presAddr)

- title, year -> studioName

- studioName -> president

- president -> presAddr

decomposed in:
1. S1(studioName, president)
2. S3(studioName, presAddr)
3. S4(studioName, title, year)

studioName=A; president=B; presAddr=C; title=D; year=E;

1. D, E -> A
2. A -> B
3. B -> C

| A | B | C | D | E |
| :--- | :--- | :--- | :--- | :--- |
| a | b | c<sub>1</sub> | d<sub>1</sub> | e<sub>1</sub> |
| a | b<sub>2</sub> | c | d<sub>2</sub> | e<sub>2</sub> |
| a | b<sub>3</sub> | c<sub>3</sub> | d | e |

Applying A->B:

| A | B | C | D | E |
| :--- | :--- | :--- | :--- | :--- |
| a | b | c<sub>1</sub> | d<sub>1</sub> | e<sub>1</sub> |
| a | b | c | d<sub>2</sub> | e<sub>2</sub> |
| a | b | c<sub>3</sub> | d | e |

Applying B->C:

| A | B | C | D | E |
| :--- | :--- | :--- | :--- | :--- |
| a | b | c | d<sub>1</sub> | e<sub>1</sub> |
| a | b | c | d<sub>2</sub> | e<sub>2</sub> |
| a | b | c | d | e |

---
## 3NF Decomposition
R(A, B, C, D, E); AB->C, C->B and A->D
1. Find a minimal basis for DFs
 - [x] Right sides with only 1 attribute
 - [ ] No redudant DFs?
    - {A, B}<sup>+</sup> = {A, B, D} --> It doesn't contain C thus the DF is essential
    - {C}<sup>+</sup> = {C} --> It doesn't contain B thus the DF is essential
    - {A}<sup>+</sup> = {A} --> It doesn't contain D thus the DF is essential


---
Movie (title, year, studioName, president, presAddr)

title, year -> studioName

studioName -> president

president -> presAddr
1. Find a minmal basis
- [x] Right side with only 1 attribute
- [x] No redudant DFs?
    - {title, year}<sup>+</sup> = {title, year} --> doesn't contain studioName
    - {studioName}<sup>+</sup> = {studioName} --> doesn't contain president
    - {president}<sup>+</sup> = {president} --> doesn't contain presAddr
- [X] No redudant attributes on left side?
    - Removing title from: title, year -> studioName  
        year -> studioName
        {year}<sup>+</sup> = {year} --> doesn't contain studioName => title is essential
    - Removing year from: title, year -> studioName  
        title -> studioName
        {title}<sup>+</sup> = {title} --> doesn't contain studioName => year is essential

2. For each FD create a relation
 - Movie1(title, year, studioName)  
 - Movie2(studioName, president)  
 - Movie3(president, presAddr)


3. If none of the relations of step 2 is a superkey for R, add
another relation for a key for R

 - ***Keys***: {title, year}

 - Movie1 contains a superkey of R.

---
## **SQL - Structured Query Language**

- Data Definition Language (DDL)
  - Define relational schemata
  - Create/alter/delete tables and their attributes
- Data Manipulation Language (DML)
  - Insert/delete/modify tuples in tables
  - Query one or more tables

### Data Types in SQL - Text
- `CHAR(n)`
  - stores fixed-length string of up to n characters
  - normally, shorter strings are padded by trailing blanks to makes n characters

- `VARCHAR(n)`
  - stores variable-length string of up to n characters

### Data Types in SQL - Numeric values

### Determination of Type affinities in SQLite
If the declared type contains:
1. `INT` : **INTEGER** affinity
2. `CHAR`, `CLOB`, `TEXT` : **TEXT** affinity
3. `BLOB` or no type specified: **BLOB** affinity
4. `REAL`, `FLOA`, `DOUB` : **REAL** affinity
5. Otherwise: **NUMERIC** affinity

Rules should be assessed by the above order.

#### TEXT affinity
Storage classes: NULL, TEXT or BLOB  
Numerical data is converted to text when inserted on a TEXT affinity column

#### NUMERIC affinity
All storage classes  
Text data is converted into INTEGER or REAL if conversion is lossless and converted to TEXT otherwise

#### INTEGER affinity
Similar to numeric affinity

#### REAL affinity
Similar to numeric affinity but INTEGER data is converted to float point representation

#### BLOB affinity
No attempt to coerce data from one storage class to another (data is stored as it is)

```
BLOBs are always stored as BLOBs no matter the column affinity
NULLs aren't affected by affinity as well
```

### SQLite

#### Table declarations
```sql
CREATE TABLE <table_name> {
    <column_name> <data_type>,
    ...,
    <column_name> <data_type>
};

CREATE TABLE Example {
    var1    INT,
    var2    CHAR(30),
    var3    VARCHAR(255),
    var4    CHAR(1),
    var5    DATE
}
```

#### Modifying Relation Schemas
##### To remove an entire table and all its tuples
```sql
DROP TABLE <table_name>;
```
##### To mofify the schema of an existing relation
```sql
ALTER TABLE <table_name> ADD <column_name> <data_type>;
ALTER TABLE <table_name> DROP <column_name;
```
#### Default Values
```sql
CREATE TABLE <table_name> {
    <column_name> <data_type> DEFAULT <default_value>,
    ...,
    <column_name> <data_type>
};
```
Default default value is `NULL`


### Constraints
Uses of constrains:
- Data-entry errors (inserts)
- Correctness criteria (updates)
- Enforce consistency
- Tell system about data -store, query processing

#### Classification of constraints
- Non-null constraints
- Key constraints
- Attribute-based and tuple-based constraints
- Referential integrity (foreign key) - if active prevents inserting data that doesn't exist on the table that is being pointed to
- General assertions
