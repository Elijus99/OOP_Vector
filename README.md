# Vector (aka std::vector) konteinerio kūrimas

## Įdiegimas (Unix kompiuteryje) naudojant `Clang` kompiliatorių  ir paleidimas

- `git clone https://github.com/Elijus99/OOP_Vector.git`
- `cd OOP_Vector`
- `make`
- `make test`


## Push_back spartos analizė
```
Inserted 10000 elements:
std::vector: 0.0001 s
Vector: 0.0001 s
Inserted 100000 elements:
std::vector: 0.0009 s
Vector: 0.0006 s
Inserted 1000000 elements:
std::vector: 0.0084 s
Vector: 0.0080 s
Inserted 10000000 elements:
std::vector: 0.1036 s
Vector: 0.0924 s
Inserted 100000000 elements:
std::vector: 1.2720 s
Vector: 0.9193 s
```
## Reallocations
```
Reallocations while inserting 10000 elements:
std::vector: 23
Vector: 20
Reallocations while inserting 100000 elements:
std::vector: 29
Vector: 26
Reallocations while inserting 1000000 elements:
std::vector: 34
Vector: 31
Reallocations while inserting 10000000 elements:
std::vector: 40
Vector: 37
Reallocations while inserting 100000000 elements:
std::vector: 46
Vector: 43
```
