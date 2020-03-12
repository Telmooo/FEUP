# ***Relational Model***
---
## Exercise 1
Relation **REFS**(T, A, I, C, S#, R, S, E, V, N, PI, PF, Y, M)

**D** = {  
    S → S#, R, E  
    S# → S  
    S, V, N → Y, M
    S, V, N, PI → T, PF  
    A → I, C  
    }

### a)
**X** = { S#, V, N, A }

{ S#, V, N, A }<sup>+</sup> = { S#, S, V, N, A, R, E, Y, I, C }  
X isn't a key as the closure doesn't contain all the attributes of the relation.

### b)
***3NF Decomposition***  
#### 1. Minimal Basis
##### Right side of every FD has 1 attribute
- S → S#
- S → R
- S → E
- S, V, N → Y
- S, V, N → M
- S, V, N, PI → T
- S, V, N, PI → PF
- A → I
- A → C

##### Eliminate Redundant DFs
For each FD obtained in the previous step, calculate the closure without considering the FD being tested
1. {S}<sup>+</sup> = {S, R, E} ⇒ S# ∉ {S}<sup>+</sup> → not redundant
2. {S}<sup>+</sup> = {S, S#, E} ⇒ R ∉ {S}<sup>+</sup> → not redundant
3. {S}<sup>+</sup> = {S, S#, R} ⇒ E ∉ {S}<sup>+</sup> → not redundant
4. {S, V, N}<sup>+</sup> = {S, V, N, M} ⇒ Y ∉ {S, V, N}<sup>+</sup> → not redundant
5. {S, V, N}<sup>+</sup> = {S, V, N, Y} ⇒ M ∉ {S, V, N}<sup>+</sup> → not redundant
6. { S, V, N, PI }<sup>+</sup> = {S, V, N, PI, PF} ⇒ T ∉ { S, V, N, PI }<sup>+</sup> → not redundant
7. { S, V, N, PI }<sup>+</sup> = {S, V, N, PI, T} ⇒ PF ∉ { S, V, N, PI }<sup>+</sup> → not redundant
8. {A}<sup>+</sup> = {A, C} ⇒ I ∉ {A}<sup>+</sup> → not redundant
9. {A}<sup>+</sup> = {A, I} ⇒ C ∉ {A}<sup>+</sup> → not redundant

##### Eliminate Redundant Left Sided Attributes
For each FD obtained in the previous step with more than one attribute on the left side calculate the closure without considering one of the attributes, if it still contains the right side of the DF then the attribute is redundant and can be eliminated
- S, V, N → Y
 - V, N → Y ⇒ {V, N}<sup>+</sup> = {V, N} ⇒ Y ∉ {V, N}<sup>+</sup> → S not redundant
 - V, N → Y ⇒ {V, N}<sup>+</sup> = {V, N} ⇒ Y ∉ {V, N}<sup>+</sup> → S not redundant
 - V, N → Y ⇒ {V, N}<sup>+</sup> = {V, N} ⇒ Y ∉ {V, N}<sup>+</sup> → S not redundant
