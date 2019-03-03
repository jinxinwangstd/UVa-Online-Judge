## Problem description

A service returns value every period of time. Given a group of services with different period, determine the first K returning values' sender id.

## Algorithm analysis

Using a priority queue to store the group of services waiting for returning values, with the exact time of returning values. So every time we just extract the service with the smallest returning time and schedule its following service, that is the same service with returning time increased by the waiting period.
If the total number of services is N, the time complexity is O(KlogN).

## Knowledge base

1. priority queue maintains the "largest" element in the front in default. Thus if we want to extract the "smallest" element every time, we need to specify a different comparator type (class), not a comparator function.

   ```c++
   template <class T, class Container = vector<T>,
   	class Compare = less<typename Container::value_type> >
   	class priority_queue;
   ```

   And if we want to specify a different Compare class, we must specify each template parameter in order. We cannot leave out the second template parameter, or like Python use parameter name to specify the corresponding relationship. That is you must write like this:

   ```c++
   priority_queue<int, vector<int>, greater<int> > p;
   ```

2. How to define a Compare class:
   A Compare class is usually used as the template parameter in some C++ container like set, priority_queue.
   To define a Compare class, we must define one operator which is (), and it serves as a public compare function in this Compare class. Thus it returns a boolean value and takes two argument with same type. If this function returns true, then we consider the first argument is "smaller" than the second argument.

   ```c++
   class Compare {
       public:
       bool operator() (const int& a, const int& b) {
           return a > b;
       }
   };
   ```

3. Unlike in C language, the struct keyword define a new type in C++, and we don't need to write the struct keyword when we want to declare a new object of this new type.