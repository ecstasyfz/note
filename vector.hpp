# 数组

```c++
template <class T>
class Vector {
public:
    T() : p_{nullptr} {}
    T(int size = 0)
        : p_{new T{size}}, size_{size}, capacity_{size} {}
    
    void push_back(T new_val) {
        if (capacity_ == size_) {
            
        }
        size_++;
    }
    
    T &operator[](int pos) {
        return p_[pos];
    }
    
private:
    T *p_;
    int size_;
    int capacity_;
};
```



