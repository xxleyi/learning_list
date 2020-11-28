---
title: pages/react-basics
---

## Transformation
## Abstraction
## Composition
## State
### We tend to prefer our data model to be immutable. We thread functions through that can update state as a single atom at the top.
## Memoization
## Lists
## Continuations
### We can move some boilerplate out of our critical business logic by deferring execution of a function.
## State Map
### once we see repeated patterns we can use composition to avoid reimplementing the same pattern over and over again.
## Memoization Map
### Once we want to memoize multiple items in a list memoization becomes much harder. You have to figure out some complex caching algorithm that balances memory usage with frequency.
## Algebraic Effects
### It turns out that it is kind of a PITA to pass every little value you might need through several levels of abstractions. It is kind of nice to sometimes have a shortcut to pass things between two abstractions without involving the intermediates. In React we call this "context".
