++++ ++++
>,                      Reads input and stores in c1
>,                      Reads input and stores in c2
<<                      Moves to c0

convert from ascii
[
    >--- ---            Minus 6 from c1
    >--- ---            Minus 6 from c2
    <<-                 Minus 1 from c0
]

multiply
>
[
    >
    [
        >+
        >+
        <<-
    ]
    >
    [
        <+
        >-
    ]
    <<-                 Decrement c1       
]

separate numbers
>[-]
>+
>
>+++++ +++++<
[
 - >- [>>>]+++++ +++++<<+
 [<<<]>>>>
]
<-
<+++++ +++++>>>[-<<<->>>]<<<

convert to ascii
<++++ ++++
[
    >+++ +++
    >
    [
        +++ +++
        >
    ]
    <[<]
    >-
]

print
>>
[
    .
    <<
]
<
[
    <<
]
>>.
>>>++ ++++ ++++.