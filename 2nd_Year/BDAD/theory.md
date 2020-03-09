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

---

***S2***: studioName -> president

R1: studioName -> president

**key**: {studioName}

R2: studioName -> title, year, presAddr

FD:
  1. title, year -> studioName
  2. studioName-> presAddr




***S3***: president -> presAddr
