# Chapter 5 - Bit Manipulation

## Logical Operations
- XOR: `^`
- NOT: `~`
- AND: `&`
- OR: `|`


## Definitions and Rules:

### XOR
```
x ^ 0 = x
x ^ 1 = ~x
x ^ x = 0
```

### AND
```
x & 0 = 0
x & 1 = x
x & x = x
```

### OR
```
x | 0 = x
x | 1 = 1
x | x = x
```

## Two's Complement
1. Flip the bits
2. Add 1
3. prepend the sign bit

```
-K = concat(1, 2^(N-1) - K) where N = # of bits in K
```

## Signed bits
- The MSB (most significant bit) denotes whether or not the number is positive or negative.
- `1` represents a negative number
- `0` represents a positive number

## Right Bit Shifting

### Arithmetic Right Shift
- Divides a number by 2
- Remove the LSB (least significant bit) and prepend the sign bit (we keep the sign bit)
- Denoted by `>>`
- Example 1: `1101 >> 1 ==> 0110`
- Example 2: `1101 >> 2 ==> 0110 ==> 0011`

### Logical Right Shift
- Remove the LSB (least significant bit) and prepend a 0 in the sign bit
- Denoted by `>>>`
- Example 1: `10110101 >>> 1 ==> 01011010` Notice how `-75` becomes `90`

## Left Bit Shifting
- Both arithmetic and Logical
- denoted by `<<`
- Remove the MSB and append a 0 in the LSB spot
