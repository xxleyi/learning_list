---
title: pages/react-basics
---

## Transformation
### The core premise for React is that UIs are simply a projection of data into a different form of data. The same input gives the same output. **A simple pure function.**
## Abstraction
### You can't fit a complex UI in a single function though. It is important that UIs can be abstracted into reusable pieces that don't leak their implementation details. Such as calling one function from another.
## Composition
### To achieve truly reusable features, it is **not enough to simply reuse leaves** and build new containers for them. You also need to be able to build abstractions from the containers that compose other abstractions.
## State
### **We tend to prefer our data model to be immutable.** We thread functions through that can update state as a single atom at the top.
## Memoization
### Calling the same function over and over again is **wasteful if we know that the function is pure.**
## Lists
### Most UIs are some form of lists that then produce multiple different values for each item in the list. This creates a natural hierarchy.
### To manage the state for each item in a list we can create **a Map that holds the state** for a particular item.
## Continuations
### We can move some boilerplate out of our critical business logic by **deferring execution of a function**.
### fiber is a special system which can create and interpret continuations
## State Map
### once we see repeated patterns we can **use composition to avoid reimplementing the same pattern** over and over again.
## Memoization Map
### Once we want to memoize multiple items in a list memoization becomes much harder. You have to figure out some complex caching algorithm that balances memory usage with frequency.
## Algebraic Effects
### It turns out that it is kind of a PITA to pass every little value you might need through several levels of abstractions. It is kind of nice to sometimes have a shortcut to **pass things between two abstractions without involving the intermediates**. In React we call this "context".
