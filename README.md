# Push swap
### Goal of the project (Mandatory part)
* Writte a sorting algorithm, as efficient as possible, to sort two stacks:
  * stack a containing positive and negative integers (up to some thousands of them)
  * stack b empty


# Bonus part
Create a checker to verify that our program sorts the two stacks correctly

# Getting started
### Installation
* Clone the repo
```
git clone git@github.com:RRebois/push_swap.git
```

### Compilation
* Sorting algorth program
```
make
```
* Checker
```
make bonus
```

### Usage
* Sorting algorth program

```
./push_swap 2 1 3 6 5 8
```
* Checker
```
./checker 2 1 3 6 5 8
ARG=" 4 67 3 87 23"; ./push_swap $ARG | ./checker
```
