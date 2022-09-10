+++++++                 Set Cell #0 to 7
[
    >++++               Add 4 to Cell #1; this will always set Cell #1 to 4
    [
        >+++            Add 3 to Cell #2
        >+++            Add 3 to Cell #3
        >+++            Add 3 to Cell #4
        >+++            Add 3 to Cell #5
        <<<<-         Decrement the loop counter in Cell #1
    ]
    >>++                Add 2 to cell #3
    >+++                Add 3 to cell #4
    >++++               Add 4 to cell #5
    >+                  Add 1 to cell #6
    [<]
    <-
]

The result of this is:
Cell no :   0   1   2   3   4   5   5    5    6
Contents:   0   0   83  99  104 111 111 108   8
ASCII   :   0   0   S   c   h   o   o   l   \n
Pointer :   ^

>>-.                    Minus 1 from Cell 2 and print
>+.                     Adds 1 to Cell 3 and prints
>-.                     Minus 1 Adds 1 to Cell 4 and prints
>-..                    Cell 5 and prints "oo" from Cell 5
---.                    prints "l" from Cell 5
>+++.                   Cell 6 and prints
