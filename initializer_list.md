# 初始化列表


```c++
int a;		//未被初始化
int b{};	//相当于int b = 0;
int *c;		//未被初始化
int *d{};	//相当于int *d = nullptr
```

初始化的写法

```c++
int a{1};
int b = {2};
int c = 3;

std::vector<int>vec1{1, 2, 3};
std::vector<int>vec2 = {1, 2, 3};
```

STL中的一些使用

```c++
std::vector<int> vec = {1, 2, 3};
std::map <int,double> mp = {{1, 1.5}, {3, 3.5}};  
std::list<std::string> list_str = { "hello", "world", "china" };  
```

指针

```c++
int *p = new int{1};
auto p = new std::vector<int>{1, 2, 3};
```

零参数

```c++
std::vector<int> vec1;
std::vector<int> vec2{};
std::vector<int> vec3();
```

歧义

```c++
std::vector<int> vec1(10);
std::vector<int> vec2{10};
```

其他用法

```c++
std::vector<int> func() {
    return {1, 2, 3};
}
```

```c++
std::vector<std::vector<int>> matrix;
matrix.push_back({1, 2, 3});
```

C数组的初始化

```c++
int arr[] = {1, 2, 3};
char str[] = {'a', 'b', 'c'};

//比较极端的用法
std::vector<int> matrix[] = {{1,2}, {2,3}};
```

```c++
struct A {
    int x;
    int y;
};

struct B {
    int x;
    int y;
    B(int a, int b)
        : x{a * 2}, y{b * 2} {}
};

struct C {
    int x;
    int y;
    C(int a, int b) {
        this->x = a * 3;
        this->y = b * 3;
    }
};

A a = {1, 2};
B b = {1, 2};
C c = {1, 2};
```

那么如何区分一个类(class struct union)是否可以使用列表初始化来完成初始化工作呢？关键问题看这个类是否是一个聚合体（aggregate)，首先看下C++中关于类是否是一个聚合体的定义：

1. 无用户自定义构造函数。
2. 无私有或者受保护的非静态数据成员
3. 无基类
4. 无虚函数
5. 无{}和=直接初始化的非静态数据成员

```c++
class Object {
public:
    Object(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); it++) {
            std::cout << i << std::endl;
        }
        
        // for (auto &i : list)
        //     std::cout << i << std::endl;
        
    }
};
Object obj = {7, 8, 9};
```

```shell
>> 7 8 9
```

1、它是一个轻量级的容器类型，内部定义了迭代器iterator等容器必须的一些概念。

2、对于initialzer-list<T>来说，它可以接受任意长度的初始化列表，但是元素必须是要相同的或者可以转换为T类型的。

3、它只有三个成员接口，begin(),end(),size(),其中size()返回initialzer-list的长度。

4、它只能被整体的初始化和赋值，遍历只能通过begin和end迭代器来，遍历取得的数据是可读的，是不能对单个进行修改的。

```c++ {
int x1 = 2.4;		// a = 2
int x2 = {2.4}		// error
char c1 = 1000		// ???
char c2 = {1000}	// error
std::vector<int> vec1{1,2,3.5} //error

const int x = 1; 	// 注意x是const int
char c3 = x 		// pass
char c4 = {x}		// error
```

```c++
class Object {
public:
    explicit Object(int a) {}
};

Object obj(1.5) // error
```

