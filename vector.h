#pragma once
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <algorithm>
#include <memory>

template <typename T, class Allocator = std::allocator<T>>
class Vector
{
private:
    size_t size_;
    size_t capacity_;
    T* elem;
    Allocator allocator;
public:
    //Member types
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
    //Member functions
    //Constructors
    Vector() : size_(0), capacity_(0), elem(new T[capacity_]) {};
    Vector(size_type count) : size_(count), capacity_(count) {
        elem = allocator.allocate(capacity_);
        std::fill_n(elem, count, 0.0);
    }
    Vector(size_type count, const_reference value) : size_(count), capacity_(count) {
        elem = allocator.allocate(capacity_);
        std::fill_n(elem, count, value);
    }
    Vector(iterator first, iterator last) {
        size_type count = last - first;
        capacity_ = count;
        elem = allocator.allocate(capacity_);
        for (size_t i = 0; i < count; i++) {
            elem[i] = *first;
            first++;
        }
        size_ = count;
    }
    Vector(std::initializer_list<T> list) {
        size_ = list.size();
        capacity_ = size_;
        elem = allocator.allocate(capacity_);
        std::copy(list.begin(), list.end(), elem);
    }
    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
        size_ = other.size();
        capacity_ = other.capacity();
        elem = allocator.allocate(capacity_);
        std::copy(other.begin(), other.end(), elem);
    }
    Vector(Vector&& other) : size_(other.size_), capacity_(other.capacity_) {
        elem = allocator.allocate(capacity_);
        std::move(other.begin(), other.end(), elem);
        other.clear();
    }
    //Deconstructor
    ~Vector() {
        allocator.destroy(elem);
        elem = nullptr;
    };
    //Operator=
    Vector& operator=(const Vector& other) {
        size_ = other.size();
        capacity_ = other.capacity();
        elem = allocator.allocate(capacity_);
        std::copy(other.begin(), other.end(), elem);
        return *this;
    };
    Vector& operator=(Vector&& other) {
        size_ = other.size();
        capacity_ = other.capacity();
        elem = allocator.allocate(capacity_);
        std::move(other.begin(), other.end(), elem);
        other.clear();
        return *this;
    };
    Vector& operator=(std::initializer_list<T> list) {
        size_ = list.size();
        capacity_ = list.capacity_;
        elem = allocator.allocate(capacity_);
        for (auto& i : list) {
            elem[size_] = i;
        }
    };
    //Assign
    void assign(size_type count, const T& value) {
        clear();
        capacity_ = count;
        elem = allocator.allocate(capacity_);
        for (size_t i = 0; i < count; i++) {
            elem[i] = value;
        }
    };
    template <typename InputIt>
    void assign(InputIt first, InputIt last) {
        clear();
        size_type count = last - first;
        capacity_ = count;
        size_ = count;
        elem = allocator.allocate(capacity_);
        for (size_t i = 0; i < count; i++) {
            elem[i] = *first;
            first++;
        }
    };
    void assign(std::initializer_list<T> ilist) {
        clear();
        capacity_ = ilist.size();
        size_ = capacity_;
        elem = allocator.allocate(capacity_);
        size_t j = 0;
        for (auto i = ilist.begin(); i < ilist.end(); i++) {
            elem[j] = *i;
            j++;
        }
    };
    //Element access
    reference at(size_type position) {
        if (position >= size_) throw std::out_of_range("Position is out of range");
        return elem[position];
    }
    const_reference at(size_type position) const {
        if (position >= size_) throw std::out_of_range("Position is out of range");
        return elem[position];
    }
    reference operator[](size_type position) {
        return elem[position];
    };
    const_reference operator[](size_type position) const {
        return elem[position];
    };
    reference front() { return elem[0]; }
    const_reference front() const { return elem[0]; }
    reference back() { return elem[size_ - 1]; }
    const_reference back() const { return elem[size_ - 1]; }
    T* data() noexcept {
        return elem;
    };
    const T* data() const noexcept {
        return elem;
    };
    //Iterators
    iterator begin() noexcept { return elem; }
    const_iterator begin() const noexcept { return elem; }
    const_iterator cbegin() const noexcept { return elem; }
    iterator end() noexcept { return elem + size_; }
    const_iterator end() const noexcept { return elem + size_; }
    const_iterator cend() const noexcept { return elem + size_; }
    reverse_iterator rbegin() noexcept { return reverse_iterator (elem + size_); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(elem + size_); }
    reverse_iterator crbegin() const noexcept { return reverse_iterator(elem + size_); }
    reverse_iterator rend() noexcept { return reverse_iterator(elem); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(elem); }
    reverse_iterator crend() const noexcept { return reverse_iterator(elem); }
    //Capacity
    bool empty() const { if (size_ == 0) { return true; } }
    size_type size() const { return size_; }
    size_type max_size() const noexcept { return SIZE_MAX; }
    void reserve(size_type new_capacity) {
        if (new_capacity > capacity_) {
            capacity_ = new_capacity;
            auto newElem = allocator.allocate(capacity_);
            std::move(elem, elem + size_, newElem);
            allocator.destroy(elem);
            elem = newElem;
        }
    };
    size_t capacity() const { return capacity_; }
    void shrink_to_fit() { capacity_ = size_; }
    //Modifiers
    void clear() {
        auto newElem = new T[0];
        delete[] elem;
        elem = newElem;
        size_ = 0;
    }
    iterator insert(const_iterator pos, const T& value) {
        insert(pos, 1, value);
    }
    iterator insert(const_iterator pos, T&& value) {
        auto index = pos - begin();
        if (size_ == capacity_) {
            capacity_ = (capacity_ + 1) * 1.5;
            reserve(capacity_);
        }
        iterator it = &elem[index];
        std::move(it, end(), it+1);
        *it = std::move(value);
        size_++;
        return it;
    };
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
    template <typename InputIt>
    iterator insert(iterator pos, InputIt first, InputIt last) {
        auto index = pos - begin();
        size_t count = last - first;
        iterator it = &elem[index];
        if (count == 0) return it;
        if (size_ + count > capacity_)
        {
            capacity_ = (size_ + count)*1.5;
            reserve(capacity_);
        }
        std::move(it, end(), it+count);
        for (size_t i = 0; i < count; i++) {
            *(it+i) = *first;
            first++;
        }
        size_ += count;
        return it;
    }
    iterator insert(const_iterator pos, std::initializer_list<T> ilist) {
        auto index = pos - begin();
        size_t count = ilist.size();
        iterator it = &elem[index];
        if (count == 0) return it;
        if (size_ + count > capacity_)
        {
            capacity_ = (size_ + count)*2;
            reserve(capacity_);
        }
        std::move(it, end(), it+count);
        for (size_t i = 0; i < count; i++)
        {
            *(it+i) = ilist[i];
        }
        size_ += count;
        return it;
    }
    template< class... Args >
    iterator emplace(const_iterator pos, Args&& ... args) {
        iterator it = &elem[pos - begin()];
        if (size_ == capacity_) {
            capacity_ = (capacity_ + 1) * 1.5;
            reserve(capacity_);
        }
        memmove(it + 1, it, (size_ - (pos - elem)) * sizeof(T));
        (*it) = std::move(T(std::forward<Args>(args) ...));
        size_++;
        return it;
    };
    template< class... Args >
    void emplace_back(Args&& ... args) {
        if (size_ == capacity_) {
            capacity_ = (capacity_ + 1) * 1.5;
        }
        elem[size_] = std::move(T(std::forward<Args>(args) ...));
        size_++;
    }
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
    };
    iterator erase(iterator first, iterator last) {
        auto* newElem = allocator.allocate(capacity_);
        auto diff = last - first;
        size_t index = 0;
        for (auto i = begin(); i < first; i++) {
            newElem[index] = *i;
            index++;
        }
        for (auto i = last; i < end(); i++) {
            newElem[index] = *i;
            index++;
        }
        allocator.destroy(elem);
        elem = newElem;
        size_ -= diff;
        return first;
    };
    void push_back(const T& value) {
        if (size() == capacity()) {
            capacity_ = (capacity_ + 1) * 1.5;
            auto* newElem = allocator.allocate(capacity_);
            std::move(elem, elem + size_, newElem);
            allocator.destroy(elem);
            elem = newElem;
        }
        elem[size_++] = value;
    };
    void push_back(T&& value) {
        if (size() == capacity()) {
            capacity_ = (capacity_ + 1) * 1.5;
            auto* newElem = allocator.allocate(capacity_);
            std::move(elem, elem + size_, newElem);
            allocator.destroy(elem);
            elem = newElem;
        }
        elem[size_++] = std::move(value);
    };
    void pop_back() {
        size_--;
        auto* newElem = allocator.allocate(capacity_);
        for (size_t i = 0; i < size_; i++) {
            newElem[i] = elem[i];
        }
        allocator.destroy(elem);
        elem = newElem;
    };
    void resize(size_type count) {
        if (capacity_ < count) {
            capacity_ = count;
        }
        auto* newElem = allocator.allocate(capacity_);
        for (size_t i = 0; i < size_; i++) {
            newElem[i] = elem[i];
        }
        for (size_t i = size_; i < count; i++) {
            newElem[i] = 0;
        }
        size_ = count;
        allocator.destroy(elem);
        elem = newElem;
    };
    void resize(size_type count, const T& value) {
        if (capacity_ < size_ + count) {
            capacity_ = count;
        }
        auto* newElem = allocator.allocate(capacity_);
        for (size_t i = 0; i < size_; i++) {
            newElem[i] = elem[i];
        }
        for (size_t i = size_; i < count; i++) {
            newElem[i] = value;
        }
        size_ = count;
        allocator.destroy(elem);
        elem = newElem;
    };
    void swap(Vector& other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(elem, other.elem);
        std::swap(allocator, other.allocator);
    };
    //Non-member functions
    bool operator== (const Vector<T>& other) {
        if (size_ == other.size()) {
            for (size_t i = 0; i < size_; i++) {
                if (elem[i] != other.elem[i]) return false;
            }
            return true;
        }
        return false;
    }
    bool operator!= (const Vector<T> & other) {
        return !operator==(other);
    }
    bool operator< (const Vector<T>& rhs) {
        if (*this == rhs) {
            return false;
        }
        return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend()) == 1 ? 1 : 0;
    }
    bool operator> (const Vector<T>& rhs) {
        if (*this == rhs) {
            return false;
        }
        return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend()) == 1 ? 0 : 1;
    }
    bool operator<= (const Vector<T>& rhs) {
        if (*this == rhs) {
            return true;
        }
        return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend()) == 1 ? 1 : 0;
    }
    bool operator>= (const Vector<T>& rhs) {
        if (*this == rhs) {
            return true;
        }
        return std::lexicographical_compare(this->cbegin(), this->cend(), rhs.cbegin(), rhs.cend()) == 1 ? 0 : 1;
    }
};

#endif
