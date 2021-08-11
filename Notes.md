# Notes

Rough notes for topics that I wasn't too sure on, just for future reference.

## Types

- ```extern int x```    
Declares the existence of a global variable to the compiler, without initialising. After compilation, the linker will resolve all the references of x to the one definition defined in the source. This definition needs to be an 'external linkage', which means it needs to be defined outside of a function, and without a 'static' keyword.

- ```static int x```    
Declares the variable for the lifetime of the program.
For example, if the variable is defined in a function and then goes out of scope, the value isn't destroyed, but retained for future use. Useful in coroutines.
In a class a static variable is initilised just once, as they are allocated space in static storage by the complier. The static variables in a class are shared by all objects of that class. Therefore they cannot be initialized by the constructor.
Static objects remain for the lifetime of the program, the destructor is called after the main function is terminated.
*Might need to read more about this.

## Namespaces

### Definition and Creation

Name spaces narrow the scope of what would be global variables to the namespaces own scope. ie a container for variables outside classes and functions, protecting variables from being redefined elsewhere in the global scope.

```cpp
namespace namespace_name 
{
    int x, y; // code declarations where 
              // x and y are declared in 
              // namespace_name's scope
}
```

and

```cpp
int a = 10;

namespace N
{
    int a = 100;

    void f()
    {
         int a = 1000;
         std::cout << a << std::endl;      //prints 1000
         std::cout << N::a << std::endl;   //prints 100 
         std::cout << ::a << std::endl;    //prints 10
    }
}
```

- Namespace declarations can be nested within each other.
- Namespace declarations only appear at global scope.
- You can extend namespaces by declaring 2 or more code blocks of namespaces with the same name.

### Unnamed Namespaces

- Just have no name defining a namespace.
- Can't be accessed from outside of the file it's created in.
- Modern way to create static variables, they are superior but static is still useful as static cannot define user created types or classes as static, but unnamed namespaces can.

### Inline Namespaces

inline namespaces can be used when nesting namespaces to make the calling or use of the namespace more simply defined. For example;

``` cpp
namespace ns1
{
    inline namespace ns2
    {
        inline namespace ns3
        {
            int var = 10;
        }
    }
}
  
int main()
{
    cout << ns1::var;
    return 0;
}
```
This can also be done with the using directive, seems pointless though.
## Pointers

## Virtual Functions

## Coroutines

https://www.geeksforgeeks.org/coroutines-in-c-cpp/

## Vectors

### Iterators

## Basic Classes

### Access Specifiers

Access specifiers define how the members (methods and variables) can be accessed and modified from outside the class. There are 3 access specifiers;

- public - members can be accessed from outside of the class.
- private - members cannot be access from outside of the class.
- protected - members cannot be accessed from outside the class, except for inherited classes.

``` cpp
class MyClass {  // The class
    public:        // Access specifier
    // class members goes here
    private:       // Another access specifier 
};
```

## Further Classes

### Inheritance

### Polymorphism

### Overloading