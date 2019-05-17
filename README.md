# Vector (aka std::vector) konteinerio kūrimas

## Push_back spartos analizė
```
Inserted 10000 elements:
std::vector: 0.0001 s
Vector: 0.0000 s
Inserted 100000 elements:
std::vector: 0.0006 s
Vector: 0.0003 s
Inserted 1000000 elements:
std::vector: 0.0097 s
Vector: 0.0071 s
Inserted 10000000 elements:
std::vector: 0.1096 s
Vector: 0.0860 s
Inserted 100000000 elements:
std::vector: 1.1527 s
Vector: 0.6999 s
```
## Reallocations
```
Reallocations while inserting 10000 elements:
std::vector: 23
Vector: 12
Reallocations while inserting 100000 elements:
std::vector: 29
Vector: 15
Reallocations while inserting 1000000 elements:
std::vector: 34
Vector: 18
Reallocations while inserting 10000000 elements:
std::vector: 40
Vector: 22
Reallocations while inserting 100000000 elements:
std::vector: 46
Vector: 25
```
