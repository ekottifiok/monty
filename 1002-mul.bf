++++ ++++               Cell c0 = 8
>,                      Reads input and stores in c1
>,                    Reads input and stores in c2
<<                     Moves to c0
[
    >--- ---          Minus 6 from c1
    >--- ---          Minus 6 from c2
    <<-                  Minus 1 from c0
]

>                      Moves to c1
[   
    >                   Moves to c2
    [
        >+              Increment c3 by 1
        >+              Increment c4 by 1
        <<-             decrement c2 by 1
    ]
    >                   move to c3
    [
        <+              add 1 to c2
        >-              decrement c3
    ]
    <<-                  decrement c1 by 1
]

<++++ ++++              Cell c0 = 8
[
    >>>>+++ +++        increment c4 by 6
    <<<<-              decrement c0 by 1
]
>>>>.                  Print c4