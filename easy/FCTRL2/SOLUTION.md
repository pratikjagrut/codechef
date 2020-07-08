# Factorial of Big numbers

This problem basically asks you to calculate the factorial of a `number up to 100`. The factorial of a number `N is 1*2*…*N`. This problem would be very simple, had it not been for the `maximum value of N`.

Now, the maximum number that we can store in an `unsigned 32 bit integer` is `2`<sup>`32`</sup> `– 1` and in an `unsigned 64 bit integer` is `2`<sup>`64`</sup> `– 1`.

Something like `100!` has over `150 decimal digits`. The data types mentioned earlier can store numbers having at most 9 and 19 decimal digits respectively. So, we need to find a way to store the 150+ digits that we will get as the answer.

The simplest data structure that we can use is an `integer array of size > 150`.

`a[200]` is how we declare the array.
We store number e.g 123 as

a[0] = 3

a[1] = 2

a[2] = 1

The least significant digit is stored in the lowest index 0. The next one in index 1 and so on.

## Multiplication using an array

So now we know how to store the number in array but now how to perform multiplication on each digit.

Example: `14 * 17 = 238`

Let's store 14 in an array and we'll use 17 to perform some calculation on each digit of 14.

`a[] = {4, 1}`

a[0] = 4

a[1] = 1

So now we start from index `0` to `1` (last index).
On each iteration we multiply `a[index]*17` and we also maintain `temp/carry` variable which is initialized with `0`.

Now at every iteration we calculate: 

```c++
int total = a[index] * 17 + carry;
a[index] = total % 10;
carry = total / 10;
```

**First iteration:**

```
int total = a[0] * 17 + carry;
total = 4 * 17 + 0
total = 68
```

```
a[0] = total % 10;
a[0] = 68 % 10
a[0] = 8
```

```
carry = total / 10;
carry = 68 / 10
carry = 6
```

**Second iteration:**

```
int total = a[1] * 17 + carry;
total = 1 * 17 + 6
total = 23
```

```
a[1] = total % 10;
a[1] = 23 % 10
a[1] = 3
```

```
carry = total / 10;
carry = 23 / 10
carry = 2
```

Now we've covered all the digits in from our initial array.

Value of array `a` after 2 iterations is `{8, 3}`, our `carry` is `2`.

So we need to iterate until `carry == 0`.

```
a[i] = carry % 10
carry = carry / 10
```

`carry == 2`

```
a[2] = 2 % 10
a[2] = 2
carry = 2 / 10
carry = 0
```

So now `carry == 0` and value of array `a` is `{8, 3, 2}`.

So now we print array `a` in reverse order we get `238` which is our final answer.

***This multiplication logic is implemented in finding big numbers factorial!***

## Pseudo Code

```
Take the input number of test cases

While test case > 0:

    Take input the number whose factorial is to be found, let it be N
    
    Initialize the array's 0th index to 1 and array_size to 1
    
    Iterate for(int i = 2; i <= n; i++), i = 0 because 0th index is initialized with 1. 
    This for loop will iterate over the number from 2 to N.

        Initialize carry = 0

        Iterate for(int j = 0; j <= array_size; j++), 
        this for loop iterate over index 0 to array_size
            
            int total = a[j] * i + carry
            a[j] = total % 10
            carry = total / 10

        While temp > 0:
            a[i] = carry % 10
            carry = carry / 10
            array_size++
    
    Print the array values in reverse order. 
```