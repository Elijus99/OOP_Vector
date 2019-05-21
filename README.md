# Vector (aka std::vector) konteinerio kūrimas

## Įdiegimas (Unix kompiuteryje) naudojant `Clang` kompiliatorių  ir paleidimas

- `git clone https://github.com/Elijus99/OOP_Vector.git`
- `cd OOP_Vector`
- `make`
- `make test`


### Member types

``` c++
typedef T value_type;
typedef size_t size_type;
typedef Allocator allocator_type;
typedef ptrdiff_t difference_type;
typedef T& reference;
typedef const T& const_reference;
typedef T* pointer;
typedef const T* const_pointer;
typedef T* iterator;
typedef const T* const_iterator;
typedef std::reverse_iterator<iterator> reverse_iterator;
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
```

### Member functions 

``` c++
Vector();
Vector(size_type count);
Vector(size_type count, const_reference value);
Vector(iterator first, iterator last);
Vector(std::initializer_list<T> list);
Vector(const Vector& other);
Vector(Vector&& other);
~Vector();
Vector& operator=(const Vector& other);
Vector& operator=(Vector&& other);
Vector& operator=(std::initializer_list<T> list);
void assign(size_type count, const T& value);
template <typename InputIt>
void assign(InputIt first, InputIt last);
void assign(std::initializer_list<T> ilist);
```

### Element access 

``` c++
reference at(size_type position);
const_reference at(size_type position) const;
reference operator[](size_type position);
const_reference operator[](size_type position) const;
reference front();
const_reference front() const;
reference back();
const_reference back() const;
T* data() noexcept;
const T* data() const noexcept;
```

### Iterators

``` c++
iterator begin() noexcept;
const_iterator begin() const noexcept;
const_iterator cbegin() const noexcept;
iterator end() noexcept;
const_iterator end() const noexcept;
const_iterator cend() const noexcept;
reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
reverse_iterator crbegin() const noexcept;
reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
reverse_iterator crend() const noexcept;
```

### Capacity

``` c++
bool empty() const;
size_type size() const;
size_type max_size() const noexcept;
void reserve(size_type new_capacity);
size_t capacity() const;
void shrink_to_fit();
```

### Modifiers

``` c++
void clear();
iterator insert(const_iterator pos, const T& value);
iterator insert(const_iterator pos, T&& value);
iterator insert(const_iterator pos, size_type count, const T& value);
template <typename InputIt>
iterator insert(iterator pos, InputIt first, InputIt last);
iterator insert(const_iterator pos, std::initializer_list<T> ilist);
template< class... Args >
iterator emplace(const_iterator pos, Args&& ... args);
template< class... Args >
void emplace_back(Args&& ... args);
iterator erase(iterator pos);
iterator erase(iterator first, iterator last);
void push_back(const T& value);
void push_back(T&& value);
void pop_back();
void resize(size_type count);
void resize(size_type count, const T& value);
void swap(Vector& other);
```

### Non-member functions

``` c++
bool operator== (const Vector<T>& other);
bool operator!= (const Vector<T> & other);
bool operator< (const Vector<T>& rhs);
bool operator> (const Vector<T>& rhs);
bool operator<= (const Vector<T>& rhs);
bool operator>= (const Vector<T>& rhs);
```

### Funkcijų pavyzdžiai

``` c++
void reserve(size_type new_capacity) {
        if (new_capacity > capacity_) {
            capacity_ = new_capacity;
            auto newElem = allocator.allocate(capacity_);
            std::move(elem, elem + size_, newElem);
            allocator.destroy(elem);
            elem = newElem;
        }
}
```

``` c++
void clear() {
        for (size_t i = 0; i < size_; i++) {
            allocator.destroy(elem + i);
        }
        size_ = 0;
}
```

``` c++
iterator insert(const_iterator pos, size_type count, const T& value) {
        auto index = pos - begin();
        iterator it = &elem[index];
        if (count == 0) return it;
        if (size_ + count > capacity_)
        {
            capacity_ = (size_ + count)*1.5;
            reserve(capacity_);
        }
        std::move(it, end(), it+count);
        size_ += count;
        for (size_t i = 0; i < count; i++) {
            *(it+i) = value;
        }
        return it;
}
```

``` c++
iterator erase(iterator pos) {
        auto* newElem = allocator.allocate(capacity_);
        size_t index = 0;
        for (auto i = begin(); i < pos; i++) {
            newElem[index] = *i;
            index++;
        }
        for (auto i = pos; i < end(); i++) {
            newElem[index] = *(i + 1);
            index++;
        }
        allocator.destroy(elem);
        elem = newElem;
        size_--;
        return pos;
}
```

``` c++
void push_back(const T& value) {
        if (size() == capacity()) {
            capacity_ = (capacity_ + 1) * 1.5;
            auto* newElem = allocator.allocate(capacity_);
            std::move(elem, elem + size_, newElem);
            allocator.destroy(elem);
            elem = newElem;
        }
        elem[size_++] = value;
}
```

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
