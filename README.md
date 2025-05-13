# CLI Calculator Project

**Parser and solver** for mathematical expressions supporting **5 operators**
(+, -, *, /, ^) for **intager** addition, substraction, multiplication, 
division and exponentiation, as well as **parentheses** ('(', ')')!

It converts expressions to machine-friendly 
[**postfix notation**](https://en.wikipedia.org/wiki/Reverse_Polish_notation) 
and finds the result using Dijkstra's shunting yard algorithm.

Example usage:
```
Type in a mathematical expression:
15 + 17 * (2+3) 
```
Output:
```
Starting tokens:
15 + 17 * ( 2 + 3 )
Postfix conversion:
15 17 2 3 + * +
Final result:
= 100
```